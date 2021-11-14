#pragma once

#include "Hittable.h"
#include <memory>
#include <vector>

namespace Experiment
{
	class HittableList : public Hittable
	{
	public:
		HittableList() {}
		HittableList(std::shared_ptr<Hittable> object);

		void clear();
		void push(std::shared_ptr<Hittable> object);

		virtual bool hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const override;

	private:
		std::vector<std::shared_ptr<Hittable>> m_Objects;
	};

}