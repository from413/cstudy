//#include "stdafx.h"
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <Windows.h>
#include "utils.h"

TCHAR g_szaMsgLog[1024][256];
int g_nMsgLogTailIndex = 0;

void win32_Printf(HWND hWnd, TCHAR *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	//swprintf_s(g_szaMsgLog[g_nMsgLogTailIndex], 256, L"%d 번 메씨지", g_nMsgLogTailIndex);
	vswprintf_s(g_szaMsgLog[g_nMsgLogTailIndex], 256, fmt, ap);
	g_nMsgLogTailIndex++;
	va_end(ap);
	InvalidateRect(hWnd, NULL, TRUE);
}

void win32_Scanf(const TCHAR *szBuf, const TCHAR *fmt,...)
{
	va_list ap;
	va_start(ap, fmt);
	vswscanf(szBuf, fmt, ap);
	va_end(ap);
}

void ClearLog(HWND hWnd)
{
	g_nMsgLogTailIndex = 0;
	InvalidateRect(hWnd, NULL, TRUE);
}

void DisplayLog(HDC hdc)
{
	for (int i = 0; i < g_nMsgLogTailIndex; i++) {
		TextOut(hdc, 0, i * 24, g_szaMsgLog[i], wcslen(g_szaMsgLog[i]));
	}
}