#include "Controller.h"
#include "Render/Camera.h"
#include "Flash/PixelGroups/P3HUB75.h"

// Import hzeller here

#include "led-matrix.h"
#include "pixel-mapper.h"
#include "graphics.h"

#include <unistd.h>

class HZellerHUB75Split : public Controller {
private:
    // Cameras and shit, hzeller lib
    CameraLayout cameraLayout = CameraLayout(CameraLayout::ZForward, CameraLayout::YUp);

    Transform camTransform = Transform(Vector3D(0.0f, 0.0f, 0.0f), Vector3D(0, 0, 0), Vector3D(1.0f, 1.0f, 1.0f));

    PixelGroup<2048> camPixelsLeft = PixelGroup<2048>(P3HUB75);
    PixelGroup<2048> camPixelsRight = PixelGroup<2048>(P3HUB75);

    Camera<2048> camLeft = Camera<2048>(&camTransform, &cameraLayout, &camPixelsLeft);
    Camera<2048> camRight = Camera<2048>(&camTransform, &cameraLayout, &camPixelsRight);

    CameraBase* cameras[2] = { &camLeft, &camRight };

    rgb_matrix::RGBMatrix *canvas;
    rgb_matrix::FrameCanvas *offscreen_canvas;
    rgb_matrix::Color bg_color = rgb_matrix::Color(0,255,0);

public:
    HZellerHUB75Split(uint8_t maxBrightness, uint8_t maxAccentBrightness) : Controller(cameras, 2, maxBrightness, maxAccentBrightness){}

    void Initialize() override {
        rgb_matrix::RGBMatrix::Options matrix_options;
        rgb_matrix::RuntimeOptions runtime_opt;

        // These are the defaults when no command-line flags are given.
        matrix_options.rows = 32;
        matrix_options.cols = 64;
        matrix_options.chain_length = 2;
        matrix_options.parallel = 1;
        matrix_options.hardware_mapping = "adafruit-hat-pwm";
        // matrix_options.disable_hardware_pulsing = 1;
        runtime_opt.gpio_slowdown = 4;
        runtime_opt.drop_privileges = 0;

        canvas = rgb_matrix::RGBMatrix::CreateFromOptions(matrix_options, runtime_opt);
        offscreen_canvas = canvas->CreateFrameCanvas();
    }

    void Display() override {
        // Do hzeller writing and buffer swap
        // offscreen_canvas->Fill(bg_color.r, bg_color.g, bg_color.b);
        // std::cout << "Here!\n";
        
        RGBColor *pixel_color;
        
        for(int y = 0; y < 32; y++) {
            for(int x = 0; x < 64; x++) {
                uint16_t pixelNum = y * 64 + x;

                pixel_color = camPixelsLeft.GetColor(pixelNum);

                offscreen_canvas->SetPixel((x + 64), (31 - y), pixel_color->R, pixel_color->G, pixel_color->B);
                // offscreen_canvas->SetPixel((128 - x), (31 - y), pixel_color->R, pixel_color->G, pixel_color->B);
                pixel_color = camPixelsRight.GetColor(pixelNum);

                offscreen_canvas->SetPixel((63 - x), (31 - y), pixel_color->R, pixel_color->G, pixel_color->B);
                // offscreen_canvas->SetPixel(x, (31 - y), pixel_color->R, pixel_color->G, pixel_color->B);
                // offscreen_canvas->SetPixel(x, y, 0,255,0);
                // std::cout << x << "\t" << y << "\n";
            }
        }

        // offscreen_canvas->SetPixel(63,0, 255, 0, 0);

        offscreen_canvas = canvas->SwapOnVSync(offscreen_canvas);
    }


};