#pragma once
#include "Obj.h"
class CBoss : public CObj
{
public:
	CBoss();
	virtual ~CBoss();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:

	int Leg1;
	int Leg2;
	int Leg3;
	float fSpeed;
	float fSpeed1;
	int iMaxHp;
	bool LegMove;
	DWORD _dwTime1;
	DWORD _dwTime2;
	DWORD _dwTime3;
	DWORD _dwTime4;
	RECT rec[10];
	RECT Collision_Rec;
private:
	template <typename T>
	CObj* Create_Bullet(float x, float y)
	{
		return CAbstractFactory<T>::Create(x, y);
	}
};

