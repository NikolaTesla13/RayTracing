#pragma once

#include <string>
#include <chrono>
#include "Logger.h"

namespace Experiment
{
    class Profiler
    {
    public:

        static void Begin(std::string title = "");
        static void End();
    private:

        static std::chrono::steady_clock::time_point m_Start, m_End;
        static std::chrono::duration<double> m_Duration;
        static std::string m_Title;
    };
}