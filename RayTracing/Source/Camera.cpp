#include "Camera.h"

namespace Experiment
{
	Camera::Camera()
	{
		float aspectRatio = 16.0 / 9.0;
		float viewportHeight = 2.0;
		float viewportWidth = aspectRatio * viewportHeight;
		float focalLength = 1.0;

		m_Origin = Point3(0, 0, 0);
		m_Horiziontal = Vector3(viewportWidth, 0, 0);
		m_Vertical = Vector3(0, viewportHeight, 0);
		m_LowerLeftCorner = m_Origin - m_Horiziontal / 2.0f - m_Vertical / 2.0f - Vector3(0, 0, focalLength);
	}

	Ray Camera::getRay(float u, float v)
	{
		return Ray(m_Origin, m_LowerLeftCorner + u * m_Horiziontal + v * m_Vertical - m_Origin);
	}
}
