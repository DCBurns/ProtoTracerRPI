#pragma once

#include "Animation.h"
#include "KeyFrameTrack.h"
#include "EasyEaseAnimator.h"
#include "../Objects/Background.h"
#include "../Objects/LEDStripBackground.h"
#include "../Morph/BiasFace.h"
#include "../Render/Scene.h"
#include "../Signals/FunctionGenerator.h"
#include "../Menu/SingleButtonMenu.h"
// #include "../Sensors/APDS9960.h"

#include "../Materials/Animated/RainbowNoise.h"
#include "../Materials/Animated/RainbowSpiral.h"
#include "../Materials/Animated/SpectrumAnalyzer.h"
#include "../Materials/Animated/AudioReactiveGradient.h"
#include "../Materials/Animated/Oscilloscope.h"

#include "../Materials/MaterialAnimator.h"

#include "AnimationTracks/BlinkTrack.h"

// #include "../Signals/FFTVoiceDetection.h"

// #include "../Sensors/MicrophoneFourier_MAX9814.h"

#include "../Sensors/MouthFIFO.h"

#include "../Render/ObjectAlign.h"

class BiasAnimation : public Animation<3> {
private:
    uint32_t lastTime = millis();

    BiasFace pM;
    Background background;
    LEDStripBackground ledStripBackground;
    EasyEaseAnimator<25> eEA = EasyEaseAnimator<25>(EasyEaseInterpolation::Overshoot, 1.0f, 0.35f);
    
    //Materials
    RainbowNoise rainbowNoise;
    RainbowSpiral rainbowSpiral;
    SimpleMaterial redMaterial = SimpleMaterial(RGBColor(255, 0, 0));
    SimpleMaterial orangeMaterial = SimpleMaterial(RGBColor(255, 165, 0));
    SimpleMaterial whiteMaterial = SimpleMaterial(RGBColor(255, 255, 255));
    SimpleMaterial greenMaterial = SimpleMaterial(RGBColor(0, 255, 0));
    SimpleMaterial blueMaterial = SimpleMaterial(RGBColor(0, 136, 255));
    SimpleMaterial yellowMaterial = SimpleMaterial(RGBColor(255, 255, 0));
    SimpleMaterial purpleMaterial = SimpleMaterial(RGBColor(255, 0, 255));
    
    // RGBColor gradientSpectrum[2] = {RGBColor(90, 178, 255), RGBColor(0, 136, 255)};
    RGBColor gradientSpectrum[2] = {RGBColor(255, 255, 255), RGBColor(0, 136, 255)};
    GradientMaterial<2> gradientMat = GradientMaterial<2>(gradientSpectrum, 100.0f, false);
    
    MaterialAnimator<10> materialAnimator;
    MaterialAnimator<4> backgroundMaterial;
    
    SpectrumAnalyzer sA = SpectrumAnalyzer(Vector2D(200, 100), Vector2D(100, 50), true, true); 
    AudioReactiveGradient aRG = AudioReactiveGradient(Vector2D(160, 160), Vector2D(0, 0), true, true); 
    Oscilloscope oSC = Oscilloscope(Vector2D(200, 100), Vector2D(0, 0));

    MouthFIFO mouth = MouthFIFO();

    //Animation controllers
    BlinkTrack<1> blink;

    FunctionGenerator fGenMatPos = FunctionGenerator(FunctionGenerator::Sine, -10.0f, 10.0f, 4.0f);
    FunctionGenerator fGenRotation = FunctionGenerator(FunctionGenerator::Sine, -30.0f, 30.0f, 2.6f);
    FunctionGenerator fGenScale = FunctionGenerator(FunctionGenerator::Sine, 3.0f, 8.0f, 4.2f);
    FunctionGenerator fGenMatXMove = FunctionGenerator(FunctionGenerator::Sine, -2.0f, 2.0f, 5.3f);
    FunctionGenerator fGenMatYMove = FunctionGenerator(FunctionGenerator::Sine, -2.0f, 2.0f, 6.7f);
    FunctionGenerator fGenMatHue = FunctionGenerator(FunctionGenerator::Triangle, 0.0f, 360.0f, 17.3f);

    // FFTVoiceDetection<128> voiceDetection;
    
    ObjectAlign objA = ObjectAlign(Vector2D(0.0f, 0.0f), Vector2D(189.0f, 93.0f), Quaternion());

