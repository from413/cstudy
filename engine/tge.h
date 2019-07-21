#pragma once
//#define SCREEN_BUF_SIZE 2000
//#define SCREEN_WIDTH 80
//#define MAX_TOKEN_SIZE 64
#include <stdio.h>
#include <tchar.h>
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#include "../engine/irrlicht/include/irrlicht.h"

namespace TGE {

	const int SCREEN_BUF_SIZE = 2000;
	const int SCREEN_WIDTH = 80;
	const int MAX_TOKEN_SIZE = 64;
	const int Version = 100;

	void hideCursor(HANDLE handle);
	void showCursor(HANDLE handle);
	void setCursor(HANDLE handle, int x, int y);
	void clearScreenBuffer( WCHAR _wCode, WORD _wAttr);
	void clearScreenBuffer(CHAR_INFO *pBuf, WCHAR _wCode, WORD _wAttr);
	void copyScreenBuffer(CHAR_INFO *pBufdest, CHAR_INFO *pBufsrc);

	void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);
	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
	CHAR_INFO *getCharacter(CHAR_INFO *pBuf, int x, int y);
	void setCharacterW(CHAR_INFO* pBuf, int x, int y, WCHAR code, WORD attr);

	void drawLineH(int _x, int _y, int _nLength, WCHAR code, WORD attr);
	void drawLineV(int _x, int _y, int _nLength, WCHAR code, WORD attr);

	extern CHAR_INFO g_chiBuffer[];


	//유틸리티
	namespace util {
		UINT64 GetTimeMs64();
	}
	extern char g_szTokens[8][MAX_TOKEN_SIZE];
	int doTokenize(char *szBuf, char szBufToken[8][MAX_TOKEN_SIZE]);
	int Tokenize(char* szBuf);

	//파일처리 
	int loadBufferBinary(CHAR_INFO *pBuf, const char *szFileName);
	int saveBufferBinary(CHAR_INFO *pBuf, const char *szFileName);

	CHAR_INFO *CreateScreenBuffer();

	//스프라이트
	void putSprite(int posx, int posy, int destw, int desth, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc);
	void putSprite(int posx, int posy, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc);

	namespace input {
		extern char g_KeyTable[1024];
		extern COORD g_cdMousePos;
		extern DWORD g_dwButtonState;
		void setNormalMode();
		void setEditMode();
		void pauseInputThread();
		void resumeInputThread();
	}
	
	void startTGE(HANDLE *phStdout);
	void endTGE();
	

}

