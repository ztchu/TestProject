#include "dll_helper.h"

#include <exception>

DllParser::DllParser():m_hMod(nullptr) {

}

DllParser::~DllParser() {
    UnLoad();
}

bool DllParser::Load(const std::string& dllPath) {
    m_hMod = LoadLibraryA(dllPath.c_str());
    if (!m_hMod) {
        return false;
    }
    return true;
}

bool DllParser::UnLoad() {
    if (!m_hMod) {
        return true;
    }

    auto ret = FreeLibrary(m_hMod);
    if (!ret) {
        return false;
    }
    return true;
}

template <typename T>
std::function<T> DllParser::GetFunction(const std::string& funcName) {
    auto iter = m_map.find(funcName);
    if (iter == m_map.end()) {
        auto func = GetProcAddress(m_hMod, funcName.c_str());
        if (!func) {
            return nullptr;
        }
        m_map.insert({ funcName, func });
        iter = m_map.find(funcName);
    }
    return std::function<T>((T*)(iter->second));
}

template <typename T, typename... Args>
typename std::result_of<std::function<T>(Args...)>::type
DllParser::ExecuteFunc(const std::string& funcName, Args&&... args) {
    auto f = GetFunction<T>(funcName);
    if (!f) {
        std::string err = "Can not find this function: " + funcName;
        throw std::exception((err.c_str()));
    }
    return f(std::forward<Args>(args)...);
}


void TestDllHelper() {
    DllParser dll;
    auto max = dll.ExecuteFunc<int(int, int)>("Max", 5, 5);
    auto get = dll.ExecuteFunc<int()>("Get");
}