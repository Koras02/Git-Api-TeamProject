#pragma once

#ifndef __MONSTER_H__
#define __MONSTER_H__


#include "Obj.h"
class CMonster :
    public CObj
{
public:
	CMonster();
	virtual ~CMonster();


public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:

	POINT m_tPosin;

};

#endif // !__MONSTER_H__


