#pragma once
class INet;
class INetMediator {
public:
	//构造函数
	INetMediator() {}

	//析构函数
	virtual ~INetMediator() {}

	//打开网络
	virtual bool OpenNet() = 0;

	//关闭网络
	virtual void CloseNet() = 0;

	//发送数据，用字符数组来接收发送
	//兼容tcp和udp
	virtual bool SendData(long lSendIP, char* buf, int nLen) = 0;

	//处理数据
	virtual void DealData(long lSendIP, char* buf, int nLen) = 0;
	
protected:
	//网络接口指针，用于调用网络函数
	INet* m_pNet;
};