    float offsetFace = 0.0f;
    float offsetFaceSA = 0.0f;
    float offsetFaceARG = 0.0f;
    float offsetFaceOSC = 0.0f;
    uint8_t offsetFaceInd = 50;
    uint8_t offsetFaceIndSA = 51;
    uint8_t offsetFaceIndARG = 52;
    uint8_t offsetFaceIndOSC = 53;
    bool mirror = false;

    void LinkEasyEase(){
        eEA.AddParameter(pM.GetMorphWeightReference(BiasFace::Angry), BiasFace::Angry, 10, 0.0f, 1.0f);
        eEA.AddParameter(pM.GetMorphWeightReference(BiasFace::Happy), BiasFace::Happy, 10, 0.0f, 1.0f);
        // eEA.AddParameter(pM.GetMorphWeightReference(BiasFace::Blink), BiasFace::Blink, 10, 0.0f, 1.0f);
    
        eEA.AddParameter(pM.GetMorphWeightReference(BiasFace::MouthOpen), BiasFace::MouthOpen, 2, 0.0f, 1.0f);


        eEA.AddParameter(&offsetFace, offsetFaceInd, 40, 0.0f, 1.0f);
        eEA.AddParameter(&offsetFaceSA, offsetFaceIndSA, 40, 0.0f, 1.0f);
        eEA.AddParameter(&offsetFaceARG, offsetFaceIndARG, 40, 0.0f, 1.0f);
        eEA.AddParameter(&offsetFaceOSC, offsetFaceIndOSC, 40, 0.0f, 1.0f);
    }

    void ResetBlinkParameters(){
        blink.RemoveAllParameters();
    }

    void ChangeInterpolationMethods(){
        eEA.SetInterpolationMethod(BiasFace::Angry, EasyEaseInterpolation::Cosine);
        eEA.SetInterpolationMethod(BiasFace::Happy, EasyEaseInterpolation::Cosine);
        
        eEA.SetInterpolationMethod(BiasFace::MouthOpen, EasyEaseInterpolation::Linear);
        eEA.SetInterpolationMethod(BiasFace::BlinkBasis, EasyEaseInterpolation::Cosine);
    }

    void SetMaterialLayers(){
        materialAnimator.SetBaseMaterial(Material::Add, &gradientMat);
        materialAnimator.AddMaterial(Material::Replace, &orangeMaterial, 40, 0.0f, 1.0f);//layer 1
        materialAnimator.AddMaterial(Material::Replace, &whiteMaterial, 40, 0.0f, 1.0f);//layer 2
        materialAnimator.AddMaterial(Material::Replace, &greenMaterial, 40, 0.0f, 1.0f);//layer 3
        materialAnimator.AddMaterial(Material::Replace, &yellowMaterial, 40, 0.0f, 1.0f);//layer 4
        materialAnimator.AddMaterial(Material::Replace, &purpleMaterial, 40, 0.0f, 1.0f);//layer 5
        materialAnimator.AddMaterial(Material::Replace, &redMaterial, 40, 0.0f, 1.0f);//layer 6
        materialAnimator.AddMaterial(Material::Replace, &blueMaterial, 40, 0.0f, 1.0f);//layer 7
        materialAnimator.AddMaterial(Material::Replace, &rainbowSpiral, 40, 0.0f, 1.0f);//layer 8
        materialAnimator.AddMaterial(Material::Add, &rainbowNoise, 40, 0.5f, 1.0f);//layer 9

        backgroundMaterial.SetBaseMaterial(Material::Add, Menu::GetMaterial());
        backgroundMaterial.AddMaterial(Material::Add, &sA, 20, 0.0f, 1.0f);
        backgroundMaterial.AddMaterial(Material::Add, &aRG, 20, 0.0f, 1.0f);
        backgroundMaterial.AddMaterial(Material::Add, &oSC, 20, 0.0f, 1.0f);
    }

    void UpdateKeyFrameTracks(){
        blink.Update();
    }

    void Default(){
        blink.AddParameter(pM.GetMorphWeightReference(BiasFace::BlinkBasis));
    }

    void Angry(){
        eEA.AddParameterFrame(BiasFace::Angry, 1.0f);
        materialAnimator.AddMaterialFrame(redMaterial, 0.8f);
        blink.AddParameter(pM.GetMorphWeightReference(BiasFace::BlinkAngry));
    }

