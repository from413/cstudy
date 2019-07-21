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

Image* pImg1;
void OnGdiplusSetup()
{	
	pImg1 = new Image(L"../../pub_res/basic_tile/basictiles.png");

}

void OnGdiplusFinish()
{
	delete pImg1;
}

void OnGdiplusApply(double fDelta)
{
}


void OnGdiplusRender(double fDelta, Graphics *pGrp)
{
	static irr::f32 _accTick;
	_accTick += fDelta;

	if (_accTick > 0.2 || _accTick < 0) {
		_accTick = 0;
		
		pGrp->TranslateTransform(rand() % 320, rand() % 240);
		pGrp->ScaleTransform((rand() % 100 + 1) / 10.0, (rand() % 100 + 1) / 10.0);
		pGrp->RotateTransform(rand() % 360);

		pGrp->DrawImage(pImg1,
			Rect(0, 0, 16, 16),
			0, 16 * 6,
			15, 16,
			UnitPixel);

		pGrp->ResetTransform();

	}

	

}