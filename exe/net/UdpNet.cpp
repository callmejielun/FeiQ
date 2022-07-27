#include"UdpNet.h"
#include"INetMediator.h"
#include"PackDef.h"

//���๹�캯��
UdpNet::UdpNet(INetMediator* pMediator) : m_sock(INVALID_SOCKET), m_handle(0) {
	m_pMediator = pMediator;
}

//������������
UdpNet::~UdpNet() {
	UninitNet();
}
//��ʼ������
bool UdpNet::InitNet() {
    //1
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        cout << "WSAStartup failed with error: " << err << endl;
        return false;
    }
    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        cout << "Could not find a usable version of Winsock.dll" << endl;
        UninitNet();
        return false;
    }

    //2
    m_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (m_sock == INVALID_SOCKET) {
        cout << "socket function failed with error = " << WSAGetLastError() << endl;
        UninitNet();
        return false;
    }

    //3
    BOOL bval = TRUE;
    setsockopt(m_sock, SOL_SOCKET, SO_BROADCAST, (char*)&bval, sizeof(bval));
	
    //4
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.S_un.S_addr = INADDR_ANY;
    service.sin_port = htons(_DEF_UDP_PORT);
    err = bind(m_sock, (SOCKADDR*)&service, sizeof(service));
    if (err == SOCKET_ERROR) {
        cout << "bind failed with error" << WSAGetLastError() << endl;
        UninitNet();
        return false;
    }

    //5�������ݡ������������������߳�
    m_handle = _beginthreadex(0, 0, &RecvThread, this, 0, 0);

    //last
    return true;
}

//�̺߳���
unsigned int __stdcall UdpNet::RecvThread(void* lpVoid) {
    UdpNet* pThis = (UdpNet*)lpVoid;
    pThis->RecvData();
    return 0;
}

//�ر�����
void UdpNet::UninitNet() {
    //


    //
    if (m_sock && m_sock != INVALID_SOCKET) {
        closesocket(m_sock);
    }
    //
    WSACleanup();
}

//��������
bool UdpNet::SendData(long lSendIP, char* buf, int nLen) {
	return true;
}

//��������
void UdpNet::RecvData() {
	
}
