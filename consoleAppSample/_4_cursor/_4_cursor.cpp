// _4_cursor.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	COORD _pos;

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	_pos.X = 10;
	_pos.Y = 10;
	SetConsoleCursorPosition(hStdout, _pos);

	printf_s("cmd >");
	char _szBuf[32];
	gets_s(_szBuf, 32);
	printf_s("%s",_szBuf);

	_pos.X = 0;
	_pos.Y = 0;
	SetConsoleCursorPosition(hStdout, _pos);

    return 0;
}

