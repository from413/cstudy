// exam1_udp_send.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


#include <stdlib.h>
#include <WinSock2.h>
#include <Ws2tcpip.h>

#pragma comment(lib,"ws2_32.lib")

int main()
{
	sockaddr_in si_other;
	SOCKET hSocket;

	
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf_s("WSAStartup() error code : %d\n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	hSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (hSocket == SOCKET_ERROR) {
		printf_s("socket() error code : %d\n", WSAGetLastError());
		return EXIT_FAILURE;
	}

	while (1)
	{	
		memset((char*)& si_other, 0, sizeof(si_other));
		//InetPton(AF_INET, L"192.168.0.15", &si_other.sin_addr.s_addr);
		InetPton(AF_INET, L"127.0.0.1", &si_other.sin_addr.s_addr);
		si_other.sin_family = AF_INET;
		si_other.sin_port = htons(3333);

		puts("보낼 메씨지를 입력하세요.");
		char szBuf[512];
		gets_s(szBuf,sizeof(szBuf));
		if (!strcmp(szBuf, "exit")) break;
		sendto(hSocket, szBuf, strlen(szBuf), 0, (sockaddr*)& si_other, sizeof(si_other));
	}

	closesocket(hSocket);
	WSACleanup();
}
