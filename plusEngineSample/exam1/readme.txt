

winmain �Լ����� �޽��� ���� �ڵ庯�� 

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_EXAM1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���ø����̼� �ʱ�ȭ�� �����մϴ�:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_EXAM1));

    MSG msg;

	////////////////////////   �ڵ� ���� 
	plusEngine::GDIPLUS_Loop(msg, Rect(0, 0, 320, 240), OnGdiplusSetup, OnGdiplusApply, OnGdiplusRender, OnGdiplusFinish);


    return (int) msg.wParam;
}


InitInstance ���� ������ hdc �¾�

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

////////////////////<< �ڵ� �߰� 
   //ȭ�� �̵�
   MoveWindow(hWnd, 0, 0, 512, 512, true);
//>>///////////////////////////////   

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   
////////////////////<< �ڵ� �߰�
   //�¾�
   plusEngine::updateDC(hWnd);
// >>///////////////////////////////   


   return TRUE;
}
