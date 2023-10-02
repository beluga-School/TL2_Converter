#pragma once
#include <string>

enum Argument
{
	kApplicationPath,
	kFilePath,
	NumArgument,
};

class TextureConverter
{
public:
	void ConvertTextureWICToDDS(const std::string& filepath);

private:
	//テクスチャファイル読み込み
	void LoadWICTextureFromFile(const std::string& filepath);
};

