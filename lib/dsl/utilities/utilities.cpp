#include "utilities.h"

namespace dsl
{
    namespace utilities
    {
        ScopedTimer::ScopedTimer(const std::function<void(timediff)> callback)
            : __callback(callback), __started(false)
        {
            reset();
        }

        ScopedTimer::ScopedTimer()
        {
            reset();
        }

        void ScopedTimer::reset()
        {
            __started = true;
            __start = std::chrono::high_resolution_clock::now();
        }

        void ScopedTimer::stop(bool restart /* = false */)
        {
            if (__started)
            {
                std::chrono::_V2::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
                if (__callback)
                    __callback(now - __start);
                __started = false;
                if (restart)
                    this->reset();
            }
        }

        ScopedTimer::~ScopedTimer()
        {
            stop();
        }
    }
}