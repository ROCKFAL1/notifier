#if defined(_WIN32)
#include <notifier/windows/notif.hpp>

#include <iostream>
#include <utils/uid.hpp>

using namespace notifier;

utils::uid uid;

Notif::Notif()
    : NotifBase()
{
    const auto id = uid.get_next();
    auto indetifier = "notifierclass" + std::to_string(id);
    memset(&_windowClass, 0, sizeof(_windowClass));
    _windowClass.cbSize = sizeof(_windowClass);
    _windowClass.lpszClassName = indetifier.c_str();
    _windowClass.lpfnWndProc = WndProc;
    _windowClass.hInstance = GetModuleHandle(nullptr);

    if (RegisterClassExA(&_windowClass) == FALSE)
    {
        throw std::runtime_error("Register class error!");
    }

    _hwnd = CreateWindowA(indetifier.c_str(),
        nullptr,
        0, 0, 0, 0, 0,
        nullptr,
        nullptr,
        _windowClass.hInstance,
        nullptr);

    if (UpdateWindow(_hwnd) == FALSE)
    {
        throw std::runtime_error("Update window error!");
    }
}

void Notif::Invoke()
{
    NOTIFYICONDATA notifData;

    memset(&notifData, 0, sizeof(NOTIFYICONDATA));
    notifData.cbSize = sizeof(NOTIFYICONDATA);
    notifData.hWnd = _hwnd;
    notifData.uFlags = NIF_INFO;
     
    strcpy_s(notifData.szInfoTitle, this->_header.c_str());
    strcpy_s(notifData.szInfo, this->_body.c_str());

    if (Shell_NotifyIconA(NIM_ADD, &notifData) == FALSE
        || Shell_NotifyIconA(NIM_DELETE, &notifData) == FALSE)
    {
        throw std::runtime_error("Invoke notification error!");
    }
}

LRESULT CALLBACK Notif::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(hwnd, msg, wParam, lParam);
}


#endif