#pragma once

#include "Utils/Math.h"

namespace Experiment
{
	class Ray
	{
	public:
		Ray(const Point3& origin, const Vector3& direction) : m_Origin(origin), m_Direction(direction) {}

		Point3 getOrigin() const { return m_Origin; }
		Vector3 getDirection() const { return m_Direction; }

		Vector3 getUnitVector() const
		{
			return glm::normalize(m_Direction);
		}

		float getLengthOfDirectionVector() const
		{
			return static_cast<float>(m_Direction.length());
		}

		Point3 at(float t) const
		{
			return m_Origin + m_Direction * t;
		}

	private:
		Point3 m_Origin;
		Vector3 m_Direction;
	};
}