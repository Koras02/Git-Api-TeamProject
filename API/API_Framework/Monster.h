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
	float m_fOriginfX;
	float m_fOriginfY;
	float m_fAngleSpeed;

	POINT m_tPosin;
	float m_fPosinAngle;

private:
	DWORD _dwWord;

};

#endif // !__MONSTER_H__


