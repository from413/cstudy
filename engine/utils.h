#pragma once


extern void win32_Printf(HWND hWnd, TCHAR *fmt, ...);
extern void win32_Scanf(const TCHAR *szBuf, const TCHAR *fmt, ...);

extern void DisplayLog(HDC hdc);
extern void ClearLog(HWND hWnd);