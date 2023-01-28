/*
This program is free software, but comes with absolutely NO WARRANTY
Simple App, an example program for the Flipper Zero
*/
#include <furi.h>
#include <furi_hal.h>
#include <furi_hal_light.h> // lib for the front LED
#include <furi_hal_power.h> // lib for power detection
#include <gui/gui.h> // unused for now
#include <input/input.h> // lib for keypress detection
#include <locale/locale.h>

InputEvent event;

int simple_app() {
    while(furi_hal_power_is_charging()) {
        if(event.key == InputKeyOk) // red light
        {
            furi_hal_light_set(LightRed, 255);
        } else {
            furi_hal_light_set(LightBlue, 0);
        }

        furi_hal_light_set(LightRed, 0);
    }
    return 0;
}