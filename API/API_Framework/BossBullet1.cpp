#include "pch.h"
#include "BossBullet1.h"

BossBullet1::BossBullet1()
{
}

BossBullet1::~BossBullet1()
{
	Release();
}

void BossBullet1::Initialize()
{
	m_tInfo.iCX = 30;
	m_tInfo.iCY = 60;

	m_fSpeed = 10.f;
}

int BossBullet1::Update()
{
	if (m_bDead)
		return OBJ_DEAD;


	m_tInfo.fY += m_fSpeed;

	Update_Rect();

	return OBJ_NOEVENT;
}

void BossBullet1::Late_Update()
{
}

void BossBullet1::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void BossBullet1::Release()
{
}
