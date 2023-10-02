#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <DirectXTex.h>

int  main(int argc,char* argv[]) {
	
	for (int32_t i = 0; i < argc; i++)
	{
		printf(argv[i]);
		printf("\n");
	}

	system("pause");

	return 0;
}