#include "Sphere.h"

namespace Experiment
{
    bool Sphere::hit(const Ray& r, float tMin, float tMax, HitRecord& rec) const
    {
        Vector3 oc = r.getOrigin() - m_Center;
        auto a = getLenghtSquaredOfVector(r.getDirection());
        auto halfB = glm::dot(oc, r.getDirection());
        auto c = getLenghtSquaredOfVector(oc) - m_Radius * m_Radius;
        
        auto discriminant = halfB * halfB - a * c;
        if (discriminant < 0)
        {
            return false;
        }
        auto sqrtd = std::sqrt(discriminant);

        auto root = (-halfB - sqrtd) / a;
        if (root < tMin || tMax < root) 
        {
            root = (-halfB + sqrtd) / a;
            if (root < tMin || tMax < root)
            {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Vector3 outwardNormal = (rec.p - m_Center) / m_Radius;
        rec.setFaceNormal(r, outwardNormal);

        return true;
    }
}

