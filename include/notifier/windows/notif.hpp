#pragma once 
#if defined(_WIN32)

#include <notifier/notifbase.hpp>

#include <windows.h>

namespace notifier
{

    class Notif final : public NotifBase
    {
    public:
        Notif();
        ~Notif() override {};

        void Invoke() override;

    private:
        WNDCLASSEX _windowClass;
        HWND _hwnd;
        
        static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

        friend class NotifBuilder;
    };

}

#endif
