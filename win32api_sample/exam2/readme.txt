메뉴 리소스 다루기

int nResult = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, testProc);
switch (nResult)
{
				case IDOK:
					OutputDebugString(L"IDOK");
					break;
				case IDCANCEL:
					OutputDebugString(L"IDCANCEL");
					break;
				default:
					break;
}

DialogBox 함수는 블로킹으로 동작한다. 창을 닫으면 dialogbox 함수 다음줄이 실행된다.


INT_PTR CALLBACK testProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		else if ((LOWORD(wParam) == IDC_BUTTON1) ) {
			static TCHAR szTemp[256];
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_TEST), szTemp,
				sizeof(szTemp) / sizeof(TCHAR));

			SetWindowText(GetDlgItem(hDlg, IDC_STATIC_TEST), szTemp);

		}
		break;
	}
	return (INT_PTR)FALSE;
}

EndDialog 함수가 호출되면 창이 닫히고 두번째 인자로 넘겨준값이 DialogBox의 리턴값이 된다.


-도전과제
다이얼로그박스로 두수를 입력받아 부모윈도우에서 곱을 구하고 결과값을 출력 하시오.



참고 
http://soen.kr