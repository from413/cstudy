

winmain 함수에서 메시지 루프 코드변경 

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM1));

    MSG msg;

	////////////////////////   코드 변경 
	plusEngine::GDIPLUS_Loop(msg, Rect(0, 0, 320, 240), OnGdiplusSetup, OnGdiplusApply, OnGdiplusRender, OnGdiplusFinish);


    return (int) msg.wParam;
}


InitInstance 에서 엔진용 hdc 셋업

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

////////////////////<< 코드 추가 
   //화면 이동
   MoveWindow(hWnd, 0, 0, 512, 512, true);
//>>///////////////////////////////   

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   
////////////////////<< 코드 추가
   //셋업
   plusEngine::updateDC(hWnd);
// >>///////////////////////////////   


   return TRUE;
}
