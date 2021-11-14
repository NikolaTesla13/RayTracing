#pragma once

#include <random>

namespace Experiment
{
	class Random
	{
	public:
		static void Initialize()
		{
			s_RandomEngine.seed(std::random_device()());
		}

		static float Float()
		{
			return static_cast<float>(s_Distribution(s_RandomEngine)) / std::numeric_limits<uint32_t>::max();
		}

		static float FloatRange(float min, float max)
		{
			return min + Float() * max;
		}

	private:
		static std::mt19937 s_RandomEngine;
		static std::uniform_int_distribution<std::mt19937::result_type> s_Distribution;
	};
}