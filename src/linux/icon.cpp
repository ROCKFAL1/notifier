#if defined(__linux__)
#include <notifier/linux/icon.hpp>

#include <stdexcept>

using namespace notifier;
Icon::Icon(SysIcon sysIcon)
{
    switch (sysIcon)
    {
        case SysIcon::None:
            _icon = nullptr;
            break;
        case SysIcon::Info:
            _icon = "dialog-information";
            break;
        case SysIcon::Warning:
            _icon = "dialog-warning";
            break;
        case SysIcon::Error:
            _icon = "dialog-error";
            break;
        default:
            throw std::runtime_error("Unknown value of sysIcon argument");
    };
}

#endif