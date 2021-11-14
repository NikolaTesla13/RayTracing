#pragma once

#include <string>
#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <glm/vec3.hpp>
#include <glm/gtx/string_cast.hpp>

namespace Experiment
{
	class Logger
	{
	public:
		static void Initialize();

		static void Message(const std::string& message);
		static void Message(const glm::vec3& vec);
		static void Warning(const std::string& message);
		static void Error(const std::string& message);

	private:
		static std::shared_ptr<spdlog::logger> console;
	};
}

#define LOG(x) Logger::Message(x);
#define LOG_ERROR(x) Logger::Error(x); __debugbreak();