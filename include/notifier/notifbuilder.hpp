#pragma once

#include <string>
#include <memory>

namespace notifier
{
    class Notif;

    class NotifBuilder
    {
    public:
        NotifBuilder& SetHeader(std::string header);
        NotifBuilder& SetBody(std::string body);

        std::unique_ptr<Notif> Build() const;

    private:
        std::string _header;
        std::string _body;
    };

} ///namespace notifier1