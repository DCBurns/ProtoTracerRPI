#pragma once

#include "../Materials/UVMap.h"

class FoxTex : public UVMap{
private:
	static const uint8_t rgbMemory[];
	static const uint8_t rgbColors[];

public:
	FoxTex(Vector2D size, Vector2D offset) : UVMap(rgbMemory, rgbColors, 64, 32, 255) {
		SetSize(size);
		SetPosition(offset);
	}
};

const uint8_t FoxTex::rgbMemory[] PROGMEM = {15,9,9,9,9,15,1,1,3,3,3,3,1,1,2,7,7,7,7,7,7,2,15,9,9,9,9,15,15,15,15,15,15,1,1,1,1,8,8,8,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,9,8,8,9,9,9,1,3,3,5,3,5,3,1,2,4,7,4,7,7,4,2,9,8,8,9,9,9,15,15,15,15,15,1,1,1,1,8,8,8,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,8,7,2,2,2,1,3,5,5,5,5,3,1,7,4,4,4,4,4,4,7,2,7,8,2,2,2,15,15,15,15,15,1,1,1,1,8,4,8,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,5,5,5,3,1,4,4,4,4,4,4,4,4,15,15,15,15,15,15,15,15,15,15,15,1,1,1,1,4,8,8,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,5,5,5,3,1,4,4,4,4,4,4,4,4,15,15,15,15,15,15,15,15,15,15,15,1,1,1,1,4,4,4,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,3,5,3,3,1,4,4,4,4,4,4,4,4,15,15,15,15,15,15,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,3,5,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,3,3,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,2,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,5,3,5,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,1,1,1,1,2,2,1,3,3,3,3,1,2,2,1,1,1,1,2,2,6,6,6,6,6,6,2,1,1,1,1,2,2,2,2,2,2,1,1,1,1,3,5,3,3,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,2,2,3,1,8,9,8,3,5,5,3,8,9,8,1,3,2,2,2,6,6,6,6,6,6,6,6,1,1,1,1,2,2,2,2,2,2,1,1,1,1,3,5,3,3,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,2,6,6,6,6,6,6,6,6,1,1,1,1,2,2,2,2,2,2,1,1,1,1,3,5,3,3,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,6,2,2,8,10,8,10,10,10,10,10,10,10,10,8,10,8,2,2,6,6,6,6,6,6,6,6,6,8,1,8,1,4,4,7,4,7,1,8,1,8,1,8,4,8,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,1,3,3,3,3,1,1,2,7,7,7,7,7,7,2,15,15,15,15,15,15,8,8,8,8,4,4,4,4,4,4,8,8,8,8,8,8,8,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,3,5,3,5,3,1,2,4,7,4,7,7,4,2,15,15,15,15,15,15,8,8,8,4,4,4,4,4,4,4,8,8,8,8,8,8,8,8,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,5,5,5,3,1,7,4,4,4,4,4,4,7,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,5,5,5,3,1,4,4,4,4,4,4,4,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,3,3,3,1,1,3,3,3,3,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,5,5,5,3,1,4,4,4,4,4,4,4,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,3,3,3,3,3,3,1,1,1,1,1,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,5,3,5,3,3,1,4,4,4,4,4,4,4,4,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,10,10,10,10,1,1,1,1,1,1,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,1,1,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,15,15,15,15,15,15,15,15,10,10,10,10,10,10,1,1,1,1,1,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,2,1,1,1,1,1,3,3,3,3,3,3,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,15,15,15,15,15,15,15,15,10,10,10,10,10,10,1,1,1,1,1,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,1,1,1,1,2,5,5,3,3,3,3,5,5,2,1,1,1,1,2,2,6,6,6,6,6,6,2,15,15,15,15,15,15,15,15,4,4,4,4,4,4,2,2,2,2,2,2,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,2,2,3,1,9,9,9,3,5,5,3,9,9,9,1,3,2,2,2,6,6,6,6,6,6,6,6,15,15,3,1,3,1,1,1,7,4,4,4,4,7,1,1,1,3,1,3,1,5,3,5,3,1,15,15,15,15,15,15,15,15,15,15,2,2,2,2,2,2,1,1,1,1,1,1,1,1,2,2,2,2,2,2,6,6,6,6,6,6,6,6,15,15,1,3,3,1,1,1,7,4,4,4,4,7,1,1,1,3,3,1,3,5,5,5,3,3,15,15,15,15,15,15,15,15,15,15,6,2,2,8,10,8,10,10,10,10,10,10,10,10,8,10,8,2,2,6,6,6,6,6,6,6,6,6,15,15,3,3,1,1,1,2,7,4,4,4,4,7,2,1,1,1,3,3,3,3,5,3,5,3,15,15,15,15,15,15,15,15,15,15,15,15,15,1,3,3,1,10,7,7,10,15,15,15,15,15,2,2,9,9,15,15,15,15,2,2,9,9,15,15,3,3,1,1,2,2,7,4,4,4,4,7,2,2,1,1,3,3,5,3,3,3,5,3,15,15,15,15,15,15,15,15,15,15,15,15,15,3,5,5,3,4,4,4,4,15,15,15,15,15,2,2,9,9,15,15,15,15,2,2,9,9,15,15,3,1,1,1,2,2,7,4,4,4,4,7,2,2,1,1,1,3,5,3,5,3,3,3,15,15,15,15,15,15,15,15,15,15,15,15,15,3,5,5,3,4,4,4,4,15,15,15,1,1,1,2,2,2,6,6,2,2,2,1,1,1,6,6,3,1,3,1,3,2,7,7,4,4,7,7,2,3,1,3,1,3,3,3,5,5,3,3,15,15,15,15,15,15,15,15,15,15,1,3,3,10,9,9,10,3,3,1,9,9,9,9,1,1,1,2,2,2,2,6,2,2,2,1,1,1,6,2,3,3,3,3,3,1,7,7,4,7,7,7,1,3,3,3,3,3,3,3,3,5,3,3,15,15,15,15,15,15,15,15,15,15,4,4,4,8,8,8,8,4,4,4,9,9,9,9,2,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,3,3,3,3,1,1,7,4,7,7,4,7,1,1,3,3,3,3,1,5,3,3,3,3,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,3,3,3,3,1,1,7,4,7,4,4,7,1,1,3,3,3,3,1,5,5,3,5,3,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,2,1,1,2,2,2,2,2,2,2,2,1,1,2,2,2,3,1,3,1,1,2,7,7,7,4,7,7,2,1,1,3,1,3,3,3,5,3,5,1,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,7,11,9,9,11,11,7,7,11,11,9,9,11,7,7,7,1,1,1,1,2,2,2,7,7,7,7,2,2,2,1,1,1,1,1,3,3,5,3,1,15,15,15,15,15,15,15,15,15,15};

