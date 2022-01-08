#include <notifier/defferednotif.hpp>

#if defined(__linux__)
#include <notifier/linux/notif.hpp>
#elif defined(_WIN32)
#include <notifier/windows/notif.hpp>
#endif

using namespace std::chrono_literals;
using namespace notifier;

void DefferedNotif::Await()
{
    std::unique_lock<std::mutex> ul(_fields->Mutex);
    _fields->Cv.wait_until(ul, _fields->InvokeTime, [&]() -> bool { return _fields->IsCanceled; });
}

void DefferedNotif::Cancel()
{
    _fields->IsCanceled = true;
    _fields->Cv.notify_all();
}

DefferedNotif::seconds_t DefferedNotif::RemainingTimeToInvoke() const
{
    const auto time = _fields->InvokeTime - std::chrono::system_clock::now();
    return  time.count() > 0 ? time : std::chrono::seconds(0);
}


