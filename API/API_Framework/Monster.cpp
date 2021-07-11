#include "pch.h"
#include "Monster.h"
#include "ObjMgr.h"
#include "ScrollMgr.h"

CMonster::CMonster()
	:m_fOriginfX(0.f),m_fOriginfY(0.f), m_fAngleSpeed(0.f),m_fPosinAngle(0.f), _dwWord(0)
{
	ZeroMemory(&m_tPosin, sizeof(m_tPosin));
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(-3, 3);
	uniform_real_distribution<float> dis1(-2000, 2000);
	uniform_real_distribution<float> dis2(-2, 2);
	uniform_real_distribution<float> dis3(-1, 1);
	m_tInfo.iCX = 50;
	m_tInfo.iCY = 50;
	m_fSpeed = 1.f;
	m_fAngleSpeed = dis(gen);

	m_pTarget = CObjMgr::Get_Instance()->Get_Player();
	m_fOriginfX = m_pTarget->Get_Info().fX ;
	m_fOriginfY = m_pTarget->Get_Info().fY ;

	float fRandomTemp = dis1(gen);

	if (abs(fRandomTemp) < 500 && fRandomTemp > 0)
		m_fDis = fRandomTemp + 500;
	else if (abs(fRandomTemp < 500 && fRandomTemp < 0))
		m_fDis = fRandomTemp - 500;
	else
		m_fDis = fRandomTemp;
	
	if (abs(m_fDis) > 500 && abs(m_fDis) < 1000)
		m_fAngleSpeed /= 3.f;
	else if (abs(m_fDis) > 1000 && abs(m_fDis) < 1500)
		m_fAngleSpeed /= 6.f;
	else if (abs(m_fDis) > 1500 && abs(m_fDis) < 2000)
		m_fAngleSpeed /= 12.f;
	else if (abs(m_fDis) > 2000 && abs(m_fDis) < 2500)
		m_fAngleSpeed /= 18.f;

	/*for(int i = 0 ; i < 10 ; ++i)
		for(int j = 500 ; j < 2000 ; j += 100)
			if(abs(m_fDis) > j && abs(m_fDis) < j + 100)
				m_fAngleSpeed*/


}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	m_fAngle += m_fAngleSpeed;
	if (m_fAngle >= 360.f)
		m_fAngle -= 360.f;
	else if (m_fAngle <= -360.f)
		m_fAngle += 360.f;
	

	int iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	
		m_tInfo.fX = m_fOriginfX - iScrollX;
		m_tInfo.fY = m_fOriginfY - iScrollY;
		//
		m_tInfo.fX += cosf(m_fAngle * PI / 180.f) * m_fSpeed * m_fDis;
		m_tInfo.fY -= sinf(m_fAngle * PI / 180.f) * m_fSpeed * m_fDis;
		// 
		
	



	Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	float x = m_pTarget->Get_Info().fX - m_tInfo.fX;
	float y = m_pTarget->Get_Info().fY - m_tInfo.fY;
	float diff = sqrtf(x * x + y * y);
	float fRad = acosf(x / diff); // 0 ~ 파이 사이값

	m_fPosinAngle = fRad * 180.f / PI;

	if (m_pTarget->Get_Info().fY >= m_tInfo.fY)
		m_fPosinAngle *= -1.f;

	m_tPosin.x = (LONG)(m_tInfo.fX + cosf(m_fPosinAngle * PI / 180.f) * 50);
	m_tPosin.y = (LONG)(m_tInfo.fY - sinf(m_fPosinAngle * PI / 180.f) * 50);
}

void CMonster::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	MoveToEx(_DC, (int)m_tInfo.fX, (int)m_tInfo.fY, nullptr);
	LineTo(_DC, m_tPosin.x, m_tPosin.y);
}

void CMonster::Release()
{
}
