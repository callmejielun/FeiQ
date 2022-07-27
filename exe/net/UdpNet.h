#pragma once
#include"INet.h"

class UdpNet : public INet{
public:
	//���캯��
	UdpNet(INetMediator* pMediator);

	//������������ʹ��ʱ������ָ��ָ�����������Ҫʹ��������
	~UdpNet();

	//��ʼ������
	bool InitNet();

	//�ر�����
	void UninitNet();

	//��������
	//����tcp��udp
	bool SendData(long lSendIP, char* buf, int nLen);

protected:
	//��������
	void RecvData();
};