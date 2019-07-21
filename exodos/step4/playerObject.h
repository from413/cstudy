#pragma once
namespace PlayerObject {
	struct S_OBJ
	{
		char m_szName[64];
		void* m_pApp;
		double m_fXpos, m_fYpos; //위치정보
		double m_fSpeed;
		int m_nStatus_HaveKey;
	};

	void init(void* , void* );
	void release(void* );
	void apply(void* , double );
	void draw(void* );
}