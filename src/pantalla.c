
/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "pantalla.h"
#include <string.h>

/* === Macros definitions ====================================================================== */
#ifndef DISPLAY_MAX_DIGIT
    #define DISPLAY_MAX_DIGIT 8
#endif

/* === Private data type declarations ========================================================== */

struct display_s {
    uint8_t digits;
    uint8_t active_digit;
    uint8_t memory[DISPLAY_MAX_DIGIT];
    struct display_driver_s driver;
};


/* === Private variable declarations =========================================================== */



/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */
 
 static struct display_s instances[1];
 
 static const uint8_t NUMBERS[] =  {
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F, // 0
  SEGMENT_B | SEGMENT_C, // 1
  SEGMENT_A | SEGMENT_B | SEGMENT_D | SEGMENT_E | SEGMENT_G, //2
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_G, // 3
  SEGMENT_B | SEGMENT_C | SEGMENT_F | SEGMENT_G, // 4
  SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_F |SEGMENT_G, // 5
  SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F |SEGMENT_G, // 6 
  SEGMENT_A | SEGMENT_B | SEGMENT_C, //7
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G ,// 8
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_F | SEGMENT_G, // 9
};
/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */
display_t DisplayCreate(uint8_t digits, display_driver_t driver){
    display_t display = instances; 
    display->digits = digits;
    display->active_digit = digits-1;
    memset(display->memory, 0, sizeof(display->memory));
    display->driver.ScreenTurnOff = driver->ScreenTurnOff;
    display->driver.DigitTurnOn = driver->DigitTurnOn;
    display->driver.SegmentsTurnOn = driver->SegmentsTurnOn;
    
    display->driver.ScreenTurnOff();

    return display;
}

void DisplayWriteBCD(display_t display, uint8_t * number, uint8_t sizeScreen){

    memset(display->memory, 0, sizeof(display->memory));
    for(int index=0 ; index < sizeScreen ; index++){
        if(index == display->digits) break;
        display->memory[index] = NUMBERS[number[index]];
    }

}

void DisplayRefresh(display_t display){

    if(display->active_digit == display->digits -1) display->active_digit = 0;
    else display->active_digit = display->active_digit + 1;
        
        
    display->driver.ScreenTurnOff();
    display->driver.SegmentsTurnOn(display->memory[display->active_digit]);
    display->driver.DigitTurnOn(display->active_digit);
    
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */