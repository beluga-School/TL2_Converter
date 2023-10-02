#include "TextureConverter.h"
#include "StringUtil.h"

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//ファイルパスを変換
	std::wstring wFilePath = ConvertStringToWChar(filepath);

	//テクスチャ読み込み
}
