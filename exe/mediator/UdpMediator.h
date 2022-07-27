#pragma once
#include"INetMediator.h"

class UdpMediator : public INetMediator {
public:
	//构造函数
	UdpMediator();

	//析构函数
	~UdpMediator();

	//打开网络
	bool OpenNet();

	//关闭网络
	void CloseNet();

	//发送数据，用字符数组来接收发送
	//兼容tcp和udp
	bool SendData(long lSendIP, char* buf, int nLen);

	//处理数据
	void DealData(long lSendIP, char* buf, int nLen);
};