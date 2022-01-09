#pragma once

#include <thread>
#include <atomic>
#include <condition_variable>
#include <chrono>

#if defined(__linux__)
#include <notifier/linux/notif.hpp>
#elif defined(_WIN32)
#include <notifier/windows/notif.hpp>
#endif

namespace notifier
{

    class DefferedNotif
    {
    public:
        using seconds_t = std::chrono::duration<float>;

        DefferedNotif(NotifBase* notifBasePtr,
                      std::chrono::seconds timeToInvoke)
        {
            Notif n = *static_cast<Notif*>(notifBasePtr) ;

            _fields = std::make_shared<Fields>();
            _fields->InvokeTime = std::chrono::system_clock::now() + timeToInvoke;
            _fields->IsCanceled = false;

            const auto task = [](std::shared_ptr<Fields> fields,
                                 Notif n)
            {
                std::unique_lock<std::mutex> ul(fields->Mutex);
                fields->Cv.wait_until(ul, fields->InvokeTime, [fields]() -> bool { return fields->IsCanceled; });
                if (fields->IsCanceled) { return; }
                n.Invoke();
            };

            std::thread(task, _fields, std::move(n)).detach();
        }

        ~DefferedNotif() {}

        void Await();
        void Cancel();
        seconds_t RemainingTimeToInvoke() const;

    private:
        struct Fields
        {
            std::atomic_bool IsCanceled;
            std::mutex Mutex;
            std::condition_variable Cv;
            std::chrono::system_clock::time_point InvokeTime;
        };

        std::shared_ptr<Fields> _fields;

        friend class NotifBase;
    };

} //namespace notifier
