#pragma once

#include "../Math/Rotation.h"
#include "Morph.h"
#include "../Materials/SimpleMaterial.h"
#include "../Render/IndexGroup.h"
#include "../Render/Object3D.h"


class BiasFace{
public:
    enum Morphs {
        Angry,
        Happy,
        BlinkBasis,
        MouthOpen,
        BlinkAngry,
        BlinkHappy
    };

private:
    Vector3D basisVertices[62] = {Vector3D(147.8420f,71.3602f,0.0000f),Vector3D(145.7505f,79.8934f,0.0000f),Vector3D(112.9528f,50.2208f,0.0000f),Vector3D(113.1660f,44.2934f,0.0000f),Vector3D(141.0574f,67.9342f,0.0000f),Vector3D(142.3672f,74.4045f,0.0000f),Vector3D(148.4221f,76.7862f,0.0000f),Vector3D(136.2631f,65.8536f,0.0000f),Vector3D(138.4568f,59.6380f,0.0000f),Vector3D(145.2408f,63.5625f,0.0000f),Vector3D(135.6066f,50.1691f,0.0000f),Vector3D(135.5613f,44.2417f,0.0000f),Vector3D(129.1354f,64.8062f,0.0000f),Vector3D(129.7443f,58.9114f,0.0000f),Vector3D(121.0801f,66.5249f,0.0000f),Vector3D(122.3945f,59.4679f,0.0000f),Vector3D(115.8933f,63.8141f,0.0000f),Vector3D(117.5827f,61.1046f,0.0000f),Vector3D(100.4582f,47.4606f,0.0000f),Vector3D(100.6714f,39.8728f,0.0000f),Vector3D(86.6351f,42.3379f,-0.0000f),Vector3D(86.8483f,34.4396f,-0.0000f),Vector3D(72.1657f,32.9473f,-0.0000f),Vector3D(72.3789f,23.6520f,-0.0000f),Vector3D(63.5128f,24.6535f,-0.0000f),Vector3D(63.7260f,15.3581f,-0.0000f),Vector3D(59.1828f,21.3865f,-0.0000f),Vector3D(59.3672f,15.3219f,-0.0000f),Vector3D(52.2654f,27.6201f,-0.0000f),Vector3D(52.6410f,15.2638f,-0.0000f),Vector3D(43.6853f,35.4208f,-0.0000f),Vector3D(43.9152f,25.0339f,-0.0000f),Vector3D(35.9702f,36.3256f,-0.0000f),Vector3D(36.1198f,28.6439f,-0.0000f),Vector3D(28.8226f,35.3656f,-0.0000f),Vector3D(28.9722f,24.6928f,-0.0000f),Vector3D(23.1128f,30.4537f,-0.0000f),Vector3D(23.2624f,23.8201f,-0.0000f),Vector3D(-0.0753f,30.4537f,-0.0000f),Vector3D(0.0743f,23.7902f,-0.0000f),Vector3D(17.2692f,75.9902f,-0.0000f),Vector3D(-0.2955f,72.4284f,-0.0000f),Vector3D(17.1403f,70.7454f,-0.0000f),Vector3D(3.2699f,61.5486f,-0.0000f),Vector3D(2.5539f,75.4084f,-0.0000f),Vector3D(10.6982f,67.6501f,-0.0000f),Vector3D(3.4512f,67.2031f,-0.0000f),Vector3D(-0.4077f,62.1304f,-0.0000f),Vector3D(112.6795f,78.2299f,0.0000f),Vector3D(112.7401f,69.4154f,0.0000f),Vector3D(142.1706f,84.5094f,0.0000f),Vector3D(135.2540f,88.6762f,0.0000f),Vector3D(138.0691f,80.3514f,0.0000f),Vector3D(117.7637f,73.3618f,0.0000f),Vector3D(115.1493f,83.8009f,0.0000f),Vector3D(118.9049f,80.3965f,0.0000f),Vector3D(122.2754f,89.3233f,0.0000f),Vector3D(122.6319f,83.5771f,0.0000f),Vector3D(129.6006f,89.8303f,0.0000f),Vector3D(130.9140f,83.9215f,0.0000f),Vector3D(111.3113f,73.8933f,0.0000f),Vector3D(138.4385f,87.3853f,0.0000f)};
    IndexGroup basisIndexes[58] = {IndexGroup(0,6,5),IndexGroup(0,4,9),IndexGroup(5,6,1),IndexGroup(5,4,0),IndexGroup(9,4,7),IndexGroup(9,7,8),IndexGroup(8,12,13),IndexGroup(13,12,14),IndexGroup(15,14,17),IndexGroup(14,15,13),IndexGroup(11,10,3),IndexGroup(12,8,7),IndexGroup(3,18,19),IndexGroup(19,18,21),IndexGroup(21,20,22),IndexGroup(23,22,25),IndexGroup(25,26,27),IndexGroup(27,26,29),IndexGroup(29,28,30),IndexGroup(31,30,33),IndexGroup(33,32,34),IndexGroup(35,34,37),IndexGroup(37,38,39),IndexGroup(41,47,43),IndexGroup(41,46,45),IndexGroup(43,46,41),IndexGroup(45,42,44),IndexGroup(44,41,45),IndexGroup(44,42,40),IndexGroup(16,53,49),IndexGroup(5,1,52),IndexGroup(48,53,54),IndexGroup(52,1,50),IndexGroup(50,61,52),IndexGroup(49,53,60),IndexGroup(53,16,14),IndexGroup(54,55,56),IndexGroup(56,57,58),IndexGroup(58,59,51),IndexGroup(51,59,52),IndexGroup(58,57,59),IndexGroup(56,55,57),IndexGroup(54,53,55),IndexGroup(17,14,16),IndexGroup(60,53,48),IndexGroup(52,61,51),IndexGroup(18,3,2),IndexGroup(33,30,32),IndexGroup(26,25,24),IndexGroup(21,18,20),IndexGroup(34,35,33),IndexGroup(3,10,2),IndexGroup(29,26,28),IndexGroup(22,23,21),IndexGroup(30,31,29),IndexGroup(25,22,24),IndexGroup(38,37,36),IndexGroup(37,34,36)};
    TriangleGroup triangleGroup = TriangleGroup(&basisVertices[0], &basisIndexes[0], 62, 58);
    SimpleMaterial simpleMaterial = SimpleMaterial(RGBColor(128, 128, 128));
    Object3D basisObj = Object3D(&triangleGroup, &simpleMaterial);

