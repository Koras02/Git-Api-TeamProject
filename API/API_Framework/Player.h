#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Obj.h"
class CPlayer :
    public CObj
{
public:
    CPlayer();
    virtual ~CPlayer();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:
	void Key_Check();
	void Jumping();

private:
	template<typename T>
	CObj* Create_Bullet()
	{
		return CAbstractFactory<T>::Create((float)m_tPosin.x, (float)m_tPosin.y, m_fAngle);
	}
	CObj* Create_Shield();

private:

	POINT m_tPosin;
	float m_fPosinDis;

	bool m_bJump ;
	float m_fJumpPower;
	float m_fJumpTime;
	float m_fJumpY;



};


#endif // !__PLAYER_H__



