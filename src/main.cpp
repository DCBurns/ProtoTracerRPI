//#define ALPHARIGHT
//#define ALPHALEFT
//#define BETAWS35
//#define GAMMAFRONT
//#define GAMMABACK
// #define HUB75
//#define HUB75Split
//#define HUB75Square
#define HUB75HZellerSplit
#define ARDUINOPATCH
//#define WS35
//#define WS35SPLIT
//#define ESP32HUB75
//#define CUSTOMHUB75
// #define CUSTOMWS35

// #define PRINTINFO

#include <cstdlib>
#include <cstdint>
#include <iostream>

uint8_t maxBrightness = 50;
uint8_t maxAccentBrightness = 100;

#ifdef ALPHARIGHT
#include "Controllers/ProtoDRController.h"
#include "Animation/ProtoDRMorphAnimation.h"
ProtoDRController controller = ProtoDRController(maxBrightness, ProtoDRController::RIGHT);
#elif defined(ALPHALEFT)
#include "Controllers/ProtoDRController.h"
#include "Animation/ProtoDRMorphAnimation.h"
ProtoDRController controller = ProtoDRController(maxBrightness, ProtoDRController::LEFT);
#elif defined(BETAWS35)
#include "Controllers/BetaProtoController.h"
#include "Animation/BetaAnimation.h"
BetaProtoController controller = BetaProtoController(maxBrightness);
BetaAnimation animation = BetaAnimation();
#elif defined(GAMMAFRONT)
#include "Controllers/GammaControllerFront.h"
#include "Animation/GammaAnimation.h"
GammaControllerFront controller = GammaControllerFront(maxBrightness);
#elif defined(GAMMABACK)
#include "Controllers/GammaControllerBack.h"
#include "Animation/GammaAnimation.h"
GammaControllerBack controller = GammaControllerBack(maxBrightness);
#elif defined(HUB75)
#include "Controllers/SmartMatrixHUB75.h"
#include "Animation/ProtogenHUB75Animation.h"
//#include "Animation/BetaAnimation.h"
SmartMatrixHUB75 controller = SmartMatrixHUB75(maxBrightness, maxAccentBrightness);
ProtogenHUB75Animation animation = ProtogenHUB75Animation();
//BetaAnimation animation = BetaAnimation();
#elif defined(HUB75Split)
#include "Controllers/SmartMatrixHUB75Split.h"
#include "Animation/ProtogenHUB75AnimationSplit.h"
SmartMatrixHUB75Split controller = SmartMatrixHUB75Split(maxBrightness, maxAccentBrightness);
ProtogenHUB75AnimationSplit animation = ProtogenHUB75AnimationSplit();
#elif defined(HUB75Square)
#include "Controllers/SmartMatrixHUB75Square.h"
#include "Animation/ClockAnimation.h"
SmartMatrixHUB75Split controller = SmartMatrixHUB75Split(maxBrightness, maxAccentBrightness);
ClockAnimation animation = ClockAnimation();
#elif defined(HUB75HZellerSplit)
#include "Controllers/HzellerHUB75Split.h"
#include "Animation/BiasAnimation.h"
#include "ArduinoPatch.h"
HZellerHUB75Split controller = HZellerHUB75Split(maxBrightness, maxAccentBrightness);
BiasAnimation animation = BiasAnimation();
#elif defined(WS35)
#include "Controllers/KaiborgV1D1Controller.h"
#include "Animation/ProtogenKitFaceAnimation.h"
KaiborgV1D1Controller controller = KaiborgV1D1Controller(maxBrightness);
ProtogenKitFaceAnimation animation = ProtogenKitFaceAnimation();
#elif defined(WS35SPLIT)
#include "Controllers/KaiborgV1D1Controller.h"
#include "Animation/ProtogenKitFaceAnimation.h"
KaiborgV1D1Controller controller = KaiborgV1D1Controller(maxBrightness);
ProtogenKitFaceAnimation animation = ProtogenKitFaceAnimation();
#elif defined(ESP32HUB75)
#include "Controllers/ESP32DevKitV1.h"
#include "Animation/ESP32Clock.h"

ESP32DevKitV1 controller = ESP32DevKitV1(maxBrightness);
ESP32Clock animation = ESP32Clock();
#elif defined(CUSTOMHUB75)
#define HUB75
#include "Controllers/SmartMatrixHUB75.h"
#include "Animation/ProtogenHUB75Animation.h"
SmartMatrixHUB75 controller = SmartMatrixHUB75(maxBrightness, maxAccentBrightness);
BasilGardenAnimation animation = BasilGardenAnimation();
#elif defined(CUSTOMWS35)
#define WS35
#include "Controllers/KaiborgV1D1Xenrax.h"
#include "Animation/Commissions/XenraxAnimation.h"
KaiborgV1D1Controller controller = KaiborgV1D1Controller(maxBrightness);
BasilGardenAnimation animation = BasilGardenAnimation();
#else
//Define your own here
//--------------- ANIMATIONS ---------------
#include "Animation/Test/FullScreenAnimation.h"
//#include "Animation/VectorFieldAnimation.h"
//#include "Animation/CoelaBonkAnimation.h"
//#include "Animation/SpyroAnimation.h"
//#include "Animation/SpyroRotateAnimation.h"
//#include "Animation/Commissions/AphoriAnimation.h"
//#include "Animation/Commissions/GalaxyAnimation.h"

