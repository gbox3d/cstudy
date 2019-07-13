﻿// exam1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "exam1.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_EXAM1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_EXAM1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   CreateWindow(L"static", L"이름을 입력하세요.", WS_CHILD | WS_VISIBLE,
	   0, 0, 150, 25,  //위치 
	   hWnd, (HMENU)-1, hInst, NULL);

   CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | CBS_AUTOHSCROLL | WS_BORDER,
	   0, 25, 100, 25, hWnd, (HMENU)3001, hInst, NULL
   );

   CreateWindow(L"static", L"나이를 입력하세요.", WS_CHILD | WS_VISIBLE,
	   0, 100, 150, 25, hWnd, (HMENU)-1, hInst, NULL);

   CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_AUTOHSCROLL,
	   0, 125, 100, 25, hWnd, (HMENU)3002, hInst, NULL);

   CreateWindow(L"static", L"너의 인생의무게를 입력하세요.", WS_CHILD | WS_VISIBLE,
	   0, 200, 280, 25, hWnd, (HMENU)-1, hInst, NULL);

   CreateWindow(L"edit", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_AUTOHSCROLL,
	   0, 225, 100, 25, hWnd, (HMENU)3003, hInst, NULL);

   CreateWindow(L"button", L"Ok", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   225, 25, 100, 25, hWnd, (HMENU)4001, hInst, NULL);

   CreateWindow(L"static", L"result......", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   0, 255, 256, 256, hWnd, (HMENU)4002, hInst, NULL);


   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
			case 4001:
			{
				static TCHAR szTemp[256];
				GetWindowText(GetDlgItem(hWnd, 3001), szTemp, 
					sizeof(szTemp) / sizeof(TCHAR));

				static TCHAR szName[256];
				lstrcpyW(szName, szTemp);
				
				int nAge;
				GetWindowText(GetDlgItem(hWnd, 3002), szTemp, sizeof(szTemp) / sizeof(TCHAR));
				nAge = _wtoi(szTemp);

				double fWeight;
				GetWindowText(GetDlgItem(hWnd, 3003), szTemp, sizeof(szTemp) / sizeof(TCHAR));
				fWeight = _wtof(szTemp);

				HDC hdc = GetDC(hWnd);
				TCHAR szBuf[256];
				swprintf_s(szBuf, sizeof(szBuf)/sizeof(TCHAR), L"당신의 이름은 %s 입니다. 나이는 %d살입니다. %lfkg", szName, nAge,fWeight);
				TextOut(hdc, 225, 150, szBuf, wcslen(szBuf));
				
				SetWindowText(GetDlgItem(hWnd, 4002),szBuf);

				OutputDebugString(szBuf);

				ReleaseDC(hWnd, hdc);

			}

				break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
