#pragma once

// #TODO: Write / read config to file for next boot?
// #include <EEPROM.h>
// #include <IntervalTimer.h>
#include <cstring>
#include <chrono>
#include <thread>
#include <functional>
#include <fcntl.h>
#include <errno.h>
// #include <stdlib.h>
#include <linux/input.h>
#include <libevdev/libevdev.h>


template<uint8_t menuCount>
class MenuHandler{
private:
    static uint16_t holdingTime;
    static uint8_t currentMenu;
    static uint8_t currentValue[menuCount];
    static uint8_t maxValue[menuCount];
    static const char *controllerFiles[];


    static std::thread controllerThread;

    static struct libevdev *dev;
    static int fd;

    static void UpdateState(){

        // Do something to increment currentMenu, currentValue[currentMenu]
        int rc;

        if(fd < 0) {
            printf("File descriptor not open. Reopening.\n");
            rc = OpenDevice(controllerFiles[0]);
        }

        if(rc < 0) {
            printf("Unable to open FD.... is a controller connected?\n");
            return;
        }

        do {
            struct input_event ev;
            rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);
            if (rc == 0)
                    // printf("Event: %s %s %d\n",
                    //        libevdev_event_type_get_name(ev.type),
                    //        libevdev_event_code_get_name(ev.type, ev.code),
                    //        ev.value);

                    if(ev.value == 0) {
                        switch(ev.code) {
                            case KEY_K: currentMenu = (currentMenu + menuCount - 1) % menuCount; break;
                            case KEY_M: currentMenu = (currentMenu + 1) % menuCount; break;
                            case KEY_C: currentValue[currentMenu] = (currentValue[currentMenu] + 1) % maxValue[currentMenu]; break;
                            case KEY_D: currentValue[currentMenu] = (currentValue[currentMenu] + maxValue[currentMenu] - 1) % maxValue[currentMenu]; break;
                        }
                    }
        } while (rc == 1 || rc == 0 || rc == -EAGAIN);

        std::cout << "UpdateState loop done. rc = " << rc << "\t" << strerror(-rc) << "\n";

        CloseDevice();
    }

    // TODO: Dynamically check for which dev device has our controller?
    static int OpenDevice(const char* device) {
        fd = open(device, O_RDONLY|O_NONBLOCK);

        if(fd < 0){
            printf("open() returned %d: %s\n", fd, strerror(errno));
            return -1;
        }

        printf("FD open on %d\n", fd);

        int rc = libevdev_new_from_fd(fd, &dev);

        if (rc < 0) {
            fprintf(stderr, "%d: Failed to init libevdev (%s)\n",rc, strerror(-rc));
            return rc;
        }

        
        printf("Input device name: \"%s\"\n", libevdev_get_name(dev));
        printf("Input device ID: bus %#x vendor %#x product %#x\n",
            libevdev_get_id_bustype(dev),
            libevdev_get_id_vendor(dev),
            libevdev_get_id_product(dev));
        
        return rc;
    }

    static int CloseDevice() {
        int rc = close(fd);

        

        if (rc != 0) {
            printf("Unable to close file descriptor %d. rc = %s: %s\n", fd, rc, strerror(errno));
        }
        
        fd = -1;
        return rc;
    }

    //TODO: Replace EEPROM with array read/write of currentValue
    static uint8_t ReadEEPROM(uint16_t index){
        // return EEPROM.read(index);
        return 0;
    }

    //WRITE SETTINGS TO EEPROM
    static void WriteEEPROM(uint16_t index, uint8_t value){
        // EEPROM.write(index, value);
    }

    static std::thread timer_start(std::function<void(void)> func, unsigned int interval) {
        std::thread current_thread = std::thread([func, interval]()
            {
                while(true)
                {
                    auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
                    func();
                    std::this_thread::sleep_until(x);
                }
            }
        );
        current_thread.detach();
        return current_thread;
    }

public:
    static void Begin(){
        if(fd < 0) {
            std::cout << "No file descriptor open for event, starting thread anyways\n";
        }
        
        controllerThread = timer_start(UpdateState, 5000);
    }

    static bool Initialize(uint16_t holdingTime){//if true, eeprom needs set
        
        int rc = OpenDevice(controllerFiles[0]);

        MenuHandler::holdingTime = holdingTime;

        return false; // always set defaults (for testing)
    }

    static void SetDefaultValue(uint16_t menu, uint8_t value){
        if(menu >= menuCount) return;

        currentValue[menu] = value;

        WriteEEPROM(menu, value);
    }

    static void SetInitialized(){
        WriteEEPROM(menuCount + 1, 0);
    }

    static void SetMenuMax(uint8_t menu, uint8_t maxValue){
        if(menu >= menuCount) return;

        MenuHandler::maxValue[menu] = maxValue;
    }

    static uint8_t GetMenuValue(uint8_t menu){
        return currentValue[menu];
    }
    
    static uint8_t GetCurrentMenu(){
        return currentMenu;
    }
    
};


template<uint8_t menuCount>
uint16_t MenuHandler<menuCount>::holdingTime;
template<uint8_t menuCount>
uint8_t MenuHandler<menuCount>::currentMenu;
template<uint8_t menuCount>
uint8_t MenuHandler<menuCount>::currentValue[];
template<uint8_t menuCount>
uint8_t MenuHandler<menuCount>::maxValue[menuCount];
template<uint8_t menuCount>
struct libevdev *MenuHandler<menuCount>::dev = NULL;
template<uint8_t menuCount>
int MenuHandler<menuCount>::fd = -1;
template<uint8_t menuCount>
std::thread MenuHandler<menuCount>::controllerThread;
template<uint8_t menuCount>
const char* MenuHandler<menuCount>::controllerFiles[] = {"/dev/input/event3","/dev/input/event4"};
// template<uint8_t menuCount>
// char MenuHandler<menuCount>::controllerFileTwo[] = "/dev/input/event4";