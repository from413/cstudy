// ex3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	int bLoop = true;

	TGE::hideCursor(hStdout);

	while (bLoop) {
		
		if (TGE::input::g_KeyTable[VK_RETURN]) {
			//동기식 입력 처리 
			TGE::input::pauseInputThread();
			TGE::input::setEditMode();

			TGE::showCursor(hStdout);
			TGE::setCursor(hStdout, 0, 27);
			char szBuf[256];
			gets_s(szBuf, sizeof(szBuf));

			int tokenNum = TGE::Tokenize(szBuf); //TGE::g_szTokens 에 토큰 저장 
			if (tokenNum > 0) {
				if (!strcmp(TGE::g_szTokens[0], "exit")) {
					bLoop = false;
					TGE::setCursor(hStdout, 0, 26);
					puts("종료합니다.");
				}
				else {
					TGE::setCursor(hStdout, 0, 27);
					puts("                        ");

				}
			}
			//커서 다시 숨기기 
			TGE::hideCursor(hStdout);
			TGE::input::g_KeyTable[VK_RETURN] = false;
			
			TGE::input::setNormalMode();
			TGE::input::resumeInputThread();
		}

		//비동기식 키입력 
		TGE::setCursor(hStdout, 0, 26);
		printf_s("U%2dD%2dL%2dR%2d",
			TGE::input::g_KeyTable[VK_UP],
			TGE::input::g_KeyTable[VK_DOWN],
			TGE::input::g_KeyTable[VK_LEFT],
			TGE::input::g_KeyTable[VK_RIGHT]
		);
	}

	TGE::endTGE();
	return 0;
    
}
