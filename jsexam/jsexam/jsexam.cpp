// jsexam.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"

#include "../../ducktape/src/duktape.h"



int main()
{
	duk_context *ctx = duk_create_heap_default();
	duk_eval_string(ctx, "1+2");
	printf("1+2=%d\n", (int)duk_get_int(ctx, -1));
	duk_destroy_heap(ctx);
    return 0;
}

