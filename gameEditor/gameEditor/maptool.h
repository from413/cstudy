#pragma once

struct S_TGE_MAPTOOL
{

	COORD m_cdCurrentCursorPos;
	WCHAR m_wcCurrentBrushCode;
	WORD m_CurrentBrushAttr;

};

void initMapTool(S_TGE_MAPTOOL *pObj);
int parseCmd(S_TGE_MAPTOOL *pObj, char *szCmdBuf);



