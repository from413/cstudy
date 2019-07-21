

static ,edit button control 예제


컨트롤에서 내용을 읽어오기
int nAge;
GetWindowText(GetDlgItem(hWnd, 3002), szTemp, sizeof(szTemp) / sizeof(TCHAR));
nAge = _wtoi(szTemp);

GetWindowText 의 첫번째 인자는 값을 얻어내고 싶은 윈도우의 핸들이다.
GetDlgItem 으로 3002번 컨트롤의 윈도우핸들을 가져온다.
그리고 다음 인자로 버퍼를 넘겨주어 내용을 받아온다.

반대로 컨트롤로 쓰고 싶다면 setwindowtext를 사용한다.
SetWindowText(GetDlgItem(hWnd, 4002),szBuf);

-도전과제
두수를 입력받아 사칙연산을 수행하라



참고
http://soen.kr/lecture/win32api/lec7/lec7-1-1.htm
