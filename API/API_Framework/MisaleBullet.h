#pragma once

#ifndef __MISALE_H__
#define __MISALE_H__

#include "Obj.h"
class CMisaleBullet : public CObj
{
public:
	CMisaleBullet();
	virtual ~CMisaleBullet();


public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:
	POINT  m_tCenterMis;
	float m_fCenterAngle;
	float m_fCenterSpeed;
	

	bool m_bStart;


};

#endif