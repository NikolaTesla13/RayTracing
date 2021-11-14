#include "Profiler.h"

namespace Experiment
{
    std::chrono::steady_clock::time_point Profiler::m_Start, Profiler::m_End;
    std::chrono::duration<double> Profiler::m_Duration;
    std::string Profiler::m_Title;

    void Profiler::Begin(std::string title)
    {
        m_Start = std::chrono::high_resolution_clock::now();
        m_Title = std::move(title);
    }

    void Profiler::End()
    {
        m_End = std::chrono::high_resolution_clock::now();
        m_Duration = m_End - m_Start;
        double ms = m_Duration.count() * 1000.0f;
        Logger::Message(m_Title + " took " + std::to_string(ms) + " miliseconds");
    }
}