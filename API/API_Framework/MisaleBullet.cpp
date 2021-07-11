#include "pch.h"
#include "MisaleBullet.h"
#include "KeyMgr.h"

CMisaleBullet::CMisaleBullet()
	:m_fCenterAngle(0.f),m_fCenterSpeed(0.f),m_bStart(true)
{
	ZeroMemory(&m_tCenterMis, sizeof(m_tCenterMis));
}

CMisaleBullet::~CMisaleBullet()
{
	Release();
}

void CMisaleBullet::Initialize()
{
   
	m_tInfo.iCX = 21.9f;
	m_tInfo.iCY = 10.f;

	m_fSpeed = 50.f;	
	m_fDis = 10.f;

	m_fCenterSpeed = 50.f;

}

int CMisaleBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	if (m_bStart)
	{
		m_tCenterMis.x = (LONG)m_tInfo.fX;
		m_tCenterMis.y = (LONG)m_tInfo.fY;
		m_fCenterAngle = m_fAngle;
		m_bStart = false;
	}

 
 
	m_tCenterMis.x -= (LONG)(cosf(m_fCenterAngle * PI / 180.f) * m_fCenterSpeed);
	m_tCenterMis.y += (LONG)(sinf(m_fCenterAngle * PI / 180.f) * m_fCenterSpeed);

	m_tInfo.fX = m_tCenterMis.x -= cosf(m_fCenterAngle * PI / 180.f) * m_fDis;
	m_tInfo.fY = m_tCenterMis.y += sinf(m_fCenterAngle * PI / 180.f) * m_fDis;


	m_fAngle += m_fSpeed;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CMisaleBullet::Late_Update()
{
	if (50 >= m_tRect.left || 50 >= m_tRect.top
		|| WINCX - 100 <= m_tRect.right || WINCY - 100 <= m_tRect.bottom)
		m_bDead = true;

	if (50 >= m_tInfo.iCX || 50 >= m_tInfo.iCY
		|| WINCX - 100 <= m_tInfo.iCY || WINCX - 100 <= m_tInfo.iCY);
}

void CMisaleBullet::Render(HDC _DC)
{
	Ellipse(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
 
}

void CMisaleBullet::Release()
{
}
