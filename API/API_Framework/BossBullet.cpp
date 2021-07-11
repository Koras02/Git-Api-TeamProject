#include "pch.h"
#include "BossBullet.h"

BossBullet::BossBullet()
{
}

BossBullet::~BossBullet()
{
	Release();
}

void BossBullet::Initialize()
{
	m_tInfo.iCX = 30;
	m_tInfo.iCY = 30;

	m_fSpeed =5.f;
}

int BossBullet::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	m_tInfo.fY += m_fSpeed;
	m_tInfo.fX += rand()%10;
	Update_Rect();

	return OBJ_NOEVENT;
}

void BossBullet::Late_Update()
{
}

void BossBullet::Render(HDC _DC)
{
	Ellipse(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void BossBullet::Release()
{
}
