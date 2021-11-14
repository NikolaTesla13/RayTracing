#include "Logger.h"

namespace Experiment
{
	std::shared_ptr<spdlog::logger> Logger::console;

	void Logger::Initialize()
	{
		console = spdlog::stdout_color_mt("Experiment", spdlog::color_mode::always);
		console->set_pattern("[%H:%M:%S] [%^%l%$] %v");
		console->set_level(spdlog::level::debug);
	}

	void Logger::Message(const std::string& message)
	{
		console->info(message);
	}

	void Logger::Message(const glm::vec3& vec)
	{
		Message(glm::to_string(vec));
	}

	void Logger::Warning(const std::string& message)
	{
		console->warn(message);
	}

	void Logger::Error(const std::string& message)
	{
		console->critical(message);
	}
}