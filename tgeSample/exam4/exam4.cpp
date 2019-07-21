// exam4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	TGE::hideCursor(hStdout);
	bool bLoop = true;
	while (bLoop)
	{
		//비동기식 입력
		if (TGE::input::g_KeyTable[VK_RETURN]) {
			bLoop = false;
		}

		TGE::setCharacter(TGE::g_chiBuffer, 1, 1,0x0041,
			0x00f0
			);
		TGE::setCharacter(TGE::g_chiBuffer, 2, 1, 0x0042,
			0x00f0
		);

		//유니코드 특수문자셋
		//http://www.hipenpal.com/tool/characters-to-unicode-charts-in-korean.php?unicode=71
		TGE::setCharacterW(TGE::g_chiBuffer, 1, 2, 
			9733,
			0x00fc
		);

		////유니코드 형 기본 문자셋
	//http://www.hipenpal.com/tool/characters-to-unicode-charts-in-korean.php?unicode=0
		
		TGE::setCharacterW(TGE::g_chiBuffer, 20, 20, 0x0020,
			0x00fc // 1111 1100
		);
		TGE::setCharacterW(TGE::g_chiBuffer, 20, 19, 0x0041,
			0x00fc // 1111 1100
		);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}

	TGE::endTGE();
}
