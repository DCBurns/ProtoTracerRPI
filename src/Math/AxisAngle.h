#pragma once

#include "Mathematics.h"
#include "Vector3D.h"

class AxisAngle {
public:
	float Rotation;
	Vector3D Axis;

	AxisAngle(float rotation, float x, float y, float z) {
		Rotation = rotation;
		Axis = Vector3D(x, y, z);
	}

	AxisAngle(float rotation, Vector3D axis) {
		Rotation = rotation;
		Axis = axis;
	}

	std::string ToString() {
		std::string r = Mathematics::DoubleToCleanString(Rotation);
		std::string x = Mathematics::DoubleToCleanString(Axis.X);
		std::string y = Mathematics::DoubleToCleanString(Axis.Y);
		std::string z = Mathematics::DoubleToCleanString(Axis.Z);

		return r + ": [" + x + " " + y + " " + z + "]";
	}
};
