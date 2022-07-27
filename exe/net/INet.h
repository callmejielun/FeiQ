#pragma once
//ͨ��ֻ����һ�������ֹͷ�ļ��ظ�����
#include<iostream>
#include<WinSock2.h>
#include<ws2tcpip.h>
#include<process.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
//���ð���ͷ�ļ���ֱ�ӷ�һ���������
class INetMediator;
class INet {
public:
	//���캯��
	INet() {}

	//������������ʹ��ʱ������ָ��ָ�����������Ҫʹ��������
	virtual ~INet() {}

	//��ʼ������
	virtual bool InitNet() = 0;

	//�ر�����
	virtual void UninitNet() = 0;

	//�������ݣ����ַ����������շ���
	//ͬʱ����tcp��udp
	virtual bool SendData(long lSendIP, char* buf,int nLen) = 0;

protected:
	//��������
	virtual void RecvData() = 0;

	//�н��߽ӿ�ָ�룬���ڽ��������������ഫ��
	INetMediator* m_pMediator;
};