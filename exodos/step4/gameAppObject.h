#pragma once
namespace GameAppObject
{
	struct S_OBJ
	{
		int m_nObjType;
		int m_nFsm;
		int m_nCurrentLevel;

		void* m_pLevelManager;		
		void* m_pPlayerObj;

		
	};

	inline void init(void* pObj)
	{
		GameAppObject::S_OBJ* pThis = (GameAppObject::S_OBJ*)pObj;
		pThis->m_nFsm = 0;
		pThis->m_nObjType = 1;
		pThis->m_nCurrentLevel = 0;

		pThis->m_pLevelManager = NULL;
		pThis->m_pPlayerObj = NULL;
		
		
	}

	inline void loop(void* pObj,HANDLE hStdout)
	{

		static const char* g_szLevels[256] = {
			"../res/level1.map",
			"../res/level2.map"
		};

		//정적 오브잭트 생성 
		GameAppObject::S_OBJ* pThis = (GameAppObject::S_OBJ*)pObj;

		static PlayerObject::S_OBJ _Player;
		PlayerObject::init(&_Player, pThis);

		static WorldMap::S_OBJ _levelManager;
		WorldMap::init(&_levelManager);

		pThis->m_pPlayerObj = &_Player;
		pThis->m_pLevelManager = &_levelManager;

		//loop start
		UINT64 _worktick = TGE::util::GetTimeMs64();
		bool bLoop = true;
		while (bLoop)
		{
			UINT64 _deltaTick = TGE::util::GetTimeMs64() - _worktick;
			_worktick = TGE::util::GetTimeMs64();
			double fDelta = _deltaTick / 1000.0;

			switch (pThis->m_nFsm)
			{
			case 0:
			{
				TGE::setCursor(hStdout, 0, 25);
				puts("시작 하려면 스페이스바 hit!");
				if (TGE::input::g_KeyTable[VK_SPACE]) {

					TGE::input::g_KeyTable[VK_SPACE] = false;
					TGE::setCursor(hStdout, 0, 25);
					puts("                                     ");

					pThis->m_nCurrentLevel = 0;
					pThis->m_nFsm = 1;
				}
			}
			break;
			case 1:
			{
				WorldMap::readWorldData(pThis->m_pLevelManager, 
					g_szLevels[pThis->m_nCurrentLevel], 
					pThis->m_nCurrentLevel);

				((PlayerObject::S_OBJ *)(pThis->m_pPlayerObj))->m_fXpos = 
					((WorldMap::S_OBJ *)(pThis->m_pLevelManager))->m_posRegen[0];
				((PlayerObject::S_OBJ*)(pThis->m_pPlayerObj))->m_fYpos =
					((WorldMap::S_OBJ*)(pThis->m_pLevelManager))->m_posRegen[1];
				pThis->m_nFsm = 10;
			}
			break;
			case 10:
			{
				//AI & action & animation(physics)
				PlayerObject::apply(pThis->m_pPlayerObj, fDelta);
				WorldMap::apply(pThis->m_pLevelManager, fDelta);

				//Draw
				WorldMap::draw(pThis->m_pLevelManager);
				PlayerObject::draw(pThis->m_pPlayerObj);
			}
			break;
			case 20:
			{
				TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020, 0x0000);
				TGE::setCursor(hStdout, 0, 25);
				puts("다음 레벨을 시작하려면 스페이스바 hit!");
				pThis->m_nFsm = 21;
			}
			break;
			case 21:
			{ //다음 레벨로 가기 
				if (TGE::input::g_KeyTable[VK_SPACE]) {
					pThis->m_nCurrentLevel++;
					if (pThis->m_nCurrentLevel >= 2) {
						pThis->m_nFsm = 100; //game over
					}
					else {
						pThis->m_nFsm = 1;
					}
				}
			}
			break;
			case 100:
			{
				TGE::setCursor(hStdout, 0, 25);
				puts("     탈출 성공                             ");

				pThis->m_nFsm = 101; // 대기상태
			}
			break;
			default:
				break;
			}

			TGE::updateBuffer(hStdout, TGE::g_chiBuffer); //화면에 보이게..



		}

	}

	inline void release(void* pObj)
	{
		GameAppObject::S_OBJ* pThis = (GameAppObject::S_OBJ*)pObj;

		//오브잭트 해제 
		if (pThis->m_pLevelManager) free(pThis->m_pLevelManager);
		if (pThis->m_pPlayerObj) free(pThis->m_pPlayerObj);	
	}
}