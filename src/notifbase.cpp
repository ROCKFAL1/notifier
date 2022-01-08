#include <notifier/notifbase.hpp>

#include <notifier/defferednotif.hpp>

using namespace notifier;

DefferedNotif NotifBase::InvokeDeffered(std::chrono::seconds timeToInvoke)
{
    return DefferedNotif(this, std::move(timeToInvoke));
}

