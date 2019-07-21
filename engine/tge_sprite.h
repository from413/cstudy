#pragma once

namespace tge_sprite {
	struct S_SPRITE_HEADER {
		char szHeader[16];
		COORD m_cdWorkSpr;
	};

	struct S_SPRITE_OBJECT {
		S_SPRITE_HEADER m_header;
		CHAR_INFO *m_pSpriteBuf;
	};

	void Init(S_SPRITE_OBJECT *pObj);
	void Release(S_SPRITE_OBJECT *pObj);
	int load(S_SPRITE_OBJECT *pObj, const char *szFileName);
	int save(S_SPRITE_OBJECT *pObj, const char *szFileName);
	int put(S_SPRITE_OBJECT *pObj, int posx, int posy);
	int put(S_SPRITE_OBJECT *pObj, int posx, int posy, CHAR_INFO *pDestScreenBuf);
	int get(S_SPRITE_OBJECT *pObj, int _xpos, int _ypos, int _width, int _height);

}