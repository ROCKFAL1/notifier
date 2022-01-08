#pragma once

#include <numeric>

namespace utils
{
    class uid
    {
    public:
        std::uint32_t get_next()
        {
            return ++uid_;
        }
        
    private:
        std::uint32_t uid_ = 0;
    };
}