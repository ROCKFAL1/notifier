#pragma once
#if defined(__linux__)

#include <notifier/icon/iconbase.hpp>

namespace notifier
{
    class Icon final : public IconBase
    {
    public:
        Icon() {};
        Icon(SysIcon sysIcon);
        ~Icon() override {};

    };
}

#endif