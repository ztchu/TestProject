#pragma once

#include <functional>
#include <map>
#include <string>
#include <Windows.h>

class DllParser {
public:
    DllParser();
    ~DllParser();

    bool Load(const std::string& dllPath);
    bool UnLoad();

    template <typename T>
    std::function<T> GetFunction(const std::string& funcName);

    template <typename T, typename... Args>
    typename std::result_of<std::function<T>(Args...)>::type
        ExecuteFunc(const std::string& funcName, Args&&... args);
private:
    HMODULE m_hMod;
    std::map<std::string, FARPROC> m_map;
};