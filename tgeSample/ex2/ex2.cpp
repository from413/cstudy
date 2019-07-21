// 멥파일 로딩 &출력 예제
//

#include <iostream>

#include "../../engine/tge.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	CHAR_INFO* pBackBuf = TGE::CreateScreenBuffer();
	CHAR_INFO* pMapDataBuf = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pMapDataBuf, "../../pub_res/1.map");


	bool bLoop = true;
	while (bLoop)
	{	
		//비동기식 입력
		if (TGE::input::g_KeyTable[VK_RETURN]) {
			bLoop = false;
		}

		TGE::copyScreenBuffer(pBackBuf, pMapDataBuf);

		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	}

	free(pBackBuf);
	free(pMapDataBuf);
	TGE::endTGE();

}
