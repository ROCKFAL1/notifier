#include <notifier/notifbuilder.hpp>

#if defined(__linux__)
#include <notifier/linux/notif.hpp>
#elif defined(_WIN32)
#include <notifier/windows/notif.hpp>
#endif

notifier::NotifBuilder& notifier::NotifBuilder::SetBody(std::string body)
{
    this->_body = std::move(body);
    return *this;
}

notifier::NotifBuilder& notifier::NotifBuilder::SetHeader(std::string header)
{
    this->_header = std::move(header);
    return *this;
}

std::unique_ptr<notifier::Notif> notifier::NotifBuilder::Build() const
{
    auto result = std::make_unique<Notif>();
    result->_header = this->_header;
    result->_body = this->_body;
    return result;
}





