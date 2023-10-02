#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <DirectXTex.h>
#include "TextureConverter.h"

int  main(int argc,char* argv[]) 
{
	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	//assert(argc >= NumArgument);

	TextureConverter converter;
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");

	return 0;
}