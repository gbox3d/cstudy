#include "framework.h"
#include "gameMain.h"

BYTE g_KeyTable[1024] = {0};

void OnKeyDown(WORD wKeycode)
{
	g_KeyTable[wKeycode] = 1;

}

void OnKeyUp(WORD wKeycode)
{
	g_KeyTable[wKeycode] = 0;

}

void OnGdiplusSetup()
{	

}

void OnGdiplusFinish()
{
}

void OnGdiplusApply(double fDelta)
{
}


void OnGdiplusRender(double fDelta, Graphics *pGrp)
{

	//pGrp->Clear(Color(200, 200, 200));

	Pen      pen(Gdiplus::Color(rand() % 256, rand() % 256, rand() % 256));
	pGrp->DrawLine(&pen, rand() % 512, rand() % 512, rand() % 512, rand() % 512);
	
	pen.SetColor(Gdiplus::Color(rand() % 256, rand() % 256, rand() % 256));
	pGrp->DrawEllipse(&pen, rand()%512, rand() % 512, rand() % 512, rand() % 512);

	pen.SetColor(Gdiplus::Color(rand() % 256, rand() % 256, rand() % 256));
	pGrp->DrawRectangle(&pen, Rect(rand() % 512, rand() % 512, rand() % 512, rand() % 512));

	SolidBrush brush(Color(rand() % 256, rand() % 256, rand() % 256));
	pGrp->FillEllipse(&brush, rand() % 512, rand() % 512, rand() % 512, rand() % 512);

	

}