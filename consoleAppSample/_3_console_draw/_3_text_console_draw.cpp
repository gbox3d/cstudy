// _3_text_console_draw.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <windows.h> 
#include <stdio.h>

const int g_cScreenBufSize = 2000; //25*80

int main(void)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	CHAR_INFO chiBuffer[g_cScreenBufSize]; 

	for (int i = 0; i < g_cScreenBufSize/2; i++) {

		//유니코드에서 속성적용 
		//첫번째 바이트는 캐릭터의 좌우 선택 1->left , 2->right
		//두번째 바이트가 컬러속성,컬러 체계는 8421 -> IRGB 
		chiBuffer[i * 2].Char.UnicodeChar = 0x25ce;//TEXT('◎');
		chiBuffer[i*2].Attributes = COMMON_LVB_LEADING_BYTE  | 0x009f; //첫번째 왼쪽표시
		chiBuffer[i*2 + 1].Char.UnicodeChar = 0x25ce; //TEXT('◎');
		chiBuffer[i*2 + 1].Attributes = COMMON_LVB_TRAILING_BYTE  | 0x009f; //나머지 반절표시 

	}

	COORD coordBufSize;
	COORD coordBufCoord;
	SMALL_RECT destRect;

	//메모리 버퍼의 크기와 위치지정
	// The top left destination cell of the temporary buffer is 
	// row 0, col 0. 
	coordBufCoord.X = 0;
	coordBufCoord.Y = 0;

	// The temporary buffer size is 2 rows x 80 columns. 
	coordBufSize.X = 80;
	coordBufSize.Y = 25;
	
	//최종적으로 스크린 버퍼가 출력될 위치지정
	destRect.Top = 2;    // top lt: row 10, col 0 
	destRect.Left = 2;
	destRect.Bottom = (destRect.Top + coordBufSize.Y) - 1; // bot. rt: row 11, col 79 
	destRect.Right = (destRect.Left + coordBufSize.X) - 1;


	WriteConsoleOutput(
		hStdout, // screen buffer to write to 
		chiBuffer,        // buffer to copy from 
		coordBufSize,     // col-row size of chiBuffer {80,25} 이런식으로도 줘도 된다. 
		coordBufCoord,    // top left src cell in chiBuffer 
		&destRect);  // dest. screen buffer rectangle 

}


/*
int main(void)
{
	HANDLE hStdout, hNewScreenBuffer;
	SMALL_RECT srctReadRect;
	SMALL_RECT srctWriteRect;
	CHAR_INFO chiBuffer[160]; // [2][80]; 
	COORD coordBufSize;
	COORD coordBufCoord;
	BOOL fSuccess;

	// Get a handle to the STDOUT screen buffer to copy from and 
	// create a new screen buffer to copy to. 

	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hNewScreenBuffer = CreateConsoleScreenBuffer(
		GENERIC_READ |           // read/write access 
		GENERIC_WRITE,
		FILE_SHARE_READ |
		FILE_SHARE_WRITE,        // shared 
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);                   // reserved; must be NULL 
	if (hStdout == INVALID_HANDLE_VALUE ||
		hNewScreenBuffer == INVALID_HANDLE_VALUE)
	{
		printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	// Make the new screen buffer the active screen buffer. 

	if (!SetConsoleActiveScreenBuffer(hNewScreenBuffer))
	{
		printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	// Set the source rectangle. 

	srctReadRect.Top = 0;    // top left: row 0, col 0 
	srctReadRect.Left = 0;
	srctReadRect.Bottom = 1; // bot. right: row 1, col 79 
	srctReadRect.Right = 79;

	// The temporary buffer size is 2 rows x 80 columns. 

	coordBufSize.Y = 2;
	coordBufSize.X = 80;

	// The top left destination cell of the temporary buffer is 
	// row 0, col 0. 

	coordBufCoord.X = 0;
	coordBufCoord.Y = 0;

	// Copy the block from the screen buffer to the temp. buffer. 

	fSuccess = ReadConsoleOutput(
		hStdout,        // screen buffer to read from 
		chiBuffer,      // buffer to copy into 
		coordBufSize,   // col-row size of chiBuffer 
		coordBufCoord,  // top left dest. cell in chiBuffer 
		&srctReadRect); // screen buffer source rectangle 
	if (!fSuccess)
	{
		printf("ReadConsoleOutput failed - (%d)\n", GetLastError());
		return 1;
	}

	//유니코드에서 속성적용 
	//첫번째 바이트는 캐릭터의 좌우 선택 1->left , 2->right
	//두번째 바이트가 컬러속성,컬러 체계는 8421 -> IRGB 
	chiBuffer[0].Char.UnicodeChar = TEXT('◎');
	chiBuffer[0].Attributes = 0x019e; //첫번째 왼쪽표시
	chiBuffer[1].Char.UnicodeChar = TEXT('◎');
	chiBuffer[1].Attributes = 0x029e; //나머지 반절표시 

	chiBuffer[2].Char.UnicodeChar = TEXT('◎');
	
	// Set the destination rectangle. 

	srctWriteRect.Top = 10;    // top lt: row 10, col 0 
	srctWriteRect.Left = 0;
	srctWriteRect.Bottom = 11; // bot. rt: row 11, col 79 
	srctWriteRect.Right = 79;

	// Copy from the temporary buffer to the new screen buffer. 

	fSuccess = WriteConsoleOutput(
		hNewScreenBuffer, // screen buffer to write to 
		chiBuffer,        // buffer to copy from 
		coordBufSize,     // col-row size of chiBuffer 
		coordBufCoord,    // top left src cell in chiBuffer 
		&srctWriteRect);  // dest. screen buffer rectangle 
	if (!fSuccess)
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
		return 1;
	}
	Sleep(5000);

	// Restore the original active screen buffer. 

	if (!SetConsoleActiveScreenBuffer(hStdout))
	{
		printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
		return 1;
	}

	return 0;
}

*/