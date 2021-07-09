#pragma once

#ifndef __COLLISIONMGR_H__
#define __COLLISIONMGR_H__

class CObj;

class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void Collision_Rect(list<CObj*>& _Dst, list<CObj*>& _Src);
	static void Collision_Sphere(list<CObj*>& _Dst, list<CObj*>& _Src);
	static void Collision_RectEx(list<CObj*>& _Dst, list<CObj*>& _Src);

	static bool Check_Sphere(CObj* _pDst, CObj* _pSrc);
	static bool Check_Rect(CObj* _pDst, CObj* _pSrc , float* _x,float* _y);

};

#endif // !__COLLISION_H__



