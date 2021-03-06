// _1_console_input.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int oldmain(VOID);

void InputTest()
{

	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];

	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &fdwSaveOldMode);
	
	/*
	Step-1:
	Disable 'Quick Edit Mode' option
	*/
	fdwMode = ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(hStdin, fdwMode);
	
	// Enable the window and mouse input events. 

	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin, fdwMode);

	while (1) {
		ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead);

		for (i = 0; i < cNumRead; i++)
		{
			switch (irInBuf[i].EventType)
			{
			case KEY_EVENT: // keyboard input 
			{
				PKEY_EVENT_RECORD pker = &irInBuf[i].Event.KeyEvent;
				printf_s("Key event: ");

				if (pker->bKeyDown) {
					printf_s("key pressed %d \n", pker->wVirtualKeyCode);
				}
				else {
					printf_s("key released %d \n", pker->wVirtualKeyCode);
				}

			}
				
				break;

			case MOUSE_EVENT: // mouse input 
				
				break;

			case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
				break;
			
			default:
				break;
			}
		}
	}

	SetConsoleMode(hStdin, fdwSaveOldMode);
}

int main()
{

	//oldmain();
	InputTest();

	/*
	char szBuf[32];

	while (1) {
		gets_s(szBuf, sizeof(szBuf));

		if (strcmp("quit", szBuf) == 0) break;
		else {
			printf_s("'%s' is not command \n", szBuf);
		}
			
	}*/
}



