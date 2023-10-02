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
	//�e�N�X�`���t�@�C���ǂݍ���
	void LoadWICTextureFromFile(const std::string& filepath);
};

