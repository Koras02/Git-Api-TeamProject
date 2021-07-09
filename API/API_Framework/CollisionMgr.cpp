#include "pch.h"
#include "CollisionMgr.h"
#include "Obj.h"

CCollisionMgr::CCollisionMgr()
{
}

CCollisionMgr::~CCollisionMgr()
{
}

void CCollisionMgr::Collision_Rect(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	RECT rc{};

	for (auto& pDst : _Dst)
	{
		for (auto& pSrc : _Src)
		{
			//if (IntersectRect(&rc, &pDst->Get_Rect(), &pSrc->Get_Rect()))
			if (IntersectRect(&rc,&pDst->Get_Rect(),&pSrc->Get_Rect()))
			{
				pDst->Set_Dead();
				pSrc->Set_Dead();
			}
		}
	}

}

void CCollisionMgr::Collision_Sphere(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	for (auto& pDst : _Dst)
	{
		for (auto& pSrc : _Src)
		{
			if (Check_Sphere(pDst,pSrc))
			{
				pDst->Set_Dead();
				pSrc->Set_Dead();
			}
		}
	}
}

void CCollisionMgr::Collision_RectEx(list<CObj*>& _Dst, list<CObj*>& _Src)
{
	float fX = 0.f;
	float fY = 0.f;

	for (auto& pDst : _Dst)
	{
		for (auto& pSrc : _Src)
		{
			if (Check_Rect(pDst, pSrc, &fX, &fY))
			{
				if (fX < fY)  //�¿� �浹�簢���� ���ΰ��� ��� ���� �¿��浹
				{
					if (pDst->Get_Info().fX < pSrc->Get_Info().fX)
						pSrc->Set_PosX(fX);
					else
						pSrc->Set_PosX(-fX);
				}
				else //�����浹 ���ΰ� ����Ƿ� ���η� �浹����
				{
					if (pDst->Get_Info().fY < pSrc->Get_Info().fY)
						pSrc->Set_PosY(fY);
					else
						pSrc->Set_PosY(-fY);
				}
			}
		}
	}
}

bool CCollisionMgr::Check_Sphere(CObj* _pDst, CObj* _pSrc)
{
	float fX = abs(_pDst->Get_Info().fX - _pSrc->Get_Info().fX);
	float fY = abs(_pDst->Get_Info().fY - _pSrc->Get_Info().fY);
	float fDia = sqrtf((fX * fX) + (fY * fY)); 
	// �ο��� �߽� ���̰Ÿ�

	float fSumRad = (float)((_pDst->Get_Info().iCX + _pSrc->Get_Info().iCX) >> 1 );
	// �ο��� ������ �Ÿ�

	if (fSumRad >= fDia)
		return true;
	return false;
}

bool CCollisionMgr::Check_Rect(CObj* _pDst, CObj* _pSrc,float* _x, float* _y)
{
	float fSumRadX = (float)((_pDst->Get_Info().iCX + _pSrc->Get_Info().iCX) >> 1);
	float fSumRadY = (float)((_pDst->Get_Info().iCY + _pSrc->Get_Info().iCY) >> 1);
	//������ ���̰Ÿ�

	float fDisX = abs(_pDst->Get_Info().fX - _pSrc->Get_Info().fX);
	float fDisY = abs(_pDst->Get_Info().fY - _pSrc->Get_Info().fY);
	//�������̰Ÿ�

	if (fSumRadX > fDisX && fSumRadY > fDisY)
	{ //�������̺��� �������� ��ũ�� �浹����
		*_x = fSumRadX - fDisX;
		*_y = fSumRadY - fDisY;
		return true;
	}

	return false;
}
