#ifndef PANTALLA_H
#define PANTALLA_H

/** \brief Brief description of the file
 **
 ** Full file description
 **
 ** \addtogroup name Module denomination
 ** \brief Brief description of the module
 ** @{ */

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
#define SEGMENT_A (1 << 0)
#define SEGMENT_B (1 << 1)
#define SEGMENT_C (1 << 2)
#define SEGMENT_D (1 << 3)
#define SEGMENT_E (1 << 4)
#define SEGMENT_F (1 << 5)
#define SEGMENT_G (1 << 6)
#define SEGMENT_P (1 << 7)
/* === Public data type declarations =========================================================== */
 typedef struct display_s * display_t;
 
typedef void(*display_screen_off_t)(void);
typedef void(*display_segments_on_t)(uint8_t segments);
typedef void(*display_digit_on_t)(uint8_t digit);

typedef struct display_driver_s {
    display_screen_off_t ScreenTurnOff;
    display_segments_on_t SegmentsTurnOn;
    display_digit_on_t DigitTurnOn;
}const * display_driver_t;

/* === Public variable declarations ============================================================ */
/**
 * @brief 
 * 
 * @param digits Numbers of digit that has the 7 segm display
 * @return display_t Pointer to display
 */
display_t DisplayCreate(uint8_t digits, display_driver_t driver);

/**
 * @brief Function to write a BCD number on the 7 segments display
 * 
 * @param display Pointer to the display descriptor
 * @param number Pointer to the first BCD element we will gone write
 * @param size Number of element in array whose contains the BCD number
 */
void DisplayWriteBCD(display_t display, uint8_t * number, uint8_t size);

/**
 * @brief Function to refresh the display 
 * 
 * @param display Pointer to the display descriptor that must refresh
 */
void DisplayRefresh(display_t display);
/* === Public function declarations ============================================================ */

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif   /* PANTALLA_H */