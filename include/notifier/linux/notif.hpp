#pragma once
#if defined(__linux__)

#include <notifier/notifbase.hpp>

namespace notifier
{

    class Notif final : public NotifBase
    {
    public:
        Notif() : NotifBase() {};
        ~Notif() override {};

        void Invoke() override;

        friend class NotifBuilder;
    };

} //namespace notifier1

#endif