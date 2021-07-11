#pragma once

#ifndef __OBJMGR_H__
#define __OBJMGR_H__

class CObj;
class CObjMgr 
{
private:
    CObjMgr();
    ~CObjMgr();

public:
	void Add_Object(CObj* _pObj, OBJID::ID _eID);
	void Update();
	void Late_Update();
	void Render(HDC _DC);
	void Release();

public:
	CObj* Get_Player() { return m_listObj[OBJID::PLAYER].front(); }
	CObj* Get_Target(CObj* _pObj, OBJID::ID _eID);
	size_t Get_MonsterSize() { return m_listObj[OBJID::MONSTER].size(); }
public:
	size_t Get_BulletSize() { return m_listObj[OBJID::BULLET].size(); }

public:
	static CObjMgr* Get_Instance()
	{
		if (!m_pInstance)
			m_pInstance = new CObjMgr;
		return m_pInstance;
	}
	static void Destroy_Instance()
	{
		SAFE_DELETE(m_pInstance);
	}

private:
	static CObjMgr* m_pInstance;

	list<CObj*>		m_listObj[OBJID::END];
};

#endif // !__OBJMGR_H__



