#include "tge.h"
#include "tge_sprite.h"

namespace tge_sprite {

	void Init(S_SPRITE_OBJECT *pObj) 
	{
		pObj->m_header.m_cdWorkSpr = { 0,0 };
		strcpy_s(pObj->m_header.szHeader, sizeof(pObj->m_header.szHeader), "TGESPR");
		pObj->m_pSpriteBuf = NULL;
	}
	void Release(S_SPRITE_OBJECT *pObj)
	{
		free(pObj->m_pSpriteBuf);
	}


	int load(S_SPRITE_OBJECT *pObj, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "r");

		fread(&(pObj->m_header), sizeof(S_SPRITE_HEADER), 1, fp);

		if (pObj->m_pSpriteBuf != NULL) { free(pObj->m_pSpriteBuf); }

		int _nBuffSize = pObj->m_header.m_cdWorkSpr.X*pObj->m_header.m_cdWorkSpr.Y * sizeof(CHAR_INFO);

		pObj->m_pSpriteBuf = (CHAR_INFO *)malloc(_nBuffSize);
		fread(pObj->m_pSpriteBuf,
			_nBuffSize, 1,
			fp);

		fclose(fp);

		return 0;
	}
	int save(S_SPRITE_OBJECT *pObj, const char *szFileName)
	{
		FILE *fp;
		fopen_s(&fp, szFileName, "w");

		fwrite(&(pObj->m_header), sizeof(S_SPRITE_HEADER), 1, fp);
		fwrite(pObj->m_pSpriteBuf,
			sizeof(CHAR_INFO), pObj->m_header.m_cdWorkSpr.X*pObj->m_header.m_cdWorkSpr.Y,
			fp);

		fclose(fp);

		return 0;
	}
	int put(S_SPRITE_OBJECT *pObj, int posx, int posy)
	{
		TGE::putSprite(posx, posy,
			pObj->m_header.m_cdWorkSpr.X,
			pObj->m_header.m_cdWorkSpr.Y, TGE::g_chiBuffer, pObj->m_pSpriteBuf);
 		return 0;
	}
	int put(S_SPRITE_OBJECT *pObj, int posx, int posy,CHAR_INFO *pDestScreenBuf)
	{
		TGE::putSprite(posx, posy,
			pObj->m_header.m_cdWorkSpr.X,
			pObj->m_header.m_cdWorkSpr.Y, pDestScreenBuf, pObj->m_pSpriteBuf);
		return 0;

	}
	int get(S_SPRITE_OBJECT *pObj, int _xpos, int _ypos, int _width, int _height)
	{
		if (pObj->m_pSpriteBuf != NULL) { free(pObj->m_pSpriteBuf); }
		pObj->m_pSpriteBuf = (CHAR_INFO *)malloc(sizeof(CHAR_INFO) * (_width*_height));
		pObj->m_header.m_cdWorkSpr = { (SHORT)_width , (SHORT)_height };

		int _desx, _desy;

		for (_desy = 0; _desy < _height; _desy++) {
			for (_desx = 0; _desx < _width; _desx++) {
				pObj->m_pSpriteBuf[_desx + (_desy*_width)] =
					TGE::g_chiBuffer[(_desx + _xpos) + ((_desy + _ypos) * TGE::SCREEN_WIDTH)];
			}
		}
		return 0;
	}

}