#include "pch.h"
#include "ScrewBullet.h"

CScrewBullet::CScrewBullet()
	: m_fCenterAngle(0.f), m_fCenterSpeed(0.f), m_bStart(true)
{
	ZeroMemory(&m_tCenterPos, sizeof(m_tCenterPos));
}

CScrewBullet::~CScrewBullet()
{
	Release();
}

void CScrewBullet::Initialize()
{
	m_tInfo.iCX = 10;
	m_tInfo.iCY = 10;
	m_tInfo.fX = 50;
	m_tInfo.fY = 50;

	m_fSpeed = 5.f;
	//m_fDis = 40.f;

	m_fCenterSpeed = 5.f;
}

int CScrewBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (m_bStart)
	{
		m_tCenterPos.x = (LONG)m_tInfo.fX;
		m_tCenterPos.y = (LONG)m_tInfo.fY;
		m_fCenterAngle = m_fAngle;
		m_bStart = false;
	}

	m_tCenterPos.x -= (LONG)(cosf(m_fCenterAngle * PI / 10.f) * m_fCenterSpeed);
	m_tCenterPos.y += (LONG)(sinf(m_fCenterAngle * PI / 10.f) * m_fCenterSpeed);

	m_tInfo.fX = m_tCenterPos.x + cosf(m_fAngle * PI / 100.f) * m_fDis;
	m_tInfo.fY = m_tCenterPos.y - sinf(m_fAngle * PI / 180.f) * m_fDis;

	m_tInfo.iCX += (LONG)(cosf(m_fMisale * PI / 10.f) * m_fCenterSpeed);
	m_tInfo.iCY -= (LONG)(cosf(m_fMisale * PI / 10.f) * m_fCenterSpeed);


	m_fAngle += m_fSpeed;

	Update_Rect();

	return OBJ_NOEVENT;
}

void CScrewBullet::Late_Update()
{
	if (50 >= m_tRect.left || 50 >= m_tRect.top
		|| WINCX - 100 <= m_tRect.right || WINCY - 100 <= m_tRect.bottom)
		m_bDead = true;

	if (10 >= m_tRect.right || 50 >= m_tRect.top
		|| WINCX - 100 <= m_tRect.left || WINCY + 100 <= m_tRect.bottom)
		m_bDead = true;
}

void CScrewBullet::Render(HDC _DC)
{
	Ellipse(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CScrewBullet::Release()
{
}
