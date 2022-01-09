#pragma once

#include <string>
#include <memory>

#if defined(__linux__)
//TODO
#elif defined(_WIN32)
#include <notifier/windows/icon.hpp>
#endif

namespace notifier
{
    class Notif;

    class NotifBuilder
    {
    public:
        NotifBuilder& SetHeader(std::string header);
        NotifBuilder& SetBody(std::string body);
        NotifBuilder& SetIcon(Icon icon);

        std::unique_ptr<Notif> Build() const;

    private:
        std::string _header;
        std::string _body;
        Icon _icon;
    };

} ///namespace notifier