/** @file main.c

/** \brief Introducing sample to the use of ciaa board with a simple project
 **   
 **  This sample is part of the EITI course called Embedded Systems. This program turn on and off 
 **  different leds of the boards with different buttons

 ** | RV | YYYY.MM.DD | Author      | Changes description                     |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.09.14 | fedeiz      | V1.0
 ** 
 **

/* === Headers files inclusions =============================================================== */


#include "bsp.h" /** \brief Here we include the headers to use a HAL module for this board */
#include <stdbool.h>
#include <stdint.h>
#include "poncho.h"
#include "chip.h"
#include "pantalla.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================= */
/**
 * This program has four different linking leds. 
 * 1) The blue led remain on while the first button is pressed
 * 2) The red led toggle whith consecutive second button event 
 * 3) The yellow led can be turn on with a third button and off with the fourth button
 * 4) The green led blink beetween 5 cicles program 
 */
int main(void) {
    

    uint8_t numbers[4] = {1,2,3,4}; 

    board_t board = BoardCreate();
    

    DisplayWriteBCD(board->display, numbers, sizeof(numbers)); // writing 1 2 3 4 in the screen

    while (true) {

      DisplayRefresh(board->display);

      for (int delay = 0; delay < 2500; delay++) {
          __asm("NOP");
      }   
    }
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
