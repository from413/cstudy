// exam_room1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"
#include "playerObject.h"

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	TGE::hideCursor(hStdout);

	//멥로딩 
	CHAR_INFO* pBackBuf = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pBackBuf, "../res/level1.map");

	PlayerObject::S_OBJ playerObj;
	PlayerObject::init(&playerObj, NULL);

	playerObj.m_fXpos = 40;
	playerObj.m_fYpos = 12;

	int bLoop = true;
	UINT64 _worktick = TGE::util::GetTimeMs64();
	int nFsm = 0;
	while (bLoop) {

		UINT64 _deltaTick = TGE::util::GetTimeMs64() - _worktick;
		_worktick = TGE::util::GetTimeMs64();
		double fDelta = _deltaTick / 1000.0;

		//움직임 처리 
		PlayerObject::apply(&playerObj, _deltaTick);

		//그리기 
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBackBuf);		
		PlayerObject::draw(&playerObj);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //화면에 보이게..

		//종료 
		if (TGE::input::g_KeyTable[VK_ESCAPE]) bLoop = false;

		TGE::setCursor(hStdout, 0, 26);
		printf_s("%4.2f,%4.2f       \n", playerObj.m_fXpos, playerObj.m_fYpos);

	}

	TGE::endTGE();

	free(pBackBuf);
	PlayerObject::release(&playerObj);

	TGE::showCursor(hStdout);

	return 0;
}
