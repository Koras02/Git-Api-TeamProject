#pragma once
#include "Obj.h"
class BossBullet1 : public CObj
{
public:
	BossBullet1();
	virtual ~BossBullet1();
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;
};
