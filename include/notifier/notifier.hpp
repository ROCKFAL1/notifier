#pragma once

#include <notifier/notifbase.hpp>
#include <notifier/notifbuilder.hpp>
#include <notifier/defferednotif.hpp>

#if defined(__linux__)
#include <notifier/linux/notif.hpp>
#elif defined(_WIN32)
//TODO
#endif
