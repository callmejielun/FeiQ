#include"UdpMediator.h"
#include"UdpNet.h"


//���캯��
UdpMediator::UdpMediator() {
	//new�������
	m_pNet = new UdpNet(this);
}

//��������
UdpMediator::~UdpMediator() {

}

//������
bool UdpMediator::OpenNet() {
	return true;
}

//�ر�����
void UdpMediator::CloseNet() {

}

//�������ݣ����ַ����������շ���
//����tcp��udp
bool UdpMediator::SendData(long lSendIP, char* buf, int nLen) {
	return true;
}

//��������
void UdpMediator::DealData(long lSendIP, char* buf, int nLen) {

}
