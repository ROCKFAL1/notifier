#include <iostream>
#include <chrono>
#include <thread>

#include <notifier/notifier.hpp>

using namespace std::chrono_literals;

int main() {
    
    notifier::NotifBuilder builder;

    {
        builder.SetBody("Body");
        builder.SetHeader("Header");
        builder.Build()->InvokeDeffered(3s).Await();
    }

    {
        auto notif = builder.SetBody("Body_2").SetHeader("Header_2").Build();
        auto deffered = notif->InvokeDeffered(10s);
        std::this_thread::sleep_for(5s);
        deffered.Cancel();
        std::cout << deffered.RemainingTimeToInvoke().count() << std::endl;
    }

    {
        auto notif = builder.SetBody("Body_3").SetHeader("Header_3").Build();
        notif->InvokeDeffered(5s);
        
    }

    std::this_thread::sleep_for(6s);

}
