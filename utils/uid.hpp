#pragma once

#include <numeric>

namespace utils
{
    class Uid
    {
    public:
        std::uint32_t get_next() { return ++_uid; }
        
    private:
        std::uint32_t _uid = 0;
    };
}