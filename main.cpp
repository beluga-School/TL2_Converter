#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <DirectXTex.h>
#include "TextureConverter.h"

int  main(int argc,char* argv[]) 
{
	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//assert(argc >= NumArgument);

	TextureConverter converter;
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");

	return 0;
}