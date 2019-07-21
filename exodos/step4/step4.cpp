// exodos.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "..\..\..\cstudy\engine\tge.h"

#include "worldmap.h"
#include "playerObject.h"
#include "gameAppObject.h"


GameAppObject::S_OBJ g_GameApp;

int main()
{
	HANDLE hStdout;
	TGE::startTGE(&hStdout);
	TGE::hideCursor(hStdout);
	
	GameAppObject::init(&g_GameApp);

	GameAppObject::loop(&g_GameApp,hStdout);

	GameAppObject::release(&g_GameApp);

	TGE::showCursor(hStdout);	
	TGE::endTGE();

	return 0;
}
