#include "Program.h"
#include "Utils/Profiler.h"
#include "Image.h"
#include "Ray.h"
#include "Sphere.h"
#include "HittableList.h"
#include "Camera.h"

namespace Experiment
{
    RayColor rayColor(const Ray& r, const HittableList& world)
    {
        HitRecord hitRecord;
        if (world.hit(r, 0, infinity, hitRecord))
        {
            return 0.5f * (hitRecord.normal + RayColor(1, 1, 1));
        }
        Vector3 unitdirection = r.getUnitVector();
        float t = 0.5 * (unitdirection.y + 1.0);
        return (1.0f - t) * RayColor(1.0, 1.0, 1.0) + t * RayColor(0.5, 0.7, 1.0);
    }

	void Program::Initialize()
	{
        const float aspectRatio = 16.0f / 9.0f;
        const uint16_t imageWidth = 400;
        const uint16_t imageHeight = static_cast<uint16_t>(imageWidth / aspectRatio);
        const uint16_t samplesPerPixel = 100;
        Image image({ imageWidth, imageHeight, "render", Format::BMP });

        HittableList world;
        world.push(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
        world.push(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

        Camera camera;

        float viewportHeight = 2.0;
        float viewportWidth = aspectRatio * viewportHeight;
        float focalLength = 1.0;

        Point3 origin({ 0, 0, 0 });
        Vector3 horizontal = Vector3(viewportWidth, 0, 0);
        Vector3 vertical = Vector3(0, viewportHeight, 0);
        Vector3 lowerLeftCorner = origin - horizontal / 2.0f - vertical / 2.0f - Vector3(0, 0, focalLength);

        Profiler::Begin("Rendering");
        for (int j = 0; j < imageHeight; j++) 
        {
            for (int i = 0; i < imageWidth; ++i) 
            {
                RayColor _rayColor(0, 0, 0);
                
                for (int s = 0; s < samplesPerPixel; s++)
                {
                    float u = (i + Random::Float()) / (imageWidth - 1);
                    float v = (j + Random::Float()) / (imageHeight - 1);

                    Ray r = camera.getRay(u, v);
                    _rayColor += rayColor(r, world);
                }

                image.WriteColor(_rayColor, samplesPerPixel);
            }
        }
        Profiler::End();

        Profiler::Begin("Serializing");
        image.Flush();
        Profiler::End();
	}
}
