//#include "stdafx.h"
#include "./irrlicht/include/irrlicht.h"
#include "plusEngine.h"

namespace plusEngine {
	//gdi plus �ʱ�ȭ �ڵ� 
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	HDC hDc = NULL;

	void startUpGdiPlus()
	{
		//----------------------------------------------------------------------
		// Initialize GDI+.
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		//----------------------------------------------------------------


	}
	void CloseGdiPlus()
	{
		//--------------------------------------
		//gdi plus �����ڵ� 
		GdiplusShutdown(gdiplusToken);
		//--------------------------------------
	}

	void printf(Graphics* grp, Font& font, Pen& pen, Brush& brush, int x, int y, TCHAR* fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);
		grp->DrawString(szBuf, -1, &font, PointF((Gdiplus::REAL)x, (Gdiplus::REAL)y), &brush);
		va_end(ap);
	}

	void printf(Graphics* grp, int x, int y, const TCHAR* fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);
		static TCHAR szBuf[1024];
		vswprintf_s(szBuf, 1024, fmt, ap);

		Pen pen(Color(255, 0, 0));
		Gdiplus::SolidBrush brushBlack(Color(0, 0, 0));
		FontFamily  fontFamily(L"����");
		Font        font(&fontFamily, 12, FontStyleRegular, UnitPixel);
		grp->DrawString(szBuf, -1, &font, PointF((Gdiplus::REAL)x, (Gdiplus::REAL)y), &brushBlack);

		va_end(ap);
	}


	//DWORD WINAPI ThreadFunc(LPVOID temp)
	void(*fpOnSetup)();
	void(*fpOnFinish)();
	void (*fpOnLoop)(double);
	void(*fpOnRender)(double, Graphics*);

	void GDIPLUS_Loop(MSG& msg, Gdiplus::Rect rectScreen,
		void(*_fpOnSetup)(),
		void(*_fpOnLoop)(double),
		void(*_fpOnRender)(double, Graphics*),
		void(*_fpOnFinish)()
	)
	{
		//----------------------------------------------------------------------
		//gdi plus �ʱ�ȭ �ڵ� 
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR           gdiplusToken;

		fpOnSetup = _fpOnSetup;
		fpOnLoop = _fpOnLoop;
		fpOnRender = _fpOnRender;
		fpOnFinish = _fpOnFinish;

		// Initialize GDI+.
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
		//-----------------------------------------------------------------------


		{
			bool quit = false;
			//gdiplus �� �˴ٿ� �Ǳ����� ��ü���� �����Ǿ�� �ϹǷ� �Ϻη� �������������� �Ѵܰ� ������ ����ߴ�.			
			Bitmap bmpMem(rectScreen.Width, rectScreen.Height);
			Graphics* pBackScreen = Graphics::FromImage(&bmpMem);

			if (fpOnSetup != NULL) {
				fpOnSetup();
			}

			static int nStep = 0;
			while (!quit) {
				switch (nStep) {
				case 0:
					hDc = GetDC(msg.hwnd);
					if(hDc) nStep = 10;
					
					break;
				case 10:
				{
					

				}
				break;
				}

				if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
						quit = true;

					TranslateMessage(&msg);
					DispatchMessage(&msg);

				}
				else {
					static LONG prev_tick;
					SYSTEMTIME time;
					GetSystemTime(&time);
					LONG time_ms = (time.wSecond * 1000) + time.wMilliseconds;
					double fDelta = (time_ms - prev_tick) / 1000.;

					//����
					if (fpOnLoop) {
						fpOnLoop(fDelta);
					}

					if (hDc) {
						Graphics graphics(hDc);

						//���� 
						if (fpOnRender) {
							fpOnRender(fDelta, pBackScreen);
						}

						graphics.DrawImage(&bmpMem, rectScreen);

					}




					prev_tick = time_ms;
				}


			}

			if (hDc) ReleaseDC(msg.hwnd, hDc);

			if (fpOnFinish) {
				fpOnFinish();
			}
		}

		//--------------------------------------
		//gdi plus �����ڵ� 
		GdiplusShutdown(gdiplusToken);
		//--------------------------------------
	}

	void GDIPLUS_Loop(MSG& msg, Gdiplus::Rect rectScreen)
	{
		GDIPLUS_Loop(msg, rectScreen, NULL, NULL, NULL, NULL);
	}

	void updateDC(HWND hWnd) {
		hDc = GetDC(hWnd);
	}


}