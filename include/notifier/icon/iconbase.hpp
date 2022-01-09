#pragma once 

#include <notifier/icon/sysicon.hpp>

#if defined(__linux__)
#include <iostream>
#elif defined(_WIN32)
#include <windows.h>
#endif

namespace notifier
{
    #if defined(__linux__)
    using IconType = std::string; //probably todo??
    #elif defined(_WIN32)

    struct WinIconType
    {
        HICON hIcon = nullptr;
        DWORD flags = NIIF_NONE;
    };

    using IconType = WinIconType;
    #endif

    class IconBase
    {
    public:
        virtual ~IconBase() {};

        const IconType& Get() const { return _icon; };
        operator const IconType&() const  { return _icon; }

    protected:
        IconType _icon;
    };
} //namespace notifier