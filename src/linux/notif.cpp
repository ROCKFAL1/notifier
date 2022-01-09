#if defined(__linux__)
#include <notifier/linux/notif.hpp>

#include <libnotify/notify.h>
#include <iostream>

void notifier::Notif::Invoke()
{
    notify_init (this->_header.c_str());
    std::cout << this->_icon.Get() << std::endl;
    NotifyNotification* notif = notify_notification_new (this->_header.c_str(), this->_body.c_str(), this->_icon.Get().c_str());
    notify_notification_show (notif, nullptr);
    g_object_unref(G_OBJECT(notif));
    notify_uninit();
}

#endif