const uint8_t FoxTex::rgbColors[] PROGMEM = {0,0,0,204,105,32,176,81,34,226,124,33,213,182,159,231,143,65,142,63,36,180,143,131,249,244,244,6,4,14,231,217,211,86,63,52,0,0,0,0,0,0,0,0,0,0,0,0};


#include "../Render/Object3D.h"
#include "../Materials/SimpleMaterial.h"

class Fox{
private:
	Vector3D basisVertices[112] = {Vector3D(0.1875f,0.6875f,-0.1875f),Vector3D(0.1875f,0.3125f,-0.1875f),Vector3D(0.1875f,0.6875f,0.5000f),Vector3D(0.1875f,0.3125f,0.5000f),Vector3D(-0.1875f,0.3125f,-0.1875f),Vector3D(-0.1875f,0.6875f,-0.1875f),Vector3D(-0.1875f,0.3125f,0.5000f),Vector3D(-0.1875f,0.6875f,0.5000f),Vector3D(0.2500f,0.6250f,-0.1875f),Vector3D(0.2500f,0.6250f,-0.5625f),Vector3D(0.2500f,0.2500f,-0.1875f),Vector3D(0.2500f,0.2500f,-0.5625f),Vector3D(-0.2500f,0.6250f,-0.5625f),Vector3D(-0.2500f,0.6250f,-0.1875f),Vector3D(-0.2500f,0.2500f,-0.5625f),Vector3D(-0.2500f,0.2500f,-0.1875f),Vector3D(0.2500f,0.7500f,-0.4375f),Vector3D(0.2500f,0.7500f,-0.5000f),Vector3D(0.2500f,0.6250f,-0.4375f),Vector3D(0.2500f,0.6250f,-0.5000f),Vector3D(0.1250f,0.7500f,-0.5000f),Vector3D(0.1250f,0.7500f,-0.4375f),Vector3D(0.1250f,0.6250f,-0.5000f),Vector3D(0.1250f,0.6250f,-0.4375f),Vector3D(-0.1250f,0.7500f,-0.4375f),Vector3D(-0.1250f,0.7500f,-0.5000f),Vector3D(-0.1250f,0.6250f,-0.4375f),Vector3D(-0.1250f,0.6250f,-0.5000f),Vector3D(-0.2500f,0.7500f,-0.5000f),Vector3D(-0.2500f,0.7500f,-0.4375f),Vector3D(-0.2500f,0.6250f,-0.5000f),Vector3D(-0.2500f,0.6250f,-0.4375f),Vector3D(0.1250f,0.3750f,-0.5625f),Vector3D(0.1250f,0.3750f,-0.7500f),Vector3D(0.1250f,0.2500f,-0.5625f),Vector3D(0.1250f,0.2500f,-0.7500f),Vector3D(-0.1250f,0.3750f,-0.7500f),Vector3D(-0.1250f,0.3750f,-0.5625f),Vector3D(-0.1250f,0.2500f,-0.7500f),Vector3D(-0.1250f,0.2500f,-0.5625f),Vector3D(0.2500f,0.6250f,-0.1875f),Vector3D(0.2500f,0.6250f,-0.5625f),Vector3D(0.2500f,0.2500f,-0.1875f),Vector3D(0.2500f,0.2500f,-0.5625f),Vector3D(-0.2500f,0.6250f,-0.5625f),Vector3D(-0.2500f,0.6250f,-0.1875f),Vector3D(-0.2500f,0.2500f,-0.5625f),Vector3D(-0.2500f,0.2500f,-0.1875f),Vector3D(0.2500f,0.7500f,-0.4375f),Vector3D(0.2500f,0.7500f,-0.5000f),Vector3D(0.2500f,0.6250f,-0.4375f),Vector3D(0.2500f,0.6250f,-0.5000f),Vector3D(0.1250f,0.7500f,-0.5000f),Vector3D(0.1250f,0.7500f,-0.4375f),Vector3D(0.1250f,0.6250f,-0.5000f),Vector3D(0.1250f,0.6250f,-0.4375f),Vector3D(-0.1250f,0.7500f,-0.4375f),Vector3D(-0.1250f,0.7500f,-0.5000f),Vector3D(-0.1250f,0.6250f,-0.4375f),Vector3D(-0.1250f,0.6250f,-0.5000f),Vector3D(-0.2500f,0.7500f,-0.5000f),Vector3D(-0.2500f,0.7500f,-0.4375f),Vector3D(-0.2500f,0.6250f,-0.5000f),Vector3D(-0.2500f,0.6250f,-0.4375f),Vector3D(0.1250f,0.3750f,-0.5625f),Vector3D(0.1250f,0.3750f,-0.7500f),Vector3D(0.1250f,0.2500f,-0.5625f),Vector3D(0.1250f,0.2500f,-0.7500f),Vector3D(-0.1250f,0.3750f,-0.7500f),Vector3D(-0.1250f,0.3750f,-0.5625f),Vector3D(-0.1250f,0.2500f,-0.7500f),Vector3D(-0.1250f,0.2500f,-0.5625f),Vector3D(0.1878f,0.3750f,0.4375f),Vector3D(0.1878f,0.3750f,0.3125f),Vector3D(0.1878f,0.0000f,0.4375f),Vector3D(0.1878f,0.0000f,0.3125f),Vector3D(0.0628f,0.3750f,0.3125f),Vector3D(0.0628f,0.3750f,0.4375f),Vector3D(0.0628f,0.0000f,0.3125f),Vector3D(0.0628f,0.0000f,0.4375f),Vector3D(-0.0628f,0.3750f,0.4375f),Vector3D(-0.0628f,0.3750f,0.3125f),Vector3D(-0.0628f,0.0000f,0.4375f),Vector3D(-0.0628f,0.0000f,0.3125f),Vector3D(-0.1878f,0.3750f,0.3125f),Vector3D(-0.1878f,0.3750f,0.4375f),Vector3D(-0.1878f,0.0000f,0.3125f),Vector3D(-0.1878f,0.0000f,0.4375f),Vector3D(0.1878f,0.3750f,0.0000f),Vector3D(0.1878f,0.3750f,-0.1250f),Vector3D(0.1878f,0.0000f,0.0000f),Vector3D(0.1878f,0.0000f,-0.1250f),Vector3D(0.0628f,0.3750f,-0.1250f),Vector3D(0.0628f,0.3750f,0.0000f),Vector3D(0.0628f,0.0000f,-0.1250f),Vector3D(0.0628f,0.0000f,0.0000f),Vector3D(-0.0628f,0.3750f,0.0000f),Vector3D(-0.0628f,0.3750f,-0.1250f),Vector3D(-0.0628f,0.0000f,0.0000f),Vector3D(-0.0628f,0.0000f,-0.1250f),Vector3D(-0.1878f,0.3750f,-0.1250f),Vector3D(-0.1878f,0.3750f,0.0000f),Vector3D(-0.1878f,0.0000f,-0.1250f),Vector3D(-0.1878f,0.0000f,0.0000f),Vector3D(0.1250f,0.6719f,0.5000f),Vector3D(0.1250f,0.3594f,0.5000f),Vector3D(0.1250f,0.6719f,1.0625f),Vector3D(0.1250f,0.3594f,1.0625f),Vector3D(-0.1250f,0.3594f,0.5000f),Vector3D(-0.1250f,0.6719f,0.5000f),Vector3D(-0.1250f,0.3594f,1.0625f),Vector3D(-0.1250f,0.6719f,1.0625f)};
	IndexGroup basisIndexes[168] = {IndexGroup(0,2,1),IndexGroup(2,3,1),IndexGroup(4,6,5),IndexGroup(6,7,5),IndexGroup(4,5,1),IndexGroup(5,0,1),IndexGroup(7,6,2),IndexGroup(6,3,2),IndexGroup(5,7,0),IndexGroup(7,2,0),IndexGroup(1,3,4),IndexGroup(3,6,4),IndexGroup(8,10,9),IndexGroup(10,11,9),IndexGroup(12,14,13),IndexGroup(14,15,13),IndexGroup(12,13,9),IndexGroup(13,8,9),IndexGroup(15,14,10),IndexGroup(14,11,10),IndexGroup(13,15,8),IndexGroup(15,10,8),IndexGroup(9,11,12),IndexGroup(11,14,12),IndexGroup(16,18,17),IndexGroup(18,19,17),IndexGroup(20,22,21),IndexGroup(22,23,21),IndexGroup(20,21,17),IndexGroup(21,16,17),IndexGroup(23,22,18),IndexGroup(22,19,18),IndexGroup(21,23,16),IndexGroup(23,18,16),IndexGroup(17,19,20),IndexGroup(19,22,20),IndexGroup(24,26,25),IndexGroup(26,27,25),IndexGroup(28,30,29),IndexGroup(30,31,29),IndexGroup(28,29,25),IndexGroup(29,24,25),IndexGroup(31,30,26),IndexGroup(30,27,26),IndexGroup(29,31,24),IndexGroup(31,26,24),IndexGroup(25,27,28),IndexGroup(27,30,28),IndexGroup(32,34,33),IndexGroup(34,35,33),IndexGroup(36,38,37),IndexGroup(38,39,37),IndexGroup(36,37,33),IndexGroup(37,32,33),IndexGroup(39,38,34),IndexGroup(38,35,34),IndexGroup(37,39,32),IndexGroup(39,34,32),IndexGroup(33,35,36),IndexGroup(35,38,36),IndexGroup(40,42,41),IndexGroup(42,43,41),IndexGroup(44,46,45),IndexGroup(46,47,45),IndexGroup(44,45,41),IndexGroup(45,40,41),IndexGroup(47,46,42),IndexGroup(46,43,42),IndexGroup(45,47,40),IndexGroup(47,42,40),IndexGroup(41,43,44),IndexGroup(43,46,44),IndexGroup(48,50,49),IndexGroup(50,51,49),IndexGroup(52,54,53),IndexGroup(54,55,53),IndexGroup(52,53,49),IndexGroup(53,48,49),IndexGroup(55,54,50),IndexGroup(54,51,50),IndexGroup(53,55,48),IndexGroup(55,50,48),IndexGroup(49,51,52),IndexGroup(51,54,52),IndexGroup(56,58,57),IndexGroup(58,59,57),IndexGroup(60,62,61),IndexGroup(62,63,61),IndexGroup(60,61,57),IndexGroup(61,56,57),IndexGroup(63,62,58),IndexGroup(62,59,58),IndexGroup(61,63,56),IndexGroup(63,58,56),IndexGroup(57,59,60),IndexGroup(59,62,60),IndexGroup(64,66,65),IndexGroup(66,67,65),IndexGroup(68,70,69),IndexGroup(70,71,69),IndexGroup(68,69,65),IndexGroup(69,64,65),IndexGroup(71,70,66),IndexGroup(70,67,66),IndexGroup(69,71,64),IndexGroup(71,66,64),IndexGroup(65,67,68),IndexGroup(67,70,68),IndexGroup(72,74,73),IndexGroup(74,75,73),IndexGroup(76,78,77),IndexGroup(78,79,77),IndexGroup(76,77,73),IndexGroup(77,72,73),IndexGroup(79,78,74),IndexGroup(78,75,74),IndexGroup(77,79,72),IndexGroup(79,74,72),IndexGroup(73,75,76),IndexGroup(75,78,76),IndexGroup(80,82,81),IndexGroup(82,83,81),IndexGroup(84,86,85),IndexGroup(86,87,85),IndexGroup(84,85,81),IndexGroup(85,80,81),IndexGroup(87,86,82),IndexGroup(86,83,82),IndexGroup(85,87,80),IndexGroup(87,82,80),IndexGroup(81,83,84),IndexGroup(83,86,84),IndexGroup(88,90,89),IndexGroup(90,91,89),IndexGroup(92,94,93),IndexGroup(94,95,93),IndexGroup(92,93,89),IndexGroup(93,88,89),IndexGroup(95,94,90),IndexGroup(94,91,90),IndexGroup(93,95,88),IndexGroup(95,90,88),IndexGroup(89,91,92),IndexGroup(91,94,92),IndexGroup(96,98,97),IndexGroup(98,99,97),IndexGroup(100,102,101),IndexGroup(102,103,101),IndexGroup(100,101,97),IndexGroup(101,96,97),IndexGroup(103,102,98),IndexGroup(102,99,98),IndexGroup(101,103,96),IndexGroup(103,98,96),IndexGroup(97,99,100),IndexGroup(99,102,100),IndexGroup(104,106,105),IndexGroup(106,107,105),IndexGroup(108,110,109),IndexGroup(110,111,109),IndexGroup(108,109,105),IndexGroup(109,104,105),IndexGroup(111,110,106),IndexGroup(110,107,106),IndexGroup(109,111,104),IndexGroup(111,106,104),IndexGroup(105,107,108),IndexGroup(107,110,108)};
	Vector2D uvVertices[504] = {Vector2D(0.4690f,0.3433f),Vector2D(0.4690f,0.0005f),Vector2D(0.5623f,0.3433f),Vector2D(0.4690f,0.0005f),Vector2D(0.5623f,0.0005f),Vector2D(0.5623f,0.3433f),Vector2D(0.6565f,0.3433f),Vector2D(0.6565f,0.0005f),Vector2D(0.7498f,0.3433f),Vector2D(0.6565f,0.0005f),Vector2D(0.7498f,0.0005f),Vector2D(0.7498f,0.3433f),Vector2D(0.6560f,0.3442f),Vector2D(0.6560f,0.5308f),Vector2D(0.5627f,0.3442f),Vector2D(0.6560f,0.5308f),Vector2D(0.5627f,0.5308f),Vector2D(0.5627f,0.3442f),Vector2D(0.7498f,0.5308f),Vector2D(0.7498f,0.3442f),Vector2D(0.6565f,0.5308f),Vector2D(0.7498f,0.3442f),Vector2D(0.6565f,0.3442f),Vector2D(0.6565f,0.5308f),Vector2D(0.7502f,0.3433f),Vector2D(0.7502f,0.0005f),Vector2D(0.8435f,0.3433f),Vector2D(0.7502f,0.0005f),Vector2D(0.8435f,0.0005f),Vector2D(0.8435f,0.3433f),Vector2D(0.5627f,0.3433f),Vector2D(0.5627f,0.0005f),Vector2D(0.6560f,0.3433f),Vector2D(0.5627f,0.0005f),Vector2D(0.6560f,0.0005f),Vector2D(0.6560f,0.3433f),Vector2D(0.0002f,0.8120f),Vector2D(0.0002f,0.6255f),Vector2D(0.0935f,0.8120f),Vector2D(0.0002f,0.6255f),Vector2D(0.0935f,0.6255f),Vector2D(0.0935f,0.8120f),Vector2D(0.2190f,0.8120f),Vector2D(0.2190f,0.6255f),Vector2D(0.3123f,0.8120f),Vector2D(0.2190f,0.6255f),Vector2D(0.3123f,0.6255f),Vector2D(0.3123f,0.8120f),Vector2D(0.2185f,0.8130f),Vector2D(0.2185f,0.9995f),Vector2D(0.0940f,0.8130f),Vector2D(0.2185f,0.9995f),Vector2D(0.0940f,0.9995f),Vector2D(0.0940f,0.8130f),Vector2D(0.3435f,0.9995f),Vector2D(0.3435f,0.8130f),Vector2D(0.2190f,0.9995f),Vector2D(0.3435f,0.8130f),Vector2D(0.2190f,0.8130f),Vector2D(0.2190f,0.9995f),Vector2D(0.3127f,0.8120f),Vector2D(0.3127f,0.6255f),Vector2D(0.4373f,0.8120f),Vector2D(0.3127f,0.6255f),Vector2D(0.4373f,0.6255f),Vector2D(0.4373f,0.8120f),Vector2D(0.0940f,0.8120f),Vector2D(0.0940f,0.6255f),Vector2D(0.2185f,0.8120f),Vector2D(0.0940f,0.6255f),Vector2D(0.2185f,0.6255f),Vector2D(0.2185f,0.8120f),Vector2D(0.0002f,0.9683f),Vector2D(0.0002f,0.9067f),Vector2D(0.0154f,0.9683f),Vector2D(0.0002f,0.9067f),Vector2D(0.0154f,0.9067f),Vector2D(0.0154f,0.9683f),Vector2D(0.0471f,0.9683f),Vector2D(0.0471f,0.9067f),Vector2D(0.0623f,0.9683f),Vector2D(0.0471f,0.9067f),Vector2D(0.0623f,0.9067f),Vector2D(0.0623f,0.9683f),Vector2D(0.0466f,0.9692f),Vector2D(0.0466f,0.9995f),Vector2D(0.0159f,0.9692f),Vector2D(0.0466f,0.9995f),Vector2D(0.0159f,0.9995f),Vector2D(0.0159f,0.9692f),Vector2D(0.0779f,0.9995f),Vector2D(0.0779f,0.9692f),Vector2D(0.0471f,0.9995f),Vector2D(0.0779f,0.9692f),Vector2D(0.0471f,0.9692f),Vector2D(0.0471f,0.9995f),Vector2D(0.0627f,0.9683f),Vector2D(0.0627f,0.9067f),Vector2D(0.0935f,0.9683f),Vector2D(0.0627f,0.9067f),Vector2D(0.0935f,0.9067f),Vector2D(0.0935f,0.9683f),Vector2D(0.0159f,0.9683f),Vector2D(0.0159f,0.9067f),Vector2D(0.0466f,0.9683f),Vector2D(0.0159f,0.9067f),Vector2D(0.0466f,0.9067f),Vector2D(0.0466f,0.9683f),Vector2D(0.3440f,0.9683f),Vector2D(0.3440f,0.9067f),Vector2D(0.3591f,0.9683f),Vector2D(0.3440f,0.9067f),Vector2D(0.3591f,0.9067f),Vector2D(0.3591f,0.9683f),Vector2D(0.3909f,0.9683f),Vector2D(0.3909f,0.9067f),Vector2D(0.4060f,0.9683f),Vector2D(0.3909f,0.9067f),Vector2D(0.4060f,0.9067f),Vector2D(0.4060f,0.9683f),Vector2D(0.3904f,0.9692f),Vector2D(0.3904f,0.9995f),Vector2D(0.3596f,0.9692f),Vector2D(0.3904f,0.9995f),Vector2D(0.3596f,0.9995f),Vector2D(0.3596f,0.9692f),Vector2D(0.4216f,0.9995f),Vector2D(0.4216f,0.9692f),Vector2D(0.3909f,0.9995f),Vector2D(0.4216f,0.9692f),Vector2D(0.3909f,0.9692f),Vector2D(0.3909f,0.9995f),Vector2D(0.4065f,0.9683f),Vector2D(0.4065f,0.9067f),Vector2D(0.4373f,0.9683f),Vector2D(0.4065f,0.9067f),Vector2D(0.4373f,0.9067f),Vector2D(0.4373f,0.9683f),Vector2D(0.3596f,0.9683f),Vector2D(0.3596f,0.9067f),Vector2D(0.3904f,0.9683f),Vector2D(0.3596f,0.9067f),Vector2D(0.3904f,0.9067f),Vector2D(0.3904f,0.9683f),Vector2D(0.0002f,0.1558f),Vector2D(0.0002f,0.0942f),Vector2D(0.0466f,0.1558f),Vector2D(0.0002f,0.0942f),Vector2D(0.0466f,0.0942f),Vector2D(0.0466f,0.1558f),Vector2D(0.1096f,0.1558f),Vector2D(0.1096f,0.0942f),Vector2D(0.1560f,0.1558f),Vector2D(0.1096f,0.0942f),Vector2D(0.1560f,0.0942f),Vector2D(0.1560f,0.1558f),Vector2D(0.1091f,0.1567f),Vector2D(0.1091f,0.2495f),Vector2D(0.0471f,0.1567f),Vector2D(0.1091f,0.2495f),Vector2D(0.0471f,0.2495f),Vector2D(0.0471f,0.1567f),Vector2D(0.1716f,0.2495f),Vector2D(0.1716f,0.1567f),Vector2D(0.1096f,0.2495f),Vector2D(0.1716f,0.1567f),Vector2D(0.1096f,0.1567f),Vector2D(0.1096f,0.2495f),Vector2D(0.1565f,0.1558f),Vector2D(0.1565f,0.0942f),Vector2D(0.2185f,0.1558f),Vector2D(0.1565f,0.0942f),Vector2D(0.2185f,0.0942f),Vector2D(0.2185f,0.1558f),Vector2D(0.0471f,0.1558f),Vector2D(0.0471f,0.0942f),Vector2D(0.1091f,0.1558f),Vector2D(0.0471f,0.0942f),Vector2D(0.1091f,0.0942f),Vector2D(0.1091f,0.1558f),Vector2D(0.0002f,0.4370f),Vector2D(0.0002f,0.2505f),Vector2D(0.0935f,0.4370f),Vector2D(0.0002f,0.2505f),Vector2D(0.0935f,0.2505f),Vector2D(0.0935f,0.4370f),Vector2D(0.2190f,0.4370f),Vector2D(0.2190f,0.2505f),Vector2D(0.3123f,0.4370f),Vector2D(0.2190f,0.2505f),Vector2D(0.3123f,0.2505f),Vector2D(0.3123f,0.4370f),Vector2D(0.2185f,0.4380f),Vector2D(0.2185f,0.6245f),Vector2D(0.0940f,0.4380f),Vector2D(0.2185f,0.6245f),Vector2D(0.0940f,0.6245f),Vector2D(0.0940f,0.4380f),Vector2D(0.3435f,0.6245f),Vector2D(0.3435f,0.4380f),Vector2D(0.2190f,0.6245f),Vector2D(0.3435f,0.4380f),Vector2D(0.2190f,0.4380f),Vector2D(0.2190f,0.6245f),Vector2D(0.3127f,0.4370f),Vector2D(0.3127f,0.2505f),Vector2D(0.4373f,0.4370f),Vector2D(0.3127f,0.2505f),Vector2D(0.4373f,0.2505f),Vector2D(0.4373f,0.4370f),Vector2D(0.0940f,0.4370f),Vector2D(0.0940f,0.2505f),Vector2D(0.2185f,0.4370f),Vector2D(0.0940f,0.2505f),Vector2D(0.2185f,0.2505f),Vector2D(0.2185f,0.4370f),Vector2D(0.0002f,0.9683f),Vector2D(0.0002f,0.9067f),Vector2D(0.0154f,0.9683f),Vector2D(0.0002f,0.9067f),Vector2D(0.0154f,0.9067f),Vector2D(0.0154f,0.9683f),Vector2D(0.0471f,0.9683f),Vector2D(0.0471f,0.9067f),Vector2D(0.0623f,0.9683f),Vector2D(0.0471f,0.9067f),Vector2D(0.0623f,0.9067f),Vector2D(0.0623f,0.9683f),Vector2D(0.0466f,0.9692f),Vector2D(0.0466f,0.9995f),Vector2D(0.0159f,0.9692f),Vector2D(0.0466f,0.9995f),Vector2D(0.0159f,0.9995f),Vector2D(0.0159f,0.9692f),Vector2D(0.0779f,0.9995f),Vector2D(0.0779f,0.9692f),Vector2D(0.0471f,0.9995f),Vector2D(0.0779f,0.9692f),Vector2D(0.0471f,0.9692f),Vector2D(0.0471f,0.9995f),Vector2D(0.0627f,0.9683f),Vector2D(0.0627f,0.9067f),Vector2D(0.0935f,0.9683f),Vector2D(0.0627f,0.9067f),Vector2D(0.0935f,0.9067f),Vector2D(0.0935f,0.9683f),Vector2D(0.0159f,0.9683f),Vector2D(0.0159f,0.9067f),Vector2D(0.0466f,0.9683f),Vector2D(0.0159f,0.9067f),Vector2D(0.0466f,0.9067f),Vector2D(0.0466f,0.9683f),Vector2D(0.3440f,0.9683f),Vector2D(0.3440f,0.9067f),Vector2D(0.3591f,0.9683f),Vector2D(0.3440f,0.9067f),Vector2D(0.3591f,0.9067f),Vector2D(0.3591f,0.9683f),Vector2D(0.3909f,0.9683f),Vector2D(0.3909f,0.9067f),Vector2D(0.4060f,0.9683f),Vector2D(0.3909f,0.9067f),Vector2D(0.4060f,0.9067f),Vector2D(0.4060f,0.9683f),Vector2D(0.3904f,0.9692f),Vector2D(0.3904f,0.9995f),Vector2D(0.3596f,0.9692f),Vector2D(0.3904f,0.9995f),Vector2D(0.3596f,0.9995f),Vector2D(0.3596f,0.9692f),Vector2D(0.4216f,0.9995f),Vector2D(0.4216f,0.9692f),Vector2D(0.3909f,0.9995f),Vector2D(0.4216f,0.9692f),Vector2D(0.3909f,0.9692f),Vector2D(0.3909f,0.9995f),Vector2D(0.4065f,0.9683f),Vector2D(0.4065f,0.9067f),Vector2D(0.4373f,0.9683f),Vector2D(0.4065f,0.9067f),Vector2D(0.4373f,0.9067f),Vector2D(0.4373f,0.9683f),Vector2D(0.3596f,0.9683f),Vector2D(0.3596f,0.9067f),Vector2D(0.3904f,0.9683f),Vector2D(0.3596f,0.9067f),Vector2D(0.3904f,0.9067f),Vector2D(0.3904f,0.9683f),Vector2D(0.0002f,0.1558f),Vector2D(0.0002f,0.0942f),Vector2D(0.0466f,0.1558f),Vector2D(0.0002f,0.0942f),Vector2D(0.0466f,0.0942f),Vector2D(0.0466f,0.1558f),Vector2D(0.1096f,0.1558f),Vector2D(0.1096f,0.0942f),Vector2D(0.1560f,0.1558f),Vector2D(0.1096f,0.0942f),Vector2D(0.1560f,0.0942f),Vector2D(0.1560f,0.1558f),Vector2D(0.1091f,0.1567f),Vector2D(0.1091f,0.2495f),Vector2D(0.0471f,0.1567f),Vector2D(0.1091f,0.2495f),Vector2D(0.0471f,0.2495f),Vector2D(0.0471f,0.1567f),Vector2D(0.1716f,0.2495f),Vector2D(0.1716f,0.1567f),Vector2D(0.1096f,0.2495f),Vector2D(0.1716f,0.1567f),Vector2D(0.1096f,0.1567f),Vector2D(0.1096f,0.2495f),Vector2D(0.1565f,0.1558f),Vector2D(0.1565f,0.0942f),Vector2D(0.2185f,0.1558f),Vector2D(0.1565f,0.0942f),Vector2D(0.2185f,0.0942f),Vector2D(0.2185f,0.1558f),Vector2D(0.0471f,0.1558f),Vector2D(0.0471f,0.0942f),Vector2D(0.1091f,0.1558f),Vector2D(0.0471f,0.0942f),Vector2D(0.1091f,0.0942f),Vector2D(0.1091f,0.1558f),Vector2D(0.2190f,0.1870f),Vector2D(0.2190f,0.0005f),Vector2D(0.2498f,0.1870f),Vector2D(0.2190f,0.0005f),Vector2D(0.2498f,0.0005f),Vector2D(0.2498f,0.1870f),Vector2D(0.2815f,0.1870f),Vector2D(0.2815f,0.0005f),Vector2D(0.3123f,0.1870f),Vector2D(0.2815f,0.0005f),Vector2D(0.3123f,0.0005f),Vector2D(0.3123f,0.1870f),Vector2D(0.2810f,0.1880f),Vector2D(0.2810f,0.2495f),Vector2D(0.2502f,0.1880f),Vector2D(0.2810f,0.2495f),Vector2D(0.2502f,0.2495f),Vector2D(0.2502f,0.1880f),Vector2D(0.3123f,0.2495f),Vector2D(0.3123f,0.1880f),Vector2D(0.2815f,0.2495f),Vector2D(0.3123f,0.1880f),Vector2D(0.2815f,0.1880f),Vector2D(0.2815f,0.2495f),Vector2D(0.3127f,0.1870f),Vector2D(0.3127f,0.0005f),Vector2D(0.3435f,0.1870f),Vector2D(0.3127f,0.0005f),Vector2D(0.3435f,0.0005f),Vector2D(0.3435f,0.1870f),Vector2D(0.2502f,0.1870f),Vector2D(0.2502f,0.0005f),Vector2D(0.2810f,0.1870f),Vector2D(0.2502f,0.0005f),Vector2D(0.2810f,0.0005f),Vector2D(0.2810f,0.1870f),Vector2D(0.3440f,0.1870f),Vector2D(0.3440f,0.0005f),Vector2D(0.3748f,0.1870f),Vector2D(0.3440f,0.0005f),Vector2D(0.3748f,0.0005f),Vector2D(0.3748f,0.1870f),Vector2D(0.4065f,0.1870f),Vector2D(0.4065f,0.0005f),Vector2D(0.4373f,0.1870f),Vector2D(0.4065f,0.0005f),Vector2D(0.4373f,0.0005f),Vector2D(0.4373f,0.1870f),Vector2D(0.4060f,0.1880f),Vector2D(0.4060f,0.2495f),Vector2D(0.3752f,0.1880f),Vector2D(0.4060f,0.2495f),Vector2D(0.3752f,0.2495f),Vector2D(0.3752f,0.1880f),Vector2D(0.4373f,0.2495f),Vector2D(0.4373f,0.1880f),Vector2D(0.4065f,0.2495f),Vector2D(0.4373f,0.1880f),Vector2D(0.4065f,0.1880f),Vector2D(0.4065f,0.2495f),Vector2D(0.4377f,0.1870f),Vector2D(0.4377f,0.0005f),Vector2D(0.4685f,0.1870f),Vector2D(0.4377f,0.0005f),Vector2D(0.4685f,0.0005f),Vector2D(0.4685f,0.1870f),Vector2D(0.3752f,0.1870f),Vector2D(0.3752f,0.0005f),Vector2D(0.4060f,0.1870f),Vector2D(0.3752f,0.0005f),Vector2D(0.4060f,0.0005f),Vector2D(0.4060f,0.1870f),Vector2D(0.2190f,0.1870f),Vector2D(0.2190f,0.0005f),Vector2D(0.2498f,0.1870f),Vector2D(0.2190f,0.0005f),Vector2D(0.2498f,0.0005f),Vector2D(0.2498f,0.1870f),Vector2D(0.2815f,0.1870f),Vector2D(0.2815f,0.0005f),Vector2D(0.3123f,0.1870f),Vector2D(0.2815f,0.0005f),Vector2D(0.3123f,0.0005f),Vector2D(0.3123f,0.1870f),Vector2D(0.2810f,0.1880f),Vector2D(0.2810f,0.2495f),Vector2D(0.2502f,0.1880f),Vector2D(0.2810f,0.2495f),Vector2D(0.2502f,0.2495f),Vector2D(0.2502f,0.1880f),Vector2D(0.3123f,0.2495f),Vector2D(0.3123f,0.1880f),Vector2D(0.2815f,0.2495f),Vector2D(0.3123f,0.1880f),Vector2D(0.2815f,0.1880f),Vector2D(0.2815f,0.2495f),Vector2D(0.3127f,0.1870f),Vector2D(0.3127f,0.0005f),Vector2D(0.3435f,0.1870f),Vector2D(0.3127f,0.0005f),Vector2D(0.3435f,0.0005f),Vector2D(0.3435f,0.1870f),Vector2D(0.2502f,0.1870f),Vector2D(0.2502f,0.0005f),Vector2D(0.2810f,0.1870f),Vector2D(0.2502f,0.0005f),Vector2D(0.2810f,0.0005f),Vector2D(0.2810f,0.1870f),Vector2D(0.3440f,0.1870f),Vector2D(0.3440f,0.0005f),Vector2D(0.3748f,0.1870f),Vector2D(0.3440f,0.0005f),Vector2D(0.3748f,0.0005f),Vector2D(0.3748f,0.1870f),Vector2D(0.4065f,0.1870f),Vector2D(0.4065f,0.0005f),Vector2D(0.4373f,0.1870f),Vector2D(0.4065f,0.0005f),Vector2D(0.4373f,0.0005f),Vector2D(0.4373f,0.1870f),Vector2D(0.4060f,0.1880f),Vector2D(0.4060f,0.2495f),Vector2D(0.3752f,0.1880f),Vector2D(0.4060f,0.2495f),Vector2D(0.3752f,0.2495f),Vector2D(0.3752f,0.1880f),Vector2D(0.4373f,0.2495f),Vector2D(0.4373f,0.1880f),Vector2D(0.4065f,0.2495f),Vector2D(0.4373f,0.1880f),Vector2D(0.4065f,0.1880f),Vector2D(0.4065f,0.2495f),Vector2D(0.4377f,0.1870f),Vector2D(0.4377f,0.0005f),Vector2D(0.4685f,0.1870f),Vector2D(0.4377f,0.0005f),Vector2D(0.4685f,0.0005f),Vector2D(0.4685f,0.1870f),Vector2D(0.3752f,0.1870f),Vector2D(0.3752f,0.0005f),Vector2D(0.4060f,0.1870f),Vector2D(0.3752f,0.0005f),Vector2D(0.4060f,0.0005f),Vector2D(0.4060f,0.1870f),Vector2D(0.4377f,0.8433f),Vector2D(0.4377f,0.5630f),Vector2D(0.5154f,0.8433f),Vector2D(0.4377f,0.5630f),Vector2D(0.5154f,0.5630f),Vector2D(0.5154f,0.8433f),Vector2D(0.5784f,0.8433f),Vector2D(0.5784f,0.5630f),Vector2D(0.6560f,0.8433f),Vector2D(0.5784f,0.5630f),Vector2D(0.6560f,0.5630f),Vector2D(0.6560f,0.8433f),Vector2D(0.5779f,0.8442f),Vector2D(0.5779f,0.9995f),Vector2D(0.5159f,0.8442f),Vector2D(0.5779f,0.9995f),Vector2D(0.5159f,0.9995f),Vector2D(0.5159f,0.8442f),Vector2D(0.6404f,0.9995f),Vector2D(0.6404f,0.8442f),Vector2D(0.5784f,0.9995f),Vector2D(0.6404f,0.8442f),Vector2D(0.5784f,0.8442f),Vector2D(0.5784f,0.9995f),Vector2D(0.6565f,0.8433f),Vector2D(0.6565f,0.5630f),Vector2D(0.7185f,0.8433f),Vector2D(0.6565f,0.5630f),Vector2D(0.7185f,0.5630f),Vector2D(0.7185f,0.8433f),Vector2D(0.5159f,0.8433f),Vector2D(0.5159f,0.5630f),Vector2D(0.5779f,0.8433f),Vector2D(0.5159f,0.5630f),Vector2D(0.5779f,0.5630f),Vector2D(0.5779f,0.8433f)};
	IndexGroup uvIndexGroup[168] = {IndexGroup(0,1,2),IndexGroup(3,4,5),IndexGroup(6,7,8),IndexGroup(9,10,11),IndexGroup(12,13,14),IndexGroup(15,16,17),IndexGroup(18,19,20),IndexGroup(21,22,23),IndexGroup(24,25,26),IndexGroup(27,28,29),IndexGroup(30,31,32),IndexGroup(33,34,35),IndexGroup(36,37,38),IndexGroup(39,40,41),IndexGroup(42,43,44),IndexGroup(45,46,47),IndexGroup(48,49,50),IndexGroup(51,52,53),IndexGroup(54,55,56),IndexGroup(57,58,59),IndexGroup(60,61,62),IndexGroup(63,64,65),IndexGroup(66,67,68),IndexGroup(69,70,71),IndexGroup(72,73,74),IndexGroup(75,76,77),IndexGroup(78,79,80),IndexGroup(81,82,83),IndexGroup(84,85,86),IndexGroup(87,88,89),IndexGroup(90,91,92),IndexGroup(93,94,95),IndexGroup(96,97,98),IndexGroup(99,100,101),IndexGroup(102,103,104),IndexGroup(105,106,107),IndexGroup(108,109,110),IndexGroup(111,112,113),IndexGroup(114,115,116),IndexGroup(117,118,119),IndexGroup(120,121,122),IndexGroup(123,124,125),IndexGroup(126,127,128),IndexGroup(129,130,131),IndexGroup(132,133,134),IndexGroup(135,136,137),IndexGroup(138,139,140),IndexGroup(141,142,143),IndexGroup(144,145,146),IndexGroup(147,148,149),IndexGroup(150,151,152),IndexGroup(153,154,155),IndexGroup(156,157,158),IndexGroup(159,160,161),IndexGroup(162,163,164),IndexGroup(165,166,167),IndexGroup(168,169,170),IndexGroup(171,172,173),IndexGroup(174,175,176),IndexGroup(177,178,179),IndexGroup(180,181,182),IndexGroup(183,184,185),IndexGroup(186,187,188),IndexGroup(189,190,191),IndexGroup(192,193,194),IndexGroup(195,196,197),IndexGroup(198,199,200),IndexGroup(201,202,203),IndexGroup(204,205,206),IndexGroup(207,208,209),IndexGroup(210,211,212),IndexGroup(213,214,215),IndexGroup(216,217,218),IndexGroup(219,220,221),IndexGroup(222,223,224),IndexGroup(225,226,227),IndexGroup(228,229,230),IndexGroup(231,232,233),IndexGroup(234,235,236),IndexGroup(237,238,239),IndexGroup(240,241,242),IndexGroup(243,244,245),IndexGroup(246,247,248),IndexGroup(249,250,251),IndexGroup(252,253,254),IndexGroup(255,256,257),IndexGroup(258,259,260),IndexGroup(261,262,263),IndexGroup(264,265,266),IndexGroup(267,268,269),IndexGroup(270,271,272),IndexGroup(273,274,275),IndexGroup(276,277,278),IndexGroup(279,280,281),IndexGroup(282,283,284),IndexGroup(285,286,287),IndexGroup(288,289,290),IndexGroup(291,292,293),IndexGroup(294,295,296),IndexGroup(297,298,299),IndexGroup(300,301,302),IndexGroup(303,304,305),IndexGroup(306,307,308),IndexGroup(309,310,311),IndexGroup(312,313,314),IndexGroup(315,316,317),IndexGroup(318,319,320),IndexGroup(321,322,323),IndexGroup(324,325,326),IndexGroup(327,328,329),IndexGroup(330,331,332),IndexGroup(333,334,335),IndexGroup(336,337,338),IndexGroup(339,340,341),IndexGroup(342,343,344),IndexGroup(345,346,347),IndexGroup(348,349,350),IndexGroup(351,352,353),IndexGroup(354,355,356),IndexGroup(357,358,359),IndexGroup(360,361,362),IndexGroup(363,364,365),IndexGroup(366,367,368),IndexGroup(369,370,371),IndexGroup(372,373,374),IndexGroup(375,376,377),IndexGroup(378,379,380),IndexGroup(381,382,383),IndexGroup(384,385,386),IndexGroup(387,388,389),IndexGroup(390,391,392),IndexGroup(393,394,395),IndexGroup(396,397,398),IndexGroup(399,400,401),IndexGroup(402,403,404),IndexGroup(405,406,407),IndexGroup(408,409,410),IndexGroup(411,412,413),IndexGroup(414,415,416),IndexGroup(417,418,419),IndexGroup(420,421,422),IndexGroup(423,424,425),IndexGroup(426,427,428),IndexGroup(429,430,431),IndexGroup(432,433,434),IndexGroup(435,436,437),IndexGroup(438,439,440),IndexGroup(441,442,443),IndexGroup(444,445,446),IndexGroup(447,448,449),IndexGroup(450,451,452),IndexGroup(453,454,455),IndexGroup(456,457,458),IndexGroup(459,460,461),IndexGroup(462,463,464),IndexGroup(465,466,467),IndexGroup(468,469,470),IndexGroup(471,472,473),IndexGroup(474,475,476),IndexGroup(477,478,479),IndexGroup(480,481,482),IndexGroup(483,484,485),IndexGroup(486,487,488),IndexGroup(489,490,491),IndexGroup(492,493,494),IndexGroup(495,496,497),IndexGroup(498,499,500),IndexGroup(501,502,503)};
	TriangleGroup triangleGroup = TriangleGroup(basisVertices, basisIndexes, uvIndexGroup, uvVertices, 112, 168, 504);
	FoxTex material = FoxTex(Vector2D(1.0f, 1.0f), Vector2D());
	Object3D basisObj = Object3D(&triangleGroup, &material);

public:
	Fox(){}

	Object3D* GetObject(){
		return &basisObj;
	}
};
