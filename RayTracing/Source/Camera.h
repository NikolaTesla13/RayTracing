#pragma once

#include "Ray.h"

namespace Experiment
{
	class Camera
	{
	public: 
		Camera();
		Ray getRay(float u, float v);

	private:
		Point3 m_Origin, m_LowerLeftCorner;
		Vector3 m_Horiziontal, m_Vertical;
	};
}