    // void Sad(){
    //     eEA.AddParameterFrame(NukudeFace::Sadness, 1.0f);
    //     eEA.AddParameterFrame(NukudeFace::Frown, 1.0f);
    //     materialAnimator.AddMaterialFrame(blueMaterial, 0.8f);
    // }

    void Happy(){
        eEA.AddParameterFrame(BiasFace::Happy, 1.0f);
        // materialAnimator.AddMaterialFrame(rainbowSpiral, 0.8f);
        blink.AddParameter(pM.GetMorphWeightReference(BiasFace::BlinkHappy));
    }

    // void SpectrumAnalyzerFace(){
    //     eEA.AddParameterFrame(offsetFaceInd, 1.0f);
    //     eEA.AddParameterFrame(offsetFaceIndSA, 1.0f);

    //     backgroundMaterial.AddMaterialFrame(sA, offsetFaceSA);
    // }

    // void AudioReactiveGradientFace(){
    //     eEA.AddParameterFrame(offsetFaceInd, 1.0f);
    //     eEA.AddParameterFrame(offsetFaceIndARG, 1.0f);

    //     backgroundMaterial.AddMaterialFrame(aRG, offsetFaceARG);
    // }

    // void OscilloscopeFace(){
    //     eEA.AddParameterFrame(offsetFaceInd, 1.0f);
    //     eEA.AddParameterFrame(offsetFaceIndOSC, 1.0f);

    //     backgroundMaterial.AddMaterialFrame(oSC, offsetFaceOSC);
    // }

    void UpdateFFTVisemes(){
        // if(Menu::UseMicrophone()){
        //     eEA.AddParameterFrame(NukudeFace::vrc_v_ss, MicrophoneFourierIT::GetCurrentMagnitude() / 2.0f);

        //     if(MicrophoneFourierIT::GetCurrentMagnitude() > 0.05f){
        //         voiceDetection.Update(MicrophoneFourierIT::GetFourierFiltered(), MicrophoneFourierIT::GetSampleRate());
        
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_ee, voiceDetection.GetViseme(voiceDetection.EE));
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_ih, voiceDetection.GetViseme(voiceDetection.AH));
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_dd, voiceDetection.GetViseme(voiceDetection.UH));
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_rr, voiceDetection.GetViseme(voiceDetection.AR));
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_ch, voiceDetection.GetViseme(voiceDetection.ER));
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_aa, voiceDetection.GetViseme(voiceDetection.AH));
        //         eEA.AddParameterFrame(NukudeFace::vrc_v_oh, voiceDetection.GetViseme(voiceDetection.OO));
        //     }
        // }
    }

    void SetMaterialColor(){
        switch(Menu::GetFaceColor()){
            case 1: materialAnimator.AddMaterialFrame(redMaterial, 0.8f); break;
            case 2: materialAnimator.AddMaterialFrame(orangeMaterial, 0.8f); break;
            case 3: materialAnimator.AddMaterialFrame(whiteMaterial, 0.8f); break;
            case 4: materialAnimator.AddMaterialFrame(greenMaterial, 0.8f); break;
            case 5: materialAnimator.AddMaterialFrame(blueMaterial, 0.8f); break;
            case 6: materialAnimator.AddMaterialFrame(yellowMaterial, 0.8f); break;
            case 7: materialAnimator.AddMaterialFrame(purpleMaterial, 0.8f); break;
            case 8: materialAnimator.AddMaterialFrame(rainbowSpiral, 0.8f); break;
            case 9: materialAnimator.AddMaterialFrame(rainbowNoise, 0.8f); break;
            default: break;
        }
    }

