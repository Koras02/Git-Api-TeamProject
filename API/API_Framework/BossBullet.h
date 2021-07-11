#pragma once
#include "Obj.h"
class BossBullet : public CObj
{
public:
	BossBullet();
	virtual ~BossBullet();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};

