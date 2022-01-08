#pragma once

#include <string>
#include <chrono>

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
    };
} //namespace notifier1