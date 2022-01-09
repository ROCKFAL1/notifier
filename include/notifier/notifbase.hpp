#pragma once

#include <string>
#include <chrono>

#if defined(__linux__)
//TODO
#elif defined(_WIN32)
#include <notifier/windows/icon.hpp>
#endif

namespace notifier
{
    class DefferedNotif;

    class NotifBase
    {
    public:
        NotifBase() {};
        virtual ~NotifBase() {};

        virtual void Invoke() = 0;
        DefferedNotif InvokeDeffered(std::chrono::seconds timeToInvoke);

    protected:
        std::string _header;
        std::string _body;
        Icon _icon;

        friend class NotifBuilder;
    };
} //namespace notifier