#pragma once

#ifndef __MAINEDIT_H__
#define __MAINEDIT_H__

class CMainEdit
{
public:
	CMainEdit();
	~CMainEdit();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();

private:
	HDC		m_hDC;
};

#endif // !__MAINEDIT_H__




