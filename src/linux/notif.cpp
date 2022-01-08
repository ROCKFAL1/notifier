#if defined(__linux__)
#include <notifier/linux/notif.hpp>

#include <libnotify/notify.h>

void notifier::Notif::Invoke()
{
    notify_init (this->_header.c_str());
    NotifyNotification* notif = notify_notification_new (this->_header.c_str(), this->_body.c_str(), nullptr);
    notify_notification_show (notif, nullptr);
    g_object_unref(G_OBJECT(notif));
    notify_uninit();
}

#endif