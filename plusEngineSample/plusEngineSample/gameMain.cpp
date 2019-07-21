#include "stdafx.h"
#include "gameMain.h"

Image *g_pImage;

BYTE g_KeyTable[1024] = {0};
double fAngle = 0;
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
	//Image _tmp(L"../../pub_res/ww2/Fighters/p38g.png");
	g_pImage = new Image(L"../../pub_res/ww2/Fighters/p38g.png");//_tmp.Clone();

}

void OnGdiplusFinish()
{
	delete g_pImage;

}

void OnGdiplusApply(double fDelta)
{
	fAngle += fDelta * 45;
}


void OnGdiplusRender(double fDelta, Graphics *pGrp)
{

	pGrp->Clear(Color(200, 200, 200));

	Pen penRed(Color(255, 0, 0));
	Pen penBlack(Color(0, 0, 0));
	Gdiplus::SolidBrush brushBalck(Color(0, 255, 0));

	pGrp->DrawLine(&penBlack, 160, 0, 160, 240);
	pGrp->DrawLine(&penBlack, 0, 120, 320, 120);
	pGrp->DrawRectangle(&penBlack, Rect(0, 0, 320, 240));

	pGrp->TranslateTransform(160, 120);

	
	{
		Matrix _tmp;
		pGrp->GetTransform(&_tmp);

		pGrp->RotateTransform(fAngle);
		irr::core::vector2df _pos(0 - g_pImage->GetWidth() / 2.0, 0 - g_pImage->GetHeight() / 2.0);
		pGrp->TranslateTransform(_pos.X, _pos.Y);
		pGrp->DrawImage(g_pImage,
			Rect(0, 0, g_pImage->GetWidth(), g_pImage->GetHeight()),
			0, 0, g_pImage->GetWidth(), g_pImage->GetHeight(), UnitPixel);

		pGrp->SetTransform(&_tmp);

	}
	

	pGrp->ResetTransform();

}