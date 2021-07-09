#pragma once

#ifndef _MOUSE_H__
#define _MOUSE_H__

#include "Obj.h"
class CMouse :
    public CObj
{
public:
    CMouse();
    virtual ~CMouse();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC _DC) override;
	virtual void Release() override;

private:
	void Key_Check();

private:
	POINT m_tMousePos;

};


#endif // !_MOUSE_H__


