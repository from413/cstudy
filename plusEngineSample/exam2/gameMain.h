#pragma once


void OnKeyDown(WORD wKeycode);
void OnKeyUp(WORD wKeycode);
void OnGdiplusRender(double fDelta, Graphics *pGrp);
void OnGdiplusSetup();
void OnGdiplusFinish();
void OnGdiplusApply(double fDelta);

