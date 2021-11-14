#include "HittableList.h"

namespace Experiment
{
	HittableList::HittableList(std::shared_ptr<Hittable> object)
	{
		push(object);
	}

	void HittableList::clear()
	{
		m_Objects.clear();
	}

	void HittableList::push(std::shared_ptr<Hittable> object)
	{
		m_Objects.push_back(object);
	}

    bool HittableList::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
    {
		HitRecord tempRec;
		bool hitAnything = false;
		auto closestSoFar = tMax;

		for (const auto& object : m_Objects)
		{
			if (object->hit(r, tMin, closestSoFar, tempRec))
			{
				hitAnything = true;
				closestSoFar = tempRec.t;
				rec = tempRec;
			}
		}

		return hitAnything;
	}
}