    static const uint8_t morphCount = 6;
    int AngryIndexes[28] = {0,1,4,5,6,7,8,9,12,13,14,15,16,17,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
    int HappyIndexes[28] = {0,1,4,5,6,7,8,9,12,13,14,15,16,17,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
    int BlinkBasisIndexes[28] = {0,1,4,5,6,7,8,9,12,13,14,15,16,17,48,49,50,51,52,53,54,55,56,57,58,59,60,61};
    int MouthOpenIndexes[24] = {2,3,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39};
    int BlinkAngryIndexes[18] = {0,1,6,8,9,13,15,16,17,48,49,50,51,54,56,58,60,61};
    int BlinkHappyIndexes[28] = {0,1,4,5,6,7,8,9,12,13,14,15,16,17,48,49,50,51,52,53,54,55,56,57,58,59,60,61};

    Vector3D AngryVectors[28] = {Vector3D(-5.6303f,-2.2743f,0.0000f),Vector3D(-1.5742f,3.9741f,0.0000f),Vector3D(-6.8673f,2.2180f,0.0000f),Vector3D(-4.4819f,0.9915f,0.0000f),Vector3D(-3.6988f,-0.7919f,0.0000f),Vector3D(-5.7084f,0.5038f,0.0000f),Vector3D(-4.4328f,0.8981f,0.0000f),Vector3D(-6.5333f,1.4776f,0.0000f),Vector3D(-4.8296f,-3.1323f,0.0000f),Vector3D(-4.1334f,-3.1484f,0.0000f),Vector3D(-5.5780f,-6.4158f,0.0000f),Vector3D(-3.6505f,-4.3073f,0.0000f),Vector3D(-4.8819f,-6.3595f,0.0000f),Vector3D(-3.6747f,-5.5145f,0.0000f),Vector3D(-2.0667f,-10.7102f,0.0000f),Vector3D(-5.6303f,-9.6672f,0.0000f),Vector3D(-1.7046f,3.3318f,0.0000f),Vector3D(-3.2015f,-6.4464f,0.0000f),Vector3D(-0.1690f,-4.9603f,0.0000f),Vector3D(-2.2530f,-13.2705f,0.0000f),Vector3D(1.8832f,-12.1009f,0.0000f),Vector3D(5.4143f,-18.7269f,0.0000f),Vector3D(0.8788f,-13.0473f,0.0000f),Vector3D(7.9321f,-17.2399f,0.0000f),Vector3D(-1.4390f,-10.2708f,0.0000f),Vector3D(3.2868f,-13.7973f,0.0000f),Vector3D(-7.6922f,-10.8792f,0.0000f),Vector3D(-2.0909f,-2.2502f,0.0000f)};
    Vector3D HappyVectors[28] = {Vector3D(-7.6523f,2.0219f,0.0000f),Vector3D(1.5066f,-3.7375f,0.0000f),Vector3D(-9.6862f,19.2228f,0.0000f),Vector3D(-6.5516f,6.0105f,0.0000f),Vector3D(-1.5935f,-3.5057f,0.0000f),Vector3D(-9.0509f,21.2767f,0.0000f),Vector3D(-9.7835f,22.4900f,0.0000f),Vector3D(-13.6859f,18.3788f,0.0000f),Vector3D(-7.2878f,15.7420f,0.0000f),Vector3D(-4.7849f,19.1749f,0.0000f),Vector3D(-3.4841f,6.2321f,0.0000f),Vector3D(-4.2934f,8.3936f,0.0000f),Vector3D(-5.5394f,3.7772f,0.0000f),Vector3D(-1.9166f,6.5660f,0.0000f),Vector3D(2.5403f,0.5656f,0.0000f),Vector3D(-2.6027f,2.7823f,0.0000f),Vector3D(4.8964f,-5.3599f,0.0000f),Vector3D(2.4627f,-0.8402f,0.0000f),Vector3D(-2.2888f,0.0869f,0.0000f),Vector3D(-0.1708f,-0.6170f,0.0000f),Vector3D(3.9692f,-0.4346f,0.0000f),Vector3D(2.9262f,0.1449f,0.0000f),Vector3D(3.0958f,0.8342f,0.0000f),Vector3D(4.5777f,3.5636f,0.0000f),Vector3D(2.4337f,0.7533f,0.0000f),Vector3D(0.4636f,3.2449f,0.0000f),Vector3D(0.9943f,1.4729f,0.0000f),Vector3D(4.3459f,-4.6066f,0.0000f)};
    Vector3D BlinkBasisVectors[28] = {Vector3D(-2.8625f,0.9754f,0.0000f),Vector3D(0.4191f,-0.3547f,0.0000f),Vector3D(-6.9419f,2.3415f,0.0000f),Vector3D(-2.2742f,0.5711f,0.0000f),Vector3D(-1.4124f,-0.3820f,0.0000f),Vector3D(-6.6989f,2.2847f,0.0000f),Vector3D(-5.2896f,4.1675f,0.0000f),Vector3D(-5.7356f,3.5096f,0.0000f),Vector3D(-4.7361f,3.2732f,0.0000f),Vector3D(-5.5550f,4.1603f,0.0000f),Vector3D(-2.1491f,3.2851f,0.0000f),Vector3D(-2.4849f,4.4922f,0.0000f),Vector3D(-0.3734f,3.0902f,0.0000f),Vector3D(-0.0257f,4.2723f,0.0000f),Vector3D(3.1738f,-5.0024f,0.0000f),Vector3D(0.7996f,-0.0348f,0.0000f),Vector3D(2.3642f,-2.6423f,0.0000f),Vector3D(1.1893f,-11.1528f,0.0000f),Vector3D(2.0893f,-5.4083f,0.0000f),Vector3D(1.1705f,-3.5520f,0.0000f),Vector3D(2.6801f,-11.0522f,0.0000f),Vector3D(5.5022f,-12.3341f,0.0000f),Vector3D(2.5222f,-17.0956f,0.0000f),Vector3D(6.9792f,-15.4586f,0.0000f),Vector3D(1.6043f,-15.6682f,0.0000f),Vector3D(3.2152f,-13.6990f,0.0000f),Vector3D(1.4213f,0.0661f,0.0000f),Vector3D(3.7524f,-4.2720f,0.0000f)};
    Vector3D MouthOpenVectors[24] = {Vector3D(-0.5046f,2.6674f,0.0001f),Vector3D(3.2009f,-5.6233f,0.0000f),Vector3D(-0.5047f,2.6674f,0.0001f),Vector3D(2.1628f,-7.3535f,0.0000f),Vector3D(-0.2163f,3.9651f,0.0002f),Vector3D(2.2493f,-13.7554f,0.0000f),Vector3D(-0.2163f,3.9651f,0.0002f),Vector3D(1.9898f,-14.5340f,0.0000f),Vector3D(-0.2163f,3.9651f,0.0002f),Vector3D(1.4707f,-14.5340f,0.0000f),Vector3D(-0.2163f,3.9651f,0.0002f),Vector3D(-1.7302f,-14.3609f,0.0000f),Vector3D(-0.2163f,3.9651f,0.0002f),Vector3D(-4.9312f,-14.1879f,0.0000f),Vector3D(0.2884f,2.5233f,0.0001f),Vector3D(-3.7200f,-15.6586f,0.0000f),Vector3D(0.2884f,2.5233f,0.0001f),Vector3D(0.1730f,-18.7730f,0.0000f),Vector3D(-0.5767f,2.2349f,0.0001f),Vector3D(-0.3460f,-23.3582f,0.0000f),Vector3D(-0.5767f,2.2349f,0.0001f),Vector3D(-1.2112f,-22.9256f,0.0000f),Vector3D(-0.5767f,2.2349f,0.0001f),Vector3D(-0.5191f,-23.3582f,0.0000f)};
    Vector3D BlinkAngryVectors[18] = {Vector3D(-0.9851f,1.7963f,0.0001f),Vector3D(-0.6664f,0.5795f,0.0000f),Vector3D(-1.3038f,1.6804f,0.0001f),Vector3D(-1.2748f,2.3178f,0.0001f),Vector3D(-1.2748f,2.3178f,0.0001f),Vector3D(-1.2748f,2.3178f,0.0001f),Vector3D(-0.9851f,1.7963f,0.0001f),Vector3D(-0.6664f,0.5795f,0.0000f),Vector3D(-0.8402f,1.3907f,0.0001f),Vector3D(2.4916f,-4.1721f,-0.0002f),Vector3D(-0.6664f,0.5795f,0.0000f),Vector3D(0.5215f,-0.3766f,-0.0000f),Vector3D(3.4188f,-4.4908f,-0.0003f),Vector3D(3.8244f,-6.2291f,-0.0004f),Vector3D(3.8534f,-8.0254f,-0.0004f),Vector3D(3.6795f,-6.4319f,-0.0004f),Vector3D(0.5215f,-0.3766f,-0.0000f),Vector3D(2.0860f,-3.9403f,-0.0002f)};
    Vector3D BlinkHappyVectors[28] = {Vector3D(-0.3189f,-2.0742f,-0.0001f),Vector3D(1.0235f,-3.2542f,-0.0002f),Vector3D(2.2810f,-14.1326f,-0.0006f),Vector3D(3.1791f,-7.4979f,-0.0004f),Vector3D(0.1620f,-1.7708f,-0.0001f),Vector3D(2.2810f,-14.1326f,-0.0006f),Vector3D(0.8715f,-11.4588f,-0.0005f),Vector3D(2.8734f,-10.8847f,-0.0005f),Vector3D(2.5707f,-9.4390f,-0.0004f),Vector3D(-0.7718f,-8.4823f,-0.0003f),Vector3D(-0.5007f,-2.2028f,-0.0001f),Vector3D(-0.2689f,0.9841f,0.0000f),Vector3D(-0.4717f,0.3467f,0.0000f),Vector3D(-0.2689f,0.9841f,0.0000f),Vector3D(0.9192f,-4.2810f,-0.0002f),Vector3D(-0.5007f,-2.2028f,-0.0001f),Vector3D(-1.3754f,-3.7757f,-0.0001f),Vector3D(0.2793f,-8.2057f,-0.0003f),Vector3D(3.1791f,-7.4979f,-0.0004f),Vector3D(-0.5007f,-2.2028f,-0.0001f),Vector3D(1.2354f,-6.2643f,-0.0003f),Vector3D(2.5707f,-9.4390f,-0.0004f),Vector3D(1.0878f,-10.4890f,-0.0004f),Vector3D(2.2810f,-14.1326f,-0.0006f),Vector3D(0.0920f,-10.4153f,-0.0004f),Vector3D(2.2810f,-14.1326f,-0.0006f),Vector3D(-0.0371f,-3.0141f,-0.0001f),Vector3D(-0.1527f,-4.9056f,-0.0002f)};

    Morph morphs[6] = {
        Morph(28, AngryIndexes, AngryVectors),
        Morph(28, HappyIndexes, HappyVectors),
        Morph(28, BlinkBasisIndexes, BlinkBasisVectors),
        Morph(24, MouthOpenIndexes, MouthOpenVectors),
        Morph(18, BlinkAngryIndexes, BlinkAngryVectors),
        Morph(28, BlinkHappyIndexes, BlinkHappyVectors)
    };

public:
    BiasFace(){}

    Object3D* GetObject(){
        return &basisObj;
    }

    void SetMorphWeight(Morphs morph, float weight){
        morphs[morph].Weight = weight;
    }

    float* GetMorphWeightReference(Morphs morph){
        return &morphs[morph].Weight;
    }

    void Reset(){
        for(int i = 0; i < morphCount; i++){
            morphs[i].Weight = 0.0f;
        }
    }

    void Update(){
        basisObj.ResetVertices();

        for(int i = 0; i < morphCount; i++){
            if(morphs[i].Weight > 0.0f){
                morphs[i].MorphObject3D(basisObj.GetTriangleGroup());
            }
        }

    }
};
