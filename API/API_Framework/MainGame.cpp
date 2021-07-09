#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "CollisionMgr.h"
#include "Mouse.h"
#include "ObjMgr.h"
#include "LineMgr.h"

CMainGame::CMainGame()
	: m_iFPS(0),
	m_hDC(NULL),
	m_dwFPSTime(GetTickCount64())
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);

	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CPlayer>::Create(), OBJID::PLAYER);


	CLineMgr::Get_Instance()->Initialize();




}

void CMainGame::Update()
{
	CLineMgr::Get_Instance()->Update();
	CObjMgr::Get_Instance()->Update();
}

void CMainGame::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CMainGame::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	CObjMgr::Get_Instance()->Render(m_hDC);
	CLineMgr::Get_Instance()->Render(m_hDC);


#ifdef _DEBUG
	TCHAR szBuff[32] = L"";
	swprintf_s(szBuff, L"총알개수: %d", m_listObj[OBJID::BULLET].size());
	TextOut(m_hDC, 50, 50, szBuff, lstrlen(szBuff));

	++m_iFPS;
	if (m_dwFPSTime + 1000 < GetTickCount64())
	{
		TCHAR szFPS[16] = L"";
		swprintf_s(szFPS, L"FPS: %d", m_iFPS);

		SetWindowText(g_hWnd, szFPS);

		m_iFPS = 0;
		m_dwFPSTime = GetTickCount64();
	}
	
	POINT pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	TCHAR szBulletPos[32] = L"";
	swprintf_s(szBulletPos, L"마우스위치: %d %d", pt.x, pt.y);
	TextOut(m_hDC, 200, 50, szBulletPos, lstrlen(szBulletPos));

	TCHAR szBulletPos1[32] = L"";
	swprintf_s(szBulletPos1, L"저장된선개수: %d", CLineMgr::Get_Instance()->Get_LineSize());
	TextOut(m_hDC, 400, 50, szBulletPos1, lstrlen(szBulletPos1));



#endif // _DEBUG


}

void CMainGame::Release()
{
	CLineMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_hDC);
}