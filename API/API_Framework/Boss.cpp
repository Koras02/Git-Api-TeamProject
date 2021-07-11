#include "pch.h"
#include "Boss.h"
#include "BossBullet.h"
#include "BossBullet1.h"
#include "ObjMgr.h"
#include <time.h>
CBoss::CBoss()
	: Leg1(270), Leg2(380), Leg3(490), fSpeed(5.f), fSpeed1(3.f), iMaxHp(10)
{
	Collision_Rec = {};
}

CBoss::~CBoss()
{
}

void CBoss::Initialize()
{
	srand(unsigned(time(NULL)));
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 100.f;
	m_tInfo.iCX = 150;
	m_tInfo.iCY = 200;
	for (int i = 10; i > 0; --i)
	{
		rec[i].left = (i * 60) + 100;
		rec[i].right = ((i+1) * 60) + 100;
		rec[i].top = 0;
		rec[i].bottom = 25;
	}
}
int CBoss::Update()
{
	if (m_bDead)
	{
		iMaxHp -= 1;
		m_bDead = !m_bDead;
		if (iMaxHp == 0);
		{
		}
	}
	if (Leg1 < 400)
	{
		Leg1 += fSpeed;
		Leg2 += fSpeed;
		Leg3 += fSpeed;
	}
	m_tInfo.fX += fSpeed1;
	if (_dwTime1 + 1000 <= GetTickCount())
	{
		CObjMgr::Get_Instance()->Add_Object(Create_Bullet<BossBullet>(Leg1, 250), OBJID::BOSSBULLET);
		_dwTime1 = GetTickCount();
	}
	if (_dwTime2 + 1500 <= GetTickCount())
	{
		CObjMgr::Get_Instance()->Add_Object(Create_Bullet<BossBullet>(Leg2, 250), OBJID::BOSSBULLET);
		_dwTime2 = GetTickCount();
	}
	if (_dwTime3 + 2000 <= GetTickCount())
	{
		CObjMgr::Get_Instance()->Add_Object(Create_Bullet<BossBullet>(Leg3, 250), OBJID::BOSSBULLET);
		_dwTime3 = GetTickCount();
	}
	if (_dwTime4 + 2000 <= GetTickCount())
	{
		CObjMgr::Get_Instance()->Add_Object(Create_Bullet<BossBullet1>(rand()%800, 0), OBJID::BOSSBULLET);
		CObjMgr::Get_Instance()->Add_Object(Create_Bullet<BossBullet1>(rand() % 800, 0), OBJID::BOSSBULLET);
		_dwTime4 = GetTickCount();
	}

	Update_Rect();
	return OBJ_NOEVENT;
}

void CBoss::Late_Update()
{
	if (Leg1 >= 380 || Leg1 <= 200)
		fSpeed *= -1.f;
	if (m_tInfo.fX >= 500 || m_tInfo.fX <= 200)
		fSpeed1 *= -1.f;
	Update_Rect();
}

void CBoss::Render(HDC _DC)
{
	MoveToEx(_DC, m_tInfo.fX, 50, nullptr);
	LineTo(_DC, m_tInfo.fX - 50, 100);
	LineTo(_DC, m_tInfo.fX + 50, 100);
	LineTo(_DC, m_tInfo.fX, 50);
	MoveToEx(_DC, m_tInfo.fX - 50, 100, nullptr);
	LineTo(_DC, m_tInfo.fX - 80, 200);
	LineTo(_DC, m_tInfo.fX + 80, 200);
	LineTo(_DC, m_tInfo.fX + 50, 100);
	Ellipse(_DC, m_tInfo.fX - 40, 110, m_tInfo.fX - 20, 150);
	Ellipse(_DC, m_tInfo.fX + 20, 110, m_tInfo.fX + 40, 150);
	MoveToEx(_DC, m_tInfo.fX, 150, nullptr);
	LineTo(_DC, m_tInfo.fX, 180);
	MoveToEx(_DC, m_tInfo.fX - 100, 200, nullptr);
	LineTo(_DC, m_tInfo.fX + 100, 200);
	LineTo(_DC, m_tInfo.fX + 110, 210);
	LineTo(_DC, m_tInfo.fX - 110, 210);
	LineTo(_DC, m_tInfo.fX - 100, 200);
	MoveToEx(_DC, m_tInfo.fX - 110, 210, nullptr);
	LineTo(_DC, Leg1, 250);
	MoveToEx(_DC, m_tInfo.fX , 210, nullptr);
	LineTo(_DC, Leg2, 250);
	MoveToEx(_DC, m_tInfo.fX + 110, 210, nullptr);
	LineTo(_DC, Leg3, 250);
	for (int i = 0; i < iMaxHp; ++i)
	{
		Rectangle(_DC, rec[i].left, rec[i].top, rec[i].right, rec[i].bottom);
	}
	//Ellipse(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	
	//Ellipse(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBoss::Release()
{
}
