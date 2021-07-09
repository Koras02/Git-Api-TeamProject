#include "pch.h"
#include "Monster.h"
#include "ObjMgr.h"

CMonster::CMonster()
	
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;

	m_fSpeed = 2.f;

	m_pTarget = CObjMgr::Get_Instance()->Get_Player();
}

int CMonster::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	/*float x = m_pTarget->Get_Info().fX - m_tInfo.fX;
	float y = m_pTarget->Get_Info().fY - m_tInfo.fY;

	float _fDis = sqrtf((x * x) + (y * y));

	
	
	m_fAngle = acosf(x / _fDis);

	if (this->Get_Info().fY < m_pTarget->Get_Info().fY)
		m_fAngle = 2 * PI - m_fAngle;

	m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
	m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed;*/

	Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	//if (100 >= m_tRect.left || 100 >= m_tRect.top
	//	|| WINCX - 100 <= m_tRect.right || WINCY - 100 <= m_tRect.bottom)
	//	m_fSpeed *= -1.f;
	//

}

void CMonster::Render(HDC _DC)
{
	Rectangle(_DC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

}

void CMonster::Release()
{
}
