#include "pch.h"
#include "MainEdit.h"
#include "KeyMgr.h"
#include "LineMgr.h"
#include "ScrollMgr.h"

CMainEdit::CMainEdit()
{
}

CMainEdit::~CMainEdit()
{
	Release();
}

void CMainEdit::Initialize()
{
	m_hDC = GetDC(g_hWnd);
}

void CMainEdit::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		CLineMgr::Get_Instance()->Add_Line();

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		CScrollMgr::Get_Instance()->Set_ScrollX(5.f);
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		CScrollMgr::Get_Instance()->Set_ScrollX(-5.f);
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		CScrollMgr::Get_Instance()->Set_ScrollY(5.f);
	if(CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		CScrollMgr::Get_Instance()->Set_ScrollY(-5.f);
	if (CKeyMgr::Get_Instance()->Key_Down('A'))
		CLineMgr::Get_Instance()->Save_Line();
	if (CKeyMgr::Get_Instance()->Key_Down('S'))
		CLineMgr::Get_Instance()->Load_Line();

}

void CMainEdit::Late_Update()
{
}

void CMainEdit::Render()
{
	Rectangle(m_hDC, 0, 0, WINCX, WINCY);

	CLineMgr::Get_Instance()->Render(m_hDC);
}

void CMainEdit::Release()
{
	CScrollMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();
	CLineMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_hDC);
}
