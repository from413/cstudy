#include "framework.h"
#include "gameMain.h"

BYTE g_KeyTable[1024] = {0};

void OnKeyDown(WORD wKeycode)
{
	g_KeyTable[wKeycode] = 1;

}

void OnKeyUp(WORD wKeycode)
{
	g_KeyTable[wKeycode] = 0;

}

void OnGdiplusSetup()
{	

}

void OnGdiplusFinish()
{
}

void OnGdiplusApply(double fDelta)
{
}


void OnGdiplusRender(double fDelta, Graphics *pGrp)
{

	


}