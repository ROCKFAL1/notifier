#pragma once

#include <notifier/notifbuilder.hpp>
#include <notifier/defferednotif.hpp>
#include <notifier/icon/sysicon.hpp>

#if defined(__linux__)
#include <notifier/linux/notif.hpp>
#elif defined(_WIN32)
#include <notifier/windows/notif.hpp>
#include <notifier/windows/icon.hpp>
#endif