//--------------- CONTROLLERS ---------------
//#include "Controllers/KaiborgV1Controller.h"
#include "Controllers/KaiborgV1D1Controller.h"
//#include "Controllers/ProtoDRController.h"
//#include "Controllers/SmartMatrixHUB75.h"
//#include "Controllers/SmartMatrixHUB75Split.h"
//#define HUB75
#define WS35SPLIT

KaiborgV1D1Controller controller = KaiborgV1D1Controller(maxBrightness);
FullScreenAnimation animation = FullScreenAnimation();
#endif

float FreeMem(){
    uint64_t stackT;
    uint64_t heapT;

    // current position of the stack.
    stackT = (uint64_t) &stackT;

    void* heapPos = malloc(1);
    heapT = (uint64_t) heapPos;
    free(heapPos);

    float temp = stackT - heapT;

    return temp / 1000000.0f;
}

// TODO: Convert to stdout
void setup() {
    std::cout << "Starting...\n";

    // while(true) {
    //     std::cout << "loop\n";
    // };
    
    controller.Initialize();

    
}

// TODO: make a main() function that is only #ifdef for pi, calls loop() in loop no delay
void loop() {
    float ratio = (float)(millis() % 5000) / 5000.0f;

    #ifdef HUB75HZellerSplit

    // std::cout << "Hello there \t" << millis() << "\t" << micros() << "\n";// TODO: Fill this in with appropriate
    controller.SetAccentBrightness(animation.GetAccentBrightness() * 25 + 5);  // RADNOTE: This is scaling brightness to 0-255 from 0-100
    controller.SetBrightness(animation.GetBrightness() * 25 + 5);

    // std::cout << "Render Cam 1 \n";
    animation.SetCameraMirror(false);
    animation.UpdateTime(ratio);  // RADNOTE: What this doing?
    controller.RenderCamera(animation.GetScene(), 0);

    // std::cout << "Render Cam 2 \n";
    animation.SetCameraMirror(true);
    animation.UpdateTime(ratio);
    controller.RenderCamera(animation.GetScene(), 1);

    #elif defined(HUB75Split)
    controller.SetAccentBrightness(animation.GetAccentBrightness() * 25 + 5);  // RADNOTE: This is scaling brightness to 0-255 from 0-100
    controller.SetBrightness(animation.GetBrightness() * 25 + 5);

    animation.SetCameraMirror(false);
    animation.UpdateTime(ratio);  // RADNOTE: What this doing?
    controller.RenderCamera(animation.GetScene(), 0);

    animation.SetCameraMirror(true);
    animation.UpdateTime(ratio);
    controller.RenderCamera(animation.GetScene(), 1);
    #elif defined(HUB75)
    controller.SetAccentBrightness(animation.GetAccentBrightness() * 25 + 5);
    controller.SetBrightness(animation.GetBrightness() * 25 + 5);

    animation.UpdateTime(ratio);
    controller.Render(animation.GetScene());
    #elif defined(ESP32HUB75)
    controller.SetBrightness(100);

    animation.UpdateTime(ratio);
    controller.Render(animation.GetScene());
    #elif defined(HUB75Square)
    controller.SetBrightness(animation.GetBrightness());

    animation.UpdateTime(ratio);
    controller.Render(animation.GetScene());
    #elif defined(WS35)
    controller.SetAccentBrightness(animation.GetAccentBrightness() * 25 + 5);
    controller.SetBrightness(powf(animation.GetBrightness() + 3, 2) / 3);

    animation.UpdateTime(ratio);
    controller.Render(animation.GetScene());
    #elif defined(WS35SPLIT)
    controller.SetAccentBrightness(animation.GetAccentBrightness() * 25 + 5);
    controller.SetBrightness(powf(animation.GetBrightness() + 3, 2) / 3);

    animation.SetCameraMirror(false);
    animation.UpdateTime(ratio);
    controller.RenderCamera(animation.GetScene(), 0);

    animation.SetCameraMirror(true);
    animation.UpdateTime(ratio);
    controller.RenderCamera(animation.GetScene(), 1);
    #elif defined(BETAWS35)
    controller.SetAccentBrightness(animation.GetAccentBrightness() * 25 + 5);
    controller.SetBrightness(powf(animation.GetBrightness() + 3, 2) / 3);

    animation.UpdateTime(ratio);
    controller.Render(animation.GetScene());
    #else
    Serial.print("not defined");
    #endif
    
    //controller.

    controller.Display();

    #ifdef PRINTINFO
    std::cout << "Animated in " << animation.GetAnimationTime() \
        << "s, Rendered in " << controller.GetRenderTime() \
        << "s, Free memory " << FreeMem() << "Kb\n";
    #endif
}

int main() {
    setup();

    while(true) {
        loop();
    }
}