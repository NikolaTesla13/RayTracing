#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
#include <glm/gtx/string_cast.hpp> // glm::to_string

namespace Experiment
{
	using Vector3 = glm::vec3;
	using Point3 = glm::vec3;
	using Point2 = glm::vec2;
	using RayColor = glm::vec3;

	const double infinity = std::numeric_limits<double>::infinity();
	const double pi = 3.1415926535897932385;

	inline double getLenghtSquaredOfVector(Vector3 vec)
	{
		return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	}

	inline double degreesToRadians(double degrees) 
	{
		return degrees * pi / 180.0;
	}
}