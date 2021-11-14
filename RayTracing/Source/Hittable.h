#pragma once

#include "Utils/Math.h"
#include "Ray.h"

namespace Experiment
{
	struct HitRecord
	{
		Point3 p;
		Vector3 normal;
		float t;
		bool frontFace;

		inline void setFaceNormal(const Ray& r, const Vector3& outwardNormal)
		{
			frontFace = glm::dot(r.getDirection(), outwardNormal) < 0;
			normal = frontFace ? outwardNormal : -outwardNormal;
		}
	};

	class Hittable
	{
	public:
		virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const = 0;
	};
}