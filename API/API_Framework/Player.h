#pragma once

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Obj.h"
class CPlayerIDLE;
class CPlayer:public CObj
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
 
	
private:

	POINT m_tPosin;
	float m_fPosinDis;

	POINT m_tMisale;
	float m_fMisaleDis;

	POINT m_tPlayerIDLE;
	float m_fPlayerIDLEDIS;
     
	POINT m_tScrew;
	float m_fScrewDis;
 

private:
	int Leg1;
	int Leg2;
	
	RECT rec[10];
	RECT _rec;
 

	CPlayerIDLE*  m_pPlayerIDLE;


};


#endif // !__PLAYER_H__



