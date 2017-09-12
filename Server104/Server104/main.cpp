#include <iostream>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/socket.h>
#include <unistd.h>
#include "termios.h"
#include "data_cache.h"
#include "tcpsocket.h"
#include "serialport.h"
#include "dlt634_5104slave_app.h"
#include "dlt634_5104slave_disk.h"
#include "dlt634_5101master_app.h"
#include "dlt634_5101master_disk.h"

using namespace std;

Queue circularQueue;//用于存储主站报文
Queue *ptrQ = &circularQueue;

/* -----------------------------------------------------------------------------
** 函数名称: thread_main_104slave
** 功能描述: 104线程入口
** 输　  入: 无
** 输　  出: 无
** 全局变量: circularQueue，写入主站的报文至循环队列中
** 调用模块: DLT634_5104_SlaveInit()、TCPSocket类
** 作　  者: Mrs.Ly
** 日　  期: 2017.09.12
** -----------------------------------------------------------------------------
** 修 改 人:
** 修改内容:
** 日　  期:
** ---------------------------------------------------------------------------*/
void* thread_main_104slave(void*)
{
    unsigned char buff[255];
    circularQueue.front = circularQueue.rear = 0;

    DLT634_5104_SlaveInit();//１０４从站初始化与定时启动

    DatabaseInit();//数据缓存区初始化
    unsigned char pbuf = 'a';
    uint8_t *pBuf = &pbuf;
    DBWrite_YX(pBuf);
    DBWrite_YC(pBuf);
    DBWrite_SOE(pBuf);
    DBWrite_NVA(pBuf);

    TCPSocket tcpConnect;//网络套接字建立连接
    tcpConnect.setReuseAddr(true);
    tcpConnect.bind("INADDR_ANY",2404);
    tcpConnect.listen();
    TCPSocket *client = tcpConnect.accept();
    std::cout << "stop here" << std::endl;

    setClientFd(client->fd());
    if(client == NULL)
    {
        printf("client falied connect");
    }
    else
    {
        printf("client success connect fd = %d \n",client->fd());
        while(1)
        {
            int n = client->read(buff,255);
            if(n < 0)
            {
                printf("read error client return number  = %d,errno = %d\n",(int)n,errno);
                pthread_exit(NULL); //return -1;
            }
            if(n == 0)
            {
                printf("connection closed by client");
                pthread_exit(NULL);//return -1;
            }
            else
            {
                printf("\n");
                printf("%d \n",(int)n);
                for(int i= 0;i < n;i++)
                {
                    //printf("%02X ",buff[i]);
                    AddQ(ptrQ,buff[i]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}


int main()
{
    pthread_t ntid_104slave;
    if (pthread_create(&ntid_104slave,NULL,thread_main_104slave,NULL))
    {
        std::cout << "fail to create pthread" <<std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << "thread id=" << (unsigned int)ntid_104slave << std::endl;
    }

    while(1)
    {
        sleep(30000);
    }

//DLT634_5101_MasterTask();//101主站初始化与定时运行
//    SerialPort serialPort;//建立串口链接
//    serialPort.openPort("/dev/ttyS2");
//    serialPort.SetSerialAttribs(DB115200,1);
//    serialPort.SetBlocking(0);
//    serialPort.readPort();


    return 0;
}

