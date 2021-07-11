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
	RECT rec[10];
	RECT _rec;

};

