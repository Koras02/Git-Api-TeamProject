#pragma once

#ifndef __CMAINGAME_H__
#define __CMAINGAME_H__

class CObj;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();

private:
	HDC m_hDC;

	//CObj* m_pPlayer;

	list<CObj*> m_listObj[OBJID::END];

	int m_iFPS;
	DWORD64 m_dwFPSTime;

	


};


#endif // !__CMAINGAME_H__


