// ex1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "../../engine/tge.h"

int main()
{
	
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	TGE::clearScreenBuffer(TGE::g_chiBuffer, 0x0020,0x009f);

	//https://ko.wikipedia.org/wiki/%EC%9C%A0%EB%8B%88%EC%BD%94%EB%93%9C_2000~2FFF
	/*TGE::g_chiBuffer[0].Char.UnicodeChar = 0x2665; //하트모양 
	TGE::g_chiBuffer[0].Attributes = COMMON_LVB_LEADING_BYTE | 0x00fc; 

	TGE::g_chiBuffer[1].Char.UnicodeChar = 0x2665;
	TGE::g_chiBuffer[1].Attributes = COMMON_LVB_TRAILING_BYTE | 0x00fc;
	*/
	TGE::setCharacterW(TGE::g_chiBuffer, 0, 0, 0x2663, 0x00fc);
	TGE::setCharacterW(TGE::g_chiBuffer, 4, 0, 0x2665, 0x00fc);

	//TGE::setCharacter(, 2, 0, TEXT('A'), 0x00fc);
    //std::cout << "Hello tge!\n";

	TGE::updateBuffer(hStdout,TGE::g_chiBuffer);
	return 0;
}
