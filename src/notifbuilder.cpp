#include <notifier/notifbuilder.hpp>

#if defined(__linux__)
#include <notifier/linux/notif.hpp>
#elif defined(_WIN32)
#include <notifier/windows/notif.hpp>
#include <notifier/windows/icon.hpp>
#endif

using namespace notifier;

NotifBuilder& NotifBuilder::SetBody(std::string body)
{
    this->_body = std::move(body);
    return *this;
}

NotifBuilder& NotifBuilder::SetHeader(std::string header)
{
    this->_header = std::move(header);
    return *this;
}

NotifBuilder& NotifBuilder::SetIcon(Icon icon)
{
    this->_icon = std::move(icon);
    return *this;
}

std::unique_ptr<notifier::Notif> NotifBuilder::Build() const
{
    auto result = std::make_unique<Notif>();
    result->_header = this->_header;
    result->_body = this->_body;
    result->_icon = this->_icon;
    return result;
}





