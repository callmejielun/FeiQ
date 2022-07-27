#pragma once
//通过只编译一次命令，防止头文件重复包含
#include<iostream>
#include<WinSock2.h>
#include<ws2tcpip.h>
#include<process.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
//不用包含头文件，直接放一个类的声明
class INetMediator;
class INet {
public:
	//构造函数
	INet() {}

	//虚析构函数，使用时，父类指针指向子类对象，需要使用虚析构
	virtual ~INet() {}

	//初始化网络
	virtual bool InitNet() = 0;

	//关闭网络
	virtual void UninitNet() = 0;

	//发送数据，用字符数组来接收发送
	//同时兼容tcp和udp
	virtual bool SendData(long lSendIP, char* buf,int nLen) = 0;

protected:
	//接收数据
	virtual void RecvData() = 0;

	//中介者接口指针，用于将网络数据向外类传输
	INetMediator* m_pMediator;
};