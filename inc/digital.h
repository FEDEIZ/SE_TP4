#ifndef DIGITAL_H
#define DIGITAL_H

/** @file digital.h
 ** \brief Header module with digital functions
 **
 ** | RV | YYYY.MM.DD | Author      | Changes description              |
 ** |----|------------|-------------|----------------------------------|
 ** |  1 | 2022.09.14 | fedeiz      | V1.0                             |
 ** 
 **

/** \brief This file contains the headers for digital.c file
 **
 ** Here we declarate the public function like DigitalOuputCreate, DigitalOutputActivate, DigitalOutputDeactivate,
 ** DigitalOutputToggle, DigitalInputCreate, DigitalInputGetState, DigitalInputHasChanged and DigitalInputHasActivated

 ** @{ */

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */
 
/* === Public data type declarations =========================================================== */
/**
 * Here we declarate the struct we use in digital.c to save the state of inputs and outputs signals
 */
typedef struct digital_output_s * digital_output_t;

typedef struct digital_input_s * digital_input_t;
/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

digital_output_t DigitalOutputCreate(uint8_t gpio, uint8_t bit);
void DigitalOutputActivate(digital_output_t output);
void DigitalOutputDeactivate(digital_output_t output);
void DigitalOutputToggle(digital_output_t output);

digital_input_t DigitalInputCreate(uint8_t gpio, uint8_t bit);
bool DigitalInputGetState(digital_input_t input);
bool DigitalInputHasChanged(digital_input_t input);
bool DigitalInputHasActivated(digital_input_t input);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif   /* DIGITAL_H */