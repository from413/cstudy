// exam2_udp_recv.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <stdlib.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

//데이터 받기 예제 

int main()
{
	
	SOCKET hSocket;

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf_s("WSAStartup() error code : %d\n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	hSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (hSocket == INVALID_SOCKET) {
		printf_s("error socket : %d\n", WSAGetLastError());
	}

	int recv_len;

	sockaddr_in si_listener;
	memset(&si_listener, 0, sizeof(sockaddr_in));
	si_listener.sin_family = AF_INET;
	si_listener.sin_port = htons(3333);
	si_listener.sin_addr.S_un.S_addr = INADDR_ANY;

	if (
		bind(hSocket, (sockaddr*)& si_listener, sizeof(sockaddr_in)) == SOCKET_ERROR
		)
	{
		printf_s("error socket bind : %d\n", WSAGetLastError());
	}

	puts("bind success");

	while (1)
	{
		sockaddr_in si_other;
		memset(&si_other, 0, sizeof(sockaddr_in));

		int slen;
		slen = sizeof(si_other);

		puts("wait data...");
		fflush(stdout);
		char szBuf[1024];
		memset(szBuf, 0, sizeof(szBuf));
		recv_len = recvfrom(hSocket, szBuf, sizeof(szBuf), 0, (sockaddr*)& si_other, &slen);

		char _szIp[256];

		//주소 출력 
		inet_ntop(AF_INET, &si_other.sin_addr, _szIp, sizeof(_szIp));
		printf_s("from :%s \n", _szIp);
		printf_s("data : %s \n", szBuf);

	}

	closesocket(hSocket);
	WSACleanup();

	return 0;
}
