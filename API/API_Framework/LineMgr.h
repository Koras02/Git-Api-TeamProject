#pragma once

#ifndef __LINEMGR_H__
#define __LINEMGR_H__

class CLine;
class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	void Initialize();
	void Update();
	void Render(HDC _DC);
	void Release();
	const size_t& Get_LineSize();
	void Key_Check();
public:
	bool Collision_Line(float _x, float* _y);

public:
	static CLineMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CLineMgr;
		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		SAFE_DELETE(m_pInstance);
	}

private:
	static CLineMgr* m_pInstance;
	list<CLine*>	m_listLine;
	LINEPOS		m_tLeftLinePos;
	LINEPOS		m_tRightLinePos;
	int t;

};

#endif // !__LINEMGR_H__



