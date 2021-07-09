#include "pch.h"
#include "Line.h"

CLine::CLine()
{
}

CLine::CLine(LINEPOS& _tLeftPos, LINEPOS& _tRightPos)
	:m_tInfo(_tLeftPos,_tRightPos)
{
}

CLine::~CLine()
{
	Release();
}

void CLine::Initialize()
{
}

void CLine::Render(HDC _DC)
{
	MoveToEx(_DC, (int)m_tInfo.tLeftPos.fX, (int)m_tInfo.tLeftPos.fY, nullptr);
	LineTo(_DC, (int)m_tInfo.tRightPos.fX, (int)m_tInfo.tRightPos.fY);
}

void CLine::Release()
{
}
