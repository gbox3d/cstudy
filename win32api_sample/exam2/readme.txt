�޴� ���ҽ� �ٷ��

int nResult = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, testProc);
switch (nResult)
{
				case IDOK:
					OutputDebugString(L"IDOK");
					break;
				case IDCANCEL:
					OutputDebugString(L"IDCANCEL");
					break;
				default:
					break;
}

DialogBox �Լ��� ���ŷ���� �����Ѵ�. â�� ������ dialogbox �Լ� �������� ����ȴ�.


INT_PTR CALLBACK testProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
		else if ((LOWORD(wParam) == IDC_BUTTON1) ) {
			static TCHAR szTemp[256];
			GetWindowText(GetDlgItem(hDlg, IDC_EDIT_TEST), szTemp,
				sizeof(szTemp) / sizeof(TCHAR));

			SetWindowText(GetDlgItem(hDlg, IDC_STATIC_TEST), szTemp);

		}
		break;
	}
	return (INT_PTR)FALSE;
}

EndDialog �Լ��� ȣ��Ǹ� â�� ������ �ι�° ���ڷ� �Ѱ��ذ��� DialogBox�� ���ϰ��� �ȴ�.


-��������
���̾�α׹ڽ��� �μ��� �Է¹޾� �θ������쿡�� ���� ���ϰ� ������� ��� �Ͻÿ�.



���� 
http://soen.kr