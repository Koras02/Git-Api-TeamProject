#include "pch.h"
#include "KeyMgr.h"

CKeyMgr* CKeyMgr::m_pInstance = nullptr;

CKeyMgr::CKeyMgr()
{
	ZeroMemory(m_bState, sizeof(m_bState));
}

CKeyMgr::~CKeyMgr()
{
}

bool CKeyMgr::Key_Pressing(int _key)
{
	if (GetAsyncKeyState(_key) & 0x8000)
		return true;
	return false;
}

bool CKeyMgr::Key_Down(int _key)
{
	if (!m_bState[_key] && (GetAsyncKeyState(_key) & 0x8000))
	{ //안눌린상태이고 키를 눌렀을때 누름상태로바꾸고 true반환
		m_bState[_key] = !m_bState[_key];
		return true;
	}

	if (m_bState[_key] && !(GetAsyncKeyState(_key) & 0x8000))
		m_bState[_key] = !m_bState[_key];
	// 상태가 눌러져잇는상태이고 키를 더이상 누르지않았을때
	// 상태를 false로 바꿈
	return false;
}

bool CKeyMgr::Key_Up(int _key)
{
	if (m_bState[_key] && !(GetAsyncKeyState(_key) & 0x8000))
	{ //키가 눌러져잇고 키를 더이상누르지않았을때 즉 키를땟을때
		m_bState[_key] = !m_bState[_key];
		return true;
	}

	if (!m_bState[_key] && (GetAsyncKeyState(_key) & 0x8000))
		m_bState[_key] = !m_bState[_key];
	//키가 안눌러져있고 키를 눌렀을대


	return false;
}
