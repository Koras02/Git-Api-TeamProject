#include "pch.h"
#include "Mouse.h"

CMouse::CMouse()
{
	ZeroMemory(&m_tMousePos, sizeof(POINT));
}

CMouse::~CMouse()
{
}

void CMouse::Initialize()
{
}

int CMouse::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	POINT pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	m_tInfo.fX = static_cast<float>(pt.x);
	m_tInfo.fY = static_cast<float>(pt.y);

	Update_Rect();

	Key_Check();


	return OBJ_NOEVENT;
}

void CMouse::Late_Update()
{
}

void CMouse::Render(HDC _DC)
{
}

void CMouse::Release()
{
}

void CMouse::Key_Check()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{

	}
}
