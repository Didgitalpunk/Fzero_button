/*
This program is free software, but comes with absolutely NO WARRANTY
Simple App, an example program for the Flipper Zero
*/
#include <stdio.h>
#include <furi.h>
#include <furi_hal.h>
#include <furi_hal_light.h> // lib for the front LED
#include <furi_hal_power.h> // lib for power detection
#include <gui/gui.h>            // unused for now
#include <input/input.h>    // lib for keypress detection
#include <locale/locale.h>

// (*1) This will be the label that tells you which keypad-button is pressed.
char* currentKeyPressed;
int BUFFER = 10;


int button_app(void* p) {
    furi_hal_light_set(LightGreen, 0);
    furi_hal_light_set(LightBlue, 0);
    furi_hal_light_set(LightRed, 0);


    UNUSED(p);
    // Initialization of (*1)
    // corrected by an meitwouldseem, thank you man !
    currentKeyPressed = "NONE";

    InputEvent event;
    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));


    while(1){
        furi_check(furi_message_queue_get(event_queue, &event, FuriWaitForever) == FuriStatusOk);
        if(event.type == InputTypeShort && event.key == InputKeyBack) {
            furi_hal_light_set(LightRed, 0);
            furi_hal_light_set(LightGreen, 0);
            break;
        }
        if(event.key == InputKeyOk) {
            
                furi_hal_light_set(LightGreen,255);
                furi_hal_light_set(LightRed, 0);
            } else{
                furi_hal_light_set(LightRed, 255);
                furi_hal_light_set(LightGreen, 0);
            }
            
            if(!furi_hal_power_is_charging()) {     // exit upon disconnecting from USB power
            furi_hal_light_set(LightBacklight, 255);
            break;
        }
    }

    // Freeing up the rest of memory from all the unused resources.
    furi_message_queue_free(event_queue);
    return 0;
}