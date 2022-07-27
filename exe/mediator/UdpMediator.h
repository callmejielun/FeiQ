#pragma once
#include"INetMediator.h"

class UdpMediator : public INetMediator {
public:
	//���캯��
	UdpMediator();

	//��������
	~UdpMediator();

	//������
	bool OpenNet();

	//�ر�����
	void CloseNet();

	//�������ݣ����ַ����������շ���
	//����tcp��udp
	bool SendData(long lSendIP, char* buf, int nLen);

	//��������
	void DealData(long lSendIP, char* buf, int nLen);
};