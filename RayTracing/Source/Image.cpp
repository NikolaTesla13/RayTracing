#include "Image.h"
#include "Utils/Logger.h"

namespace Experiment
{
	Image::Image(const ImageProps &props)
	{
		m_Width = props.width;
		m_Height = props.height;
		m_Data.reserve(m_Width * m_Height);
		m_Format = props.format;

		m_Filename = props.filename;
		switch (m_Format)
		{
		case Format::PPM:
			m_Filename += ".ppm";
			m_File = std::ofstream(m_Filename);
			break;
		case Format::BMP:
			m_Filename += ".bmp";
			m_File = std::ofstream(m_Filename, std::ios::out | std::ios::binary);
			break;
		default:
			break;
		}
	}

	void Image::WriteColor(Color color)
	{
		if(color.isVald()) 
		{
			m_Data.push_back(color);
		}
		else 
		{
			LOG_ERROR("Failed to write color")
		}
	}

	void Image::WriteColor(RayColor rayColor, uint32_t samplesPerPixel)
	{
		Color color;
		color.fromRayColor(rayColor, samplesPerPixel);
		WriteColor(color);
	}

	bool Image::CanBeFlushed()
	{
		return m_Data.size() == m_Width * m_Height;
	}

	void Image::Flush()
	{
		if (!CanBeFlushed())
		{
			LOG_ERROR("Failed to write data to image")
		}

		switch (m_Format)
		{
		case Format::PPM:
			
			m_File << "P3\n" << m_Width << ' ' << m_Height << "\n255\n";

			for (auto color : m_Data)
			{
				m_File << color.rgb[0] << ' ' << color.rgb[1] << ' ' << color.rgb[2] << '\n';
			}

			m_File.close();

			break;
		case Format::BMP:
			
			const size_t headerSize = 54;
			char header[headerSize] = { 0 };
			uint16_t paddingBytes = m_Width % 4 == 0 ? 0 : 4 - m_Width * 3 % 4;
			const size_t arraySize = m_Height * (m_Width + paddingBytes) * 3;
			const size_t totalSize = headerSize + arraySize;

			memcpy(header, "BM", 2);
			*(size_t*)(header + 0x2) = totalSize;
			*(size_t*)(header + 0xA) = headerSize;
			*(size_t*)(header + 0xE) = headerSize - 14;
			*(size_t*)(header + 0x12) = m_Width;
			*(size_t*)(header + 0x16) = m_Height;
			*(header + 0x1A) = 1;
			*(header + 0x1C) = 24;
			*(size_t*)(header + 0x22) = arraySize;
			*(size_t*)(header + 0x26) = 2835;
			*(size_t*)(header + 0x2A) = 2835;

			char* data = new char[m_Height * m_Width * 3];
			char* dataPtr = data;
			for (auto color : m_Data)
			{
				if (color.isVald())
				{
					for (int k = 2; k >= 0; k--) {
						*dataPtr++ = static_cast<char>(color.rgb[k]);
					}
					dataPtr += paddingBytes;
				}
				else
				{
					LOG_ERROR("Failed to write data to image file");
					return;
				}
			}

			m_File.write(header, headerSize);
			m_File.write(data, arraySize);
			m_File.close();

			break;
		}
	}
}