#pragma once
#include <string>
#include <DirectXTex.h>

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
	//DDSテクスチャとしてファイル書き出し
	void SaveDDSTextureToFile();

	DirectX::TexMetadata mMetadata;

	DirectX::ScratchImage mScratchImage;

	//ディレクトリパス格納変数
	std::wstring mDirectoryPath;
	//ファイルパス格納変数
	std::wstring mFileName;
	//ファイル拡張子格納変数
	std::wstring mFileExt;
};

