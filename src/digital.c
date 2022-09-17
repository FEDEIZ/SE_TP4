/** @file digital.c

/** \brief Simple sample of use LPC HAL gpio functions
 **  The purpose of this sample is to understand the use of LPC HAL gpio functions and how to 
 **  create separate c and h files for a project. This sample is part of the EITI course called Embedded Systems
 **
 ** | RV | YYYY.MM.DD | Author      | Changes description                     |
 ** |----|------------|-------------|-----------------------------------------|
 ** |  1 | 2022.09.14 | fedeiz      | V1.0
 ** 
 **
 

 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "digital.h" /** \brief file that contains the headers and include resources */
#include "chip.h"   /** \brief file thtat contains the hardware configuration chip*/

/* === Macros definitions ====================================================================== */
/**
 * Here we define the inputs and outpust that we need for this project
 */
#ifndef OUTPUT_INSTANCES
    #define OUTPUT_INSTANCES 6
#endif

#ifndef INPUT_INSTANCES
    #define INPUT_INSTANCES 6
#endif

/* === Private data type declarations ========================================================== */

struct digital_output_s { /** \brief this struct has the attribute that we define in our class model for digital_output*/
    uint8_t gpio;
    uint8_t bit;
    bool allocated;
};

struct digital_input_s { /** \brief this struct has the attribute that we define in our class model for digital_input */
    uint8_t gpio;
    uint8_t bit;
    bool last_state;
    bool allocated;
};
/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */
/**
 * Here we initialize the digital output and input struct specifyng the number of input and output instances
 */
static struct digital_output_s instances_output[OUTPUT_INSTANCES] = {0};

static struct digital_input_s instances_input[INPUT_INSTANCES] = {0};

/* === Private function implementation ========================================================= */
/**
 * Here we return a pointer to the first instance that we find free to use in input and output instances structs.
 */
digital_output_t DigitalOutputAllocate(void){ 
    digital_output_t output = NULL;

    for(int index = 0 ; index < OUTPUT_INSTANCES ; index++){
        if(instances_output[index].allocated == false) {
            instances_output[index].allocated = true;
            output = &instances_output[index];
            break;
        }
    }
    return output;
}

digital_input_t DigitalInputAllocate(void){ 
    digital_input_t input = NULL;

    for(int index = 0 ; index < INPUT_INSTANCES ; index++){
        if(instances_input[index].allocated == false) {
            instances_input[index].allocated = true;
            input = &instances_input[index];
            break;
        }
    }
    return input;
}
/* === Public function implementation ========================================================= */


digital_output_t DigitalOutputCreate(uint8_t gpio, uint8_t bit){ /** \brief Here we use the DigitalOutputAllocate funtion to set the gpio and bit values to the next instance free we will use */

    digital_output_t output = DigitalOutputAllocate();
    if(output){
        output->gpio = gpio;
        output ->bit = bit;
        Chip_GPIO_SetPinState(LPC_GPIO_PORT,output->gpio, output ->bit , false);
        Chip_GPIO_SetPinDIR(LPC_GPIO_PORT,output->gpio, output ->bit, true);
    }

    return output;
}
void DigitalOutputActivate(digital_output_t output){ /** \brief This function activate the output signal*/
    
    if(output){
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->gpio, output->bit, true);
    }
}
void DigitalOutputDeactivate(digital_output_t output){ /** \brief This function deactivate the output signal*/
    
     if(output){
        Chip_GPIO_SetPinState(LPC_GPIO_PORT, output->gpio, output->bit, false);
    }

}
void DigitalOutputToggle(digital_output_t output){ /** \brief This function toggle the output signal*/
     
     if(output){
        Chip_GPIO_SetPinToggle(LPC_GPIO_PORT, output->gpio, output->bit);
    }
}

digital_input_t DigitalInputCreate(uint8_t gpio, uint8_t bit){ /** \brief Here we use the DigitalInputAllocate funtion to set the gpio and bit values to the next instance free we will use */
   
   digital_input_t input = DigitalInputAllocate();
    if(input){
        input->gpio = gpio;
        input ->bit = bit;
        input ->last_state = false;
        Chip_GPIO_SetPinDIR(LPC_GPIO_PORT, input->gpio, input ->bit, false);
    }
    return input;
}

bool DigitalInputGetState(digital_input_t input){  /** \brief This fnuction read the state of the digital input*/
    bool state = false;
    if(input){
        state = (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, input->gpio, input->bit) == 0);
    }
    return state;
}

bool DigitalInputHasChanged(digital_input_t input){ /** \brief This fnuction verify if the state of the digital input changed*/
    bool state = DigitalInputGetState(input);
    if(state != input->last_state){
        input->last_state = state;
        return true;
    } 
    else return false;
}

bool DigitalInputHasActivated(digital_input_t input){ /** \brief This fnuction verify if the state of the digital input was activated*/
    bool state = DigitalInputGetState(input);
    bool last_state = DigitalInputHasChanged(input);
    if(last_state == false && state == true) return true;
    else return false;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
