#include <cstdio>
#include <cstdlib>
#include <stdint.h>
#include <DirectXTex.h>
#include "TextureConverter.h"
#include "StringUtil.h"

int  main(int argc,char* argv[]) 
{
	if (argc < NumArgument) {
		TextureConverter::OutputUsage();
		return 0;
	}

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	int numoptions = argc - NumArgument;
	char** options = argv + NumArgument;

	TextureConverter converter;
	converter.ConvertTextureWICToDDS(argv[kFilePath], numoptions, options);

	//COMライブラリの終了
	CoUninitialize();

	return 0;
}