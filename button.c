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

int button_app() {
    furi_hal_light_set(LightGreen, 0);
    furi_hal_light_set(LightBlue, 0);

    while(furi_hal_power_is_charging()) {
        furi_check(furi_message_queue_get(event_queue, &event, FuriWaitForever) == FuriStatusOk);
        if(event.key == InputKeyOk) // red light
        {
            furi_hal_light_set(LightRed, 255);
        }
    }
    furi_hal_light_set(LightRed, 0);
    return 0;
}