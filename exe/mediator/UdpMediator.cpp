#include"UdpMediator.h"
#include"UdpNet.h"


//构造函数
UdpMediator::UdpMediator() {
	//new网络对象
	m_pNet = new UdpNet(this);
}

//析构函数
UdpMediator::~UdpMediator() {

}

//打开网络
bool UdpMediator::OpenNet() {
	return true;
}

//关闭网络
void UdpMediator::CloseNet() {

}

//发送数据，用字符数组来接收发送
//兼容tcp和udp
bool UdpMediator::SendData(long lSendIP, char* buf, int nLen) {
	return true;
}

//处理数据
void UdpMediator::DealData(long lSendIP, char* buf, int nLen) {

}
