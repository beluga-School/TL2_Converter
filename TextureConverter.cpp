#include "TextureConverter.h"
#include "StringUtil.h"

using namespace DirectX;

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	LoadWICTextureFromFile(filepath);

	SaveDDSTextureToFile();
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filepath)
{
	//ファイルパスを変換
	std::wstring wFilePath = ConvertStringToWChar(filepath);

	//テクスチャ読み込み
	HRESULT result;
	result = LoadFromWICFile(wFilePath.c_str(),WIC_FLAGS_NONE,&mMetadata,mScratchImage);
	assert(SUCCEEDED(result));

	//ファイルパスを分割
	std::vector<std::string>  splitFilePaths;
	splitFilePaths = SplitString(filepath, "\\");

	for (auto& string : splitFilePaths)
	{
		//[.]がついているものを探し、分割する
		if (string.find(".") != std::string::npos)
		{
			std::vector<std::string>  splitTexPath;
			splitTexPath = SplitString(string, ".");

			//分割数が2つになっていないなら何らかの問題があるのでそのまま送り返す
			if (splitTexPath.size() != 2)
			{
				return;
			}

			//手前をファイル名に
			mFileName = ConvertStringToWChar(splitTexPath[0]);
			
			//奥をファイル拡張子に格納
			mFileExt = ConvertStringToWChar(splitTexPath[1]);

			break;
		}
		//[.]がついていないならディレクトリパス側に格納する
		else
		{
			mDirectoryPath += ConvertStringToWChar(string);
			mDirectoryPath += ConvertStringToWChar("\\");
		}
	}
}

void TextureConverter::SaveDDSTextureToFile()
{
	mMetadata.format = MakeSRGB(mMetadata.format);

	HRESULT result;

	//出力ファイル名を設定
	std::wstring filePath = mDirectoryPath + mFileName + L".dds";

	//DDSファイル書き出し
	result = SaveToDDSFile(mScratchImage.GetImages(), mScratchImage.GetImageCount(),
		mMetadata,DDS_FLAGS_NONE,filePath.c_str());
	assert(SUCCEEDED(result));
}
