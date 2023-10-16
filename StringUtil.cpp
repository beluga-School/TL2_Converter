#include "StringUtil.h"
#include <iostream>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>

using namespace std;

std::string ConvertWCharToString(const wchar_t* t) 
{
    wstring wString(t);

    //wstring → SJIS
    int32_t iBufferSize = WideCharToMultiByte(
        CP_OEMCP,
        0,
        wString.c_str(),
        -1,
        (char*)NULL,
        0,
        NULL,
        NULL
    );

    //バッファの取得
    CHAR* cpMultiByte = new CHAR[iBufferSize];

    //wstring → SJIS
    WideCharToMultiByte(
        CP_OEMCP,
        0,
        wString.c_str(),
        -1,
        cpMultiByte,
        iBufferSize,
        NULL,
        NULL
    );

    //stringの生成
    string oRet(cpMultiByte, cpMultiByte + iBufferSize - 1);

    //バッファの破棄
    delete[] cpMultiByte;

    //変換結果を返す
    return (oRet);
}

wstring ConvertStringToWChar(const std::string& str)
{
    string wString(str);

    //wstring → SJIS
    int32_t iBufferSize = MultiByteToWideChar(
        CP_OEMCP,
        0,
        wString.c_str(),
        -1,
        (wchar_t*)NULL,
        0
    );

    //バッファの取得
    WCHAR* cpMultiByte = new WCHAR[iBufferSize];

    //wstring → SJIS
    MultiByteToWideChar(
        CP_OEMCP,
        0,
        wString.c_str(),
        -1,
        cpMultiByte,
        iBufferSize
    );

    //stringの生成
    wstring oRet(cpMultiByte, cpMultiByte + iBufferSize - 1);

    //バッファの破棄
    delete[] cpMultiByte;

    //変換結果を返す
    return (oRet);
}

std::vector<std::string> SplitString(const std::string& str, const char* delimiter)
{
    vector<string> vec;
    size_t len = str.length();

    size_t n = 0;

    for (size_t i = 0; i < len; i = n + 1)
    {
        n = str.find_first_of(delimiter, i);
        if (n == string::npos)
        {
            n = len;
        }
        vec.push_back(str.substr(i, n - i));
    }

    return vec;
}
