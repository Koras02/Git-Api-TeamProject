#include "pch.h"
#include "LineMgr.h"
#include "Line.h"
#include "ScrollMgr.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
	:m_bCheck(true)
{
	ZeroMemory(m_tLinePos, sizeof(m_tLinePos));
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize()
{
	LINEPOS		tPos[4] = { {100.f, 500.f}, {300.f, 500.f}, {500.f, 300.f}, {700.f, 300.f} };

	m_listLine.emplace_back(new CLine(tPos[0], tPos[1]));
	m_listLine.emplace_back(new CLine(tPos[1], tPos[2]));
	m_listLine.emplace_back(new CLine(tPos[2], tPos[3]));
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

void CLineMgr::Add_Line()
{
	POINT pt = {};
	
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	if (m_bCheck)
	{
		m_tLinePos[0].fX = (float)pt.x;
		m_tLinePos[0].fY = (float)pt.y;
		m_bCheck = !m_bCheck;
	}
	else
	{
		m_tLinePos[1].fX = (float)pt.x;
		m_tLinePos[1].fY = (float)pt.y;

		m_listLine.emplace_back(new CLine(m_tLinePos[0], m_tLinePos[1]));

		//// ##1.
		//m_bCheck = !m_bCheck;

		// ##2.
		memcpy(m_tLinePos, m_tLinePos + 1, sizeof(LINEPOS));
	}
}

void CLineMgr::Save_Line()
{
	HANDLE hFile = CreateFile(L"../Data/Line.dat", GENERIC_WRITE,
		NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"저장 실패!", L"실패", MB_OK);
		return;
	}

	DWORD dwByte = 0;
	for (auto& pLine : m_listLine)
		WriteFile(hFile, &pLine->Get_Info(), sizeof(LINEINFO), &dwByte, NULL);

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"저장 성공!", L"성공", MB_OK);

}

void CLineMgr::Load_Line()
{
	HANDLE hFile = CreateFile(L"../Data/Line.dat", GENERIC_READ
		, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"불러오기 실패!", L"실패", MB_OK);
		return;
	}

	Release();

	LINEINFO	tTemp;
	DWORD		dwByte = 0;

	while (true)
	{
		ReadFile(hFile, &tTemp, sizeof(LINEINFO), &dwByte, NULL);

		if (0 == dwByte)
			break;

		m_listLine.emplace_back(new CLine(tTemp.tLeftPos, tTemp.tRightPos));
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"불러오기 성공!", L"성공", MB_OK);
}
