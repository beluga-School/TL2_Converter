#pragma once
#include <string>
#include <vector>

std::string ConvertWCharToString(const wchar_t* t);

std::wstring ConvertStringToWChar(const std::string& str);

//stringを指定した区切り文字で分割する
std::vector<std::string> SplitString(const std::string& str, const char* delimiter);
