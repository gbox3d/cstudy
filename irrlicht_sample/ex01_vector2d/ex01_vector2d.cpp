// ex01_vector2d.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../engine/irrlicht/include/irrlicht.h"

int main()
{
	irr::core::vector2df test;
	test = irr::core::vector2df(10, 0);

	printf_s("원본 : %lf %lf \n", test.X, test.Y);

	test.normalize();
	printf_s("정규화 : %lf %lf \n", test.X, test.Y);

	test.rotateBy(45);
	printf_s("회전 : %lf %lf \n", test.X, test.Y);

	printf_s("getAngle : %lf \n", test.getAngle());
	printf_s("getAngleTrig : %lf \n", test.getAngleTrig());
	//printf_s("getAngleTrig : %lf \n", test.getAngleWith());

	irr::core::vector2df _a, _b,_c;
	_a = irr::core::vector2df(0, 0);
	_b = irr::core::vector2df(1, 1);

	_c = _a.getInterpolated(_b, 0.5f);

	printf_s("getInterpolated , (0,0)->(1,1) 0.5 : %lf %lf \n", _c.X, _c.Y);


	printf_s("a->b length %lf \n",(_b-_a).getLength() );
	

	return 0;
}

