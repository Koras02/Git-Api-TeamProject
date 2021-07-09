#include "pch.h"
#include "LineMgr.h"
#include "Line.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
	:t(0)
{
	ZeroMemory(&m_tLeftLinePos, sizeof(LINEPOS));
	ZeroMemory(&m_tRightLinePos, sizeof(LINEPOS));
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	//LINEPOS tPos[4] = { {100.f,500.f},{300.f,500.f},{500.f,300.f} ,{700.f,300.f} };

	/*for (int i = 0; i < (sizeof(tPos) / sizeof(tPos[0])) - 1; ++i)
		m_listLine.emplace_back(new CLine(tPos[i], tPos[i + 1]));*/
}

void CLineMgr::Update()
{
	Key_Check();
}

void CLineMgr::Render(HDC _DC)
{
	for (auto& pLine : m_listLine)
		pLine->Render(_DC);
}

void CLineMgr::Release()
{
	for_each(m_listLine.begin(), m_listLine.end(), Safe_Delete<CLine*>);
	m_listLine.clear();
}

const size_t& CLineMgr::Get_LineSize()
{
	// TODO: 여기에 return 문을 삽입합니다.
	return m_listLine.size();
}

void CLineMgr::Key_Check()
{
	POINT pt{};
	

	if (m_tLeftLinePos.fX != 0 && m_tRightLinePos.fX != 0)
	{
		m_listLine.emplace_back(new CLine(m_tLeftLinePos, m_tRightLinePos));
		m_tLeftLinePos = {};
		m_tRightLinePos = {};
		Sleep(100);
	}

	if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000))
	{
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);
		if (m_tLeftLinePos.fX == 0)
		{
			m_tLeftLinePos.fX = (float)pt.x;
			m_tLeftLinePos.fY = (float)pt.y;
			pt = { 0,0 };
		}

	}
	else if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);
		if (m_tRightLinePos.fX == 0)
		{
			m_tRightLinePos.fX = (float)pt.x;
			m_tRightLinePos.fY = (float)pt.y;
			pt = { 0,0 };
		}

	}
	
}

bool CLineMgr::Collision_Line(float _x, float* _y)
{
	if (m_listLine.empty())
		return false;

	for (auto& pLine : m_listLine)
	{
		if (pLine->Get_Info().tLeftPos.fX <= _x &&
			pLine->Get_Info().tRightPos.fX > _x)
		{
			float x1 = pLine->Get_Info().tLeftPos.fX;
			float y1 = pLine->Get_Info().tLeftPos.fY;
			float x2 = pLine->Get_Info().tRightPos.fX;
			float y2 = pLine->Get_Info().tRightPos.fY;

			*_y = ((y2 - y1) / (x2 - x1)) * (_x - x1) + y1;
			//직선의 방정식
			return true;
		}
	}



	return false;
}
