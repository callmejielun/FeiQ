#pragma once
class INet;
class INetMediator {
public:
	//���캯��
	INetMediator() {}

	//��������
	virtual ~INetMediator() {}

	//������
	virtual bool OpenNet() = 0;

	//�ر�����
	virtual void CloseNet() = 0;

	//�������ݣ����ַ����������շ���
	//����tcp��udp
	virtual bool SendData(long lSendIP, char* buf, int nLen) = 0;

	//��������
	virtual void DealData(long lSendIP, char* buf, int nLen) = 0;
	
protected:
	//����ӿ�ָ�룬���ڵ������纯��
	INet* m_pNet;
};