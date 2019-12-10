//
//  maths.hpp
//  Protocol Bernardo
//
//  Created by Valentin Dufois on 2019-09-18.
//

#ifndef maths_h
#define maths_h

/// The default scalar type to use throughout the application
///
/// The type is defined as a macro to conserve the possibility of
/// easily switching the entire app to another scalar type.
#define SCALAR double

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_SWIZZLE_XYZW
#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "../Network/Messages/messages.hpp"

#ifdef MACHINE_TRACKER
#include <nite2/NiTE.h>
#endif

namespace pb {
namespace maths {

// MARK: - Definitions
const double pi = 3.14159265358979323846;  /* pi */

// Define common types
using vec2 = glm::vec<2, SCALAR, glm::qualifier::defaultp>;
using vec3 = glm::vec<3, SCALAR, glm::qualifier::defaultp>;
using vec4 = glm::vec<4, SCALAR, glm::qualifier::defaultp>;

// MARK: - Conversion

template<typename T>
inline T deg2rad(const T &deg) {
	return deg * pi / 180.0;
}

template<typename T>
inline T rad2deg(const T &rad) {
	return rad * 180.0 / pi;
}


#ifdef MACHINE_TRACKER

/// Converts a nite float3 to a `vec3`
/// @param p3f The float3 to convert
inline vec3 P3FToVec3(const nite::Point3f &p3f) {
	return vec3(-p3f.x, p3f.y, p3f.z);
}

/// Converts a nite quaternion to a `vec3` euler angle (pitch, yaw, roll)
/// @param nQuat The quaternion to convert
inline vec3 nQuatToVec3(const nite::Quaternion &nQuat) {
	return glm::eulerAngles(glm::quat(nQuat.x, nQuat.y, nQuat.z, nQuat.w));
}

#endif /* MACHINE_TRACKER */

// MARK: - Network

/// Converts a `vec2` to its equivalent protobuf message
/// @param vec The vec to convert
inline network::messages::vec2 * asMessage(const vec2 &vec) {
	network::messages::vec2 * message = new network::messages::vec2();
	message->set_x(vec.x);
	message->set_y(vec.y);

	return message;
}

/// Converts a `vec23` to its equivalent protobuf message
/// @param vec The vec to convert
inline network::messages::vec3 * asMessage(const vec3 &vec) {
	network::messages::vec3 * message = new network::messages::vec3();
	message->set_x(vec.x);
	message->set_y(vec.y);
	message->set_z(vec.z);

	return message;
}

/// Converts a `vec4` to its equivalent protobuf message
/// @param vec The vec to convert
inline network::messages::vec4 * asMessage(const vec4 &vec) {
	network::messages::vec4 * message = new network::messages::vec4();
	message->set_x(vec.x);
	message->set_y(vec.y);
	message->set_z(vec.z);
	message->set_w(vec.w);

	return message;
}

/// Gives the vec2 represented by the given message
/// @param message The message to unpack
inline vec2 fromMessage(const network::messages::vec2 &message) {
	vec2 vec;
	vec.x = message.x();
	vec.y = message.y();

	return vec;
}

/// Gives the vec3 represented by the given message
/// @param message The message to unpack
inline vec3 fromMessage(const network::messages::vec3 &message) {
	vec3 vec;
	vec.x = message.x();
	vec.y = message.y();
	vec.z = message.z();

	return vec;
}

/// Gives the vec4 represented by the given message
/// @param message The message to unpack
inline vec4 fromMessage(const network::messages::vec4 &message) {
	vec4 vec;
	vec.x = message.x();
	vec.y = message.y();
	vec.z = message.z();
	vec.w = message.w();

	return vec;
}

} /* ::maths */
} /* ::pb */

#endif /* maths_h */
