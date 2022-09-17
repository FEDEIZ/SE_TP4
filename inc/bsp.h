#ifndef BSP_H
#define BSP_H

/** @file bsp.h
 ** | RV | YYYY.MM.DD | Author      | Changes description                     |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.09.14 | fedeiz      | V1.0

/** \brief Headers for the bsp.c file
 **
 ** Declaring the type struct for the board whith his pointer and boardCreate function
 **

 ** @{ */

/* === Headers files inclusions ================================================================ */

#include "ciaa.h"
#include "digital.h"
#include "pantalla.h"
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
 
/* === Public data type declarations =========================================================== */
 
typedef struct digital_output_s * digital_output_t;

typedef struct digital_input_s * digital_input_t;

typedef struct board_s {
    digital_output_t buzzer;
    digital_input_t set_time;
    digital_input_t set_alarm;
    digital_input_t decrement;
    digital_input_t increment;
    digital_input_t accept;
    digital_input_t cancel;
    display_t display;
} const * const board_t;


/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
board_t BoardCreate(void);



/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif   /* BSP_H */