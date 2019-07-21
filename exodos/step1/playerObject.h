#pragma once
namespace PlayerObject {
	struct S_OBJ
	{
		int m_nObjType;
		double m_fXpos, m_fYpos; //위치정보
		double m_fSpeed;
		void* m_pMap;
	};

	inline void init(void* pObj, void* pMap)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		ptrThis->m_nObjType = 1000;
		ptrThis->m_fXpos = 0;
		ptrThis->m_fYpos = 0;
		ptrThis->m_fSpeed = 2.0;
		ptrThis->m_pMap = pMap;
	}
	inline void release(void* pObj)
	{

	}

	inline void apply(void* pObj, double fDelat)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;
		if (TGE::input::g_KeyTable[VK_LEFT]) {
			TGE::input::g_KeyTable[VK_LEFT] = 0; //연속눌림 처리 방지
			ptrThis->m_fXpos -= 1; //왼쪽이동
		}
		if (TGE::input::g_KeyTable[VK_RIGHT]) {
			TGE::input::g_KeyTable[VK_RIGHT] = 0; //연속눌림 처리 방지
			ptrThis->m_fXpos += 1; //오른쪽이동
		}
	}
	void draw(void* pObj)
	{
		PlayerObject::S_OBJ* ptrThis = (PlayerObject::S_OBJ*)pObj;

		TGE::setCharacter(TGE::g_chiBuffer, (int)ptrThis->m_fXpos, (int)ptrThis->m_fYpos,
			0x0020,
			0x00F0
		);
	}
}