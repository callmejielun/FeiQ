#include"UdpNet.h"
#include"INetMediator.h"
#include"PackDef.h"

//子类构造函数
UdpNet::UdpNet(INetMediator* pMediator) : m_sock(INVALID_SOCKET), m_handle(0) {
	m_pMediator = pMediator;
}

//子类析构函数
UdpNet::~UdpNet() {
	UninitNet();
}
//初始化网络
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

    //5接收数据——阻塞函数，创建线程
    m_handle = _beginthreadex(0, 0, &RecvThread, this, 0, 0);

    //last
    return true;
}

//线程函数
unsigned int __stdcall UdpNet::RecvThread(void* lpVoid) {
    UdpNet* pThis = (UdpNet*)lpVoid;
    pThis->RecvData();
    return 0;
}

//关闭网络
void UdpNet::UninitNet() {
    //


    //
    if (m_sock && m_sock != INVALID_SOCKET) {
        closesocket(m_sock);
    }
    //
    WSACleanup();
}

//发送数据
bool UdpNet::SendData(long lSendIP, char* buf, int nLen) {
	return true;
}

//接收数据
void UdpNet::RecvData() {
	
}
