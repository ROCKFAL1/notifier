#include <notifier/windows/icon.hpp>

#include <stdexcept>

using namespace notifier;

Icon::Icon(SysIcon sysIcon)
{
    switch (sysIcon)
    {
        case SysIcon::None:
            _icon.flags |= NIIF_NONE;
            break;
        case SysIcon::Info:
            _icon.flags |= NIIF_INFO;
            break;
        case SysIcon::Warning:
            _icon.flags |= NIIF_WARNING;
            break;
        case SysIcon::Error:
            _icon.flags |= NIIF_ERROR;
            break;
        default:
            throw std::runtime_error("Unknown value of sysIcon argument");
            break;
    };
}