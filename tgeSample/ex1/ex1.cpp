// ex1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../../engine/tge.h"

int main()
{
	
	HANDLE hStdout;
	TGE::startTGE(&hStdout);

	TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020,0x009f);

	//https://ko.wikipedia.org/wiki/%EC%9C%A0%EB%8B%88%EC%BD%94%EB%93%9C_2000~2FFF
	
	TGE::setCharacterW(TGE::g_chiBuffer, 0, 0, 0x2663, 0x00fc);
	TGE::setCharacterW(TGE::g_chiBuffer, 1, 0, 0x2665, 0x00fc);
	TGE::setCharacterW(TGE::g_chiBuffer, 2, 2, 0x00, 0x00fc);

	TGE::setCharacter(TGE::g_chiBuffer,4, 1, TEXT('A'), 0x00fc);
	TGE::setCharacter(TGE::g_chiBuffer,5, 1, TEXT('B'), 0x00fc);
    
	TGE::updateBuffer(hStdout,TGE::g_chiBuffer);

	TGE::setCursor(hStdout, 0, 20);

	TGE::endTGE();

	return 0;
}
