

static ,edit button control ����


��Ʈ�ѿ��� ������ �о����
int nAge;
GetWindowText(GetDlgItem(hWnd, 3002), szTemp, sizeof(szTemp) / sizeof(TCHAR));
nAge = _wtoi(szTemp);

GetWindowText �� ù��° ���ڴ� ���� ���� ���� �������� �ڵ��̴�.
GetDlgItem ���� 3002�� ��Ʈ���� �������ڵ��� �����´�.
�׸��� ���� ���ڷ� ���۸� �Ѱ��־� ������ �޾ƿ´�.

�ݴ�� ��Ʈ�ѷ� ���� �ʹٸ� setwindowtext�� ����Ѵ�.
SetWindowText(GetDlgItem(hWnd, 4002),szBuf);

-��������
�μ��� �Է¹޾� ��Ģ������ �����϶�



����
http://soen.kr/lecture/win32api/lec7/lec7-1-1.htm
