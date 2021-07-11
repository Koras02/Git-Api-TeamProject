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
#include "Boss.h"
#include "PlayerIDLE.h"


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
	

	m_fSpeed = 20.f;

	m_fMisaleDis = 50.f;

	m_fPlayerIDLEDIS = 50;

	m_fScrewDis = 50.f;

 
}

int CPlayer::Update()
{
	//if (m_bDead)
	//	return OBJ_DEAD;

	//CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CPlayerIDLE>::Create(m_tPlayerIDLE.x, m_tPlayerIDLE.y, m_fAngle), OBJID::PLAYER);
	Key_Check();
 
	
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_SPACE))
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CMisaleBullet>::Create(m_tPosin.x, m_tPosin.y, m_fAngle), OBJID::MISALE);
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_TAB))
    //CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CScrewBullet>::Create(m_pTarget), OBJID::BULLET); 
	CObjMgr::Get_Instance()->Add_Object(CAbstractFactory<CScrewBullet>::Create(m_tPosin.x, m_tPosin.y, m_fAngle), OBJID::MISALE);


 
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_fAngle += 5.f;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_fAngle -= 5.f;
 
    

	Update_Rect();

	
	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
	// 포신
	m_tPosin.x = (LONG)(m_tInfo.fX - cosf(m_fAngle * PI / 180.f) * m_fMisaleDis);
	m_tPosin.y = (LONG)(m_tInfo.fY + sinf(m_fAngle * PI / 180.f) * m_fMisaleDis);

	// 미사일
	m_tMisale.x = (LONG)(m_tInfo.fX - cosf(m_fMisaleDis * PI / 180.f) * m_fAngle);
	m_tMisale.y = (LONG)(m_tInfo.fY + sinf(m_fMisaleDis * PI / 180.f) * m_fAngle);

	// 스크류 미사일
	m_tScrew.x = (LONG)(m_tInfo.fX - cosf(m_fScrewDis * PI / 10.f) * m_fAngle);
	m_tScrew.y = (LONG)(m_tInfo.fY + sinf(m_fScrewDis * PI / 10.f) * m_fAngle);


 
	if (m_tRect.left <= 100 || m_tRect.right >= WINCX - 100)
		m_fSpeed *= 5.f;

    

}

void CPlayer::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom); 
	//MoveToEx(_DC, m_tRect.left, m_tRect.right, nullptr);
	MoveToEx(_DC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(_DC, m_tPosin.x,m_tPosin.y);

 

 
}

void CPlayer::Release()
{

}

void CPlayer::Key_Check()
{

 
 
}
 

 

 
 

 
