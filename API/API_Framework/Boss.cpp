#include "pch.h"
#include "Boss.h"

CBoss::CBoss()
	: Leg1(270), Leg2(380), Leg3(490)
{
}

CBoss::~CBoss()
{
}

void CBoss::Initialize()
{
	for (int i = 0; i < 10; ++i)
	{
		rec[i].left = (i * 60) + 100;
		rec[i].right = ((i+1) * 60) + 100;
		rec[i].top = 0;
		rec[i].bottom = 25;
	}
}

int CBoss::Update()
{
	if (Leg1 >= 310)
		Leg1 -= 0.1f;
	else if (Leg1 <= 270)
		Leg1 += 0.1f;
	Leg2 = 380;
	Leg3 = 490;

	Update_Rect();
	return OBJ_NOEVENT;
}

void CBoss::Late_Update()
{
	Leg2 = 410;
	Leg3 = 530;
}

void CBoss::Render(HDC _DC)
{
	MoveToEx(_DC, 400, 50, nullptr);
	LineTo(_DC, 350, 100);
	LineTo(_DC, 450, 100);
	LineTo(_DC, 400, 50);
	MoveToEx(_DC, 350, 100, nullptr);
	LineTo(_DC, 320, 200);
	LineTo(_DC, 480, 200);
	LineTo(_DC, 450, 100);
	Ellipse(_DC, 360, 110, 380, 150);
	Ellipse(_DC, 420, 110, 440, 150);
	MoveToEx(_DC, 400, 150, nullptr);
	LineTo(_DC, 400, 180);
	MoveToEx(_DC, 300, 200, nullptr);
	LineTo(_DC, 500, 200);
	LineTo(_DC, 510, 210);
	LineTo(_DC, 290, 210);
	LineTo(_DC, 300, 200);
	MoveToEx(_DC, 290, 210, nullptr);
	LineTo(_DC, Leg1, 250);
	MoveToEx(_DC, 400, 210, nullptr);
	LineTo(_DC, Leg2, 250);
	MoveToEx(_DC, 510, 210, nullptr);
	LineTo(_DC, Leg3, 250);

	for (int i = 0; i < 10; ++i)
	{
		Rectangle(_DC, rec[i].left, rec[i].top, rec[i].right, rec[i].bottom);
	}

}

void CBoss::Release()
{
}
