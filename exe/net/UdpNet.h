#pragma once
#include"INet.h"

class UdpNet : public INet{
public:
	//构造函数
	UdpNet(INetMediator* pMediator);

	//虚析构函数，使用时，父类指针指向子类对象，需要使用虚析构
	~UdpNet();

	//初始化网络
	bool InitNet();

	//关闭网络
	void UninitNet();

	//发送数据
	//兼容tcp和udp
	bool SendData(long lSendIP, char* buf, int nLen);

protected:
	//接收数据
	void RecvData();
};