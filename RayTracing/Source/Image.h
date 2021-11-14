#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "Utils/Math.h"

namespace Experiment
{
	struct Color
	{
		double rgb[3];

		bool isVald() {
			return (rgb[0] < 256) && (rgb[1] < 256) && (rgb[2] < 256);
		}

		void fromRayColor(RayColor color, uint32_t samplesPerPixel)
		{
			float r = color.x;
			float g = color.y;
			float b = color.z;

			float scale = 1.0f / samplesPerPixel;
			r *= scale;
			g *= scale;
			b *= scale;

			rgb[0] = static_cast<uint16_t>(256 * std::clamp<float>(r, 0.0f, 0.999f));
			rgb[1] = static_cast<uint16_t>(256 * std::clamp<float>(g, 0.0f, 0.999f));
			rgb[2] = static_cast<uint16_t>(256 * std::clamp<float>(b, 0.0f, 0.999f));
		}
	};

	enum class Format { PPM, BMP };

	struct ImageProps
	{
		 using enum Format;

		uint16_t width;
		uint16_t height;
		std::string filename;
		Format format;
	};

	class Image
	{
	public:

		Image(const ImageProps& props);
		void WriteColor(Color color);
		void WriteColor(RayColor rayColor, uint32_t samplesPerPixel);
		void Flush();

	private:
		bool CanBeFlushed();

		uint16_t m_Width, m_Height;
		std::vector<Color> m_Data;
		Format m_Format;
		std::string m_Filename;
		std::ofstream m_File;
	};
}