public:
    BiasAnimation() {
        scene.AddObject(pM.GetObject());
        scene.AddObject(background.GetObject());
        scene.AddObject(ledStripBackground.GetObject());

        LinkEasyEase();
        // LinkParameters();

        ChangeInterpolationMethods();

        SetMaterialLayers();

        pM.GetObject()->SetMaterial(&materialAnimator);
        background.GetObject()->SetMaterial(&backgroundMaterial);
        ledStripBackground.GetObject()->SetMaterial(&materialAnimator);

        // boop.Initialize(5);

        // MicrophoneFourierIT::Initialize(A0, 8000, 50.0f, 120.0f);//8KHz sample rate, 50dB min, 120dB max
        Menu::Initialize(3, 500);//7 is number of faces

        objA.SetJustification(ObjectAlign::MiddleLeft);
        objA.SetMirrorX(false);

        float* p1 = pM.GetMorphWeightReference(BiasFace::BlinkBasis);
        float* p2 = pM.GetMorphWeightReference(BiasFace::BlinkAngry);
        float* p3 = pM.GetMorphWeightReference(BiasFace::BlinkHappy);

        std::cout << p1 << "\t" << p2 << "\t" << p3 << "\n";
    }

    uint8_t GetAccentBrightness(){
        return 50;
    }

    uint8_t GetBrightness(){
        return 255;
    }

    void FadeIn(float stepRatio) override {}
    void FadeOut(float stepRatio) override {}

    Object3D* GetObject(){
        return pM.GetObject();
    }

    void SetCameraMirror(bool mirror){
        this->mirror = mirror;
        // objA.SetMirrorX(!mirror);
    }

    void Update(float ratio) override {

        if(!mirror){
            // gradientSpectrum[0].SetColor(255, 175, 175);
            // gradientSpectrum[1].SetColor(255, 55, 225);
            gradientMat.UpdateRGB();

            pM.Reset();
            ResetBlinkParameters();

            float xOffset = fGenMatXMove.Update();
            float yOffset = fGenMatYMove.Update();

            Menu::Update(ratio);

            SetMaterialColor();

            bool isBooped = false; // Menu::UseBoopSensor() ? boop.isBooped() : 0;
            uint8_t mode = Menu::GetFaceState();//change by button press

            auto now = millis();

            // if (now - lastTime > 15000) {
            //     lastTime = now;
            //     mode = (mode + 1) % 3;
            //     Menu::SetFaceState(mode);

            //     std::cout << "mode " << (int)mode << "\n";
            // }

            // MicrophoneFourierIT::Update();
            // mouth.getScale();
            eEA.AddParameterFrame(BiasFace::MouthOpen, mouth.getScale());

            sA.SetHueAngle(ratio * 360.0f * 4.0f);
            // sA.SetMirrorYState(Menu::MirrorSpectrumAnalyzer());
            // sA.SetFlipYState(!Menu::MirrorSpectrumAnalyzer());
            
            aRG.SetRadius((xOffset + 2.0f) * 2.0f + 25.0f);
            aRG.SetSize(Vector2D((xOffset + 2.0f) * 10.0f + 50.0f, (xOffset + 2.0f) * 10.0f + 50.0f));
            aRG.SetHueAngle(ratio * 360.0f * 8.0f);
            aRG.SetRotation(ratio * 360.0f * 2.0f);
            aRG.SetPosition(Vector2D(80.0f + xOffset * 4.0f, 48.0f + yOffset * 4.0f));

            oSC.SetSize(Vector2D(200.0f, 100.0f));
            oSC.SetHueAngle(ratio * 360.0f * 8.0f);
            oSC.SetPosition(Vector2D(100.0f, 50.0f));
            
            if (mode == 0) Default();
            else if (mode == 1) Angry();
            else Happy();
            
            UpdateKeyFrameTracks();

            eEA.Update();
            pM.Update();
            
            rainbowNoise.Update(ratio);
            rainbowSpiral.Update(ratio);
            materialAnimator.Update();
            backgroundMaterial.Update();

            // uint8_t faceSize = Menu::GetFaceSize();
            float scale = Menu::ShowMenu() * 0.6f + 0.4f;
            // float faceSizeOffset = faceSize * 8.0f;

            // objA.SetPlaneOffsetAngle(0.0f);
            // objA.SetEdgeMargin(2.0f);
            // objA.SetCameraMax(Vector2D(110.0f + faceSizeOffset, 93.0f - 93.0f * offsetFace).Multiply(scale));

            // objA.AlignObjects(scene.GetObjects(), 1);
            // pM.GetObject()->GetTransform()->SetPosition(Vector3D(-100.0f, 0.0f, 0.0f));
            

            pM.GetObject()->GetTransform()->SetPosition(Vector3D(xOffset, yOffset, 0.0f));
            pM.GetObject()->GetTransform()->SetScale(Vector3D(scale, scale, scale));
            pM.GetObject()->UpdateTransform();
        }
        
        
    }
};
