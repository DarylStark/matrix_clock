#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include <chrono>
#include <functional>

namespace dsl
{
    namespace utilities
    {
        typedef std::chrono::duration<float> timediff;

        class ScopedTimer
        {
        private:
            bool __started;
            std::function<void(timediff)> __callback;
            std::chrono::_V2::system_clock::time_point __start;

        public:
            // Constructors and destructors
            ScopedTimer(const std::function<void(timediff)> callback);
            ScopedTimer();
            ~ScopedTimer();

            // Timer functions
            void reset();
            void stop(bool restart = false);
        };
    };
};

#endif /* __UTILITIES_H__ */