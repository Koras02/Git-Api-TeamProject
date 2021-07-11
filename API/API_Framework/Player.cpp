#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "Shield.h"
#include "ObjMgr.h"
#include "ScrewBullet.h"
#include "GuideBullet.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "MisaleBullet.h"


CPlayer::CPlayer()
{
	ZeroMemory(&m_tPosin, sizeof(m_tPosin));
}


CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 50;


	m_fSpeed = 5.f;

	m_fMisaleDis = 50.f;

	
}

int CPlayer::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	Key_Check();
 
	
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE))
		CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMisaleBullet>::Create(m_tPosin.x, m_tPosin.y, m_fAngle),OBJID::MISALE);
 

	Update_Rect();

	
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	m_tPosin.x = (LONG)(m_tInfo.fX + cosf(m_fAngle * PI / 180.f) * m_fMisaleDis);
	m_tPosin.y = (LONG)(m_tInfo.fY - sinf(m_fAngle * PI / 180.f) * m_fMisaleDis);

	//m_tPosin.y = (LONG)(m_tInfo.fY - sinf(m_fAngle * PI / 30.f) * m_fMisaleDis);
	//m_tPosin.x = (LONG)(m_tInfo.fX + cosf(m_fAngle * PI / 30.f) * m_fMisaleDis);
	 
    

}

void CPlayer::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
 

	MoveToEx(_DC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(_DC, m_tPosin.x, m_tPosin.y);

}

void CPlayer::Release()
{

}

void CPlayer::Key_Check()
{
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LEFT))
		m_tInfo.fX -= 5.f;
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RIGHT))
		m_tInfo.fX += 5.f; 
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_UP))
		m_tInfo.fY -= 5.f;
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_DOWN))
		m_tInfo.fY += 5.f;
 
}
 

 

 
 

 
