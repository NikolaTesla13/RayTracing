#pragma once

#include "Hittable.h"

namespace Experiment
{
	class Sphere : public Hittable
	{
	public:
		Sphere() {}
		Sphere(Point3 center, double radius) : m_Center(center), m_Radius(radius) {}

		virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;

	private:
		Point3 m_Center;
		float m_Radius;
	};
}