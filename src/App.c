/*
 * App.c
 *
 *  Created on: Oct 27, 2023
 *      Author: lenovo
 */

#if 0

#include "util/delay.h"
#include "../Private/Types.h"
#include "../MCAL/DIO/Dio.h"
#include "../HAL/Seven_Segment/Ssd.h"
#include "../HAL/Keypad/Keypad.h"
#include "../MCAL/EXTINT/Extint.h"
#include "../MCAL/Global_Interrupt/Gie.h"
#include "../HAL/LCD/Lcd.h"
#include"../MCAL/ADC/Adc_Int.h"
#include "../MCAL/Timer/Timer.h"


#define ID0          1234
#define ID1          2341
#define ID2          3421

#define PASSWORD0          1234
#define PASSWORD1          2341
#define PASSWORD2          3421

int main()
{
    u8 id = 0, password = 0;
    u8 temp = 0, i;
    H_LCD_void_Init();
    Keypad_Init();
    H_LCD_void_sendString("Please enter your ID:");

    /*for(i = 0; i < 4; i++)
            {
                temp = Keypad_GetButtonState();
                H_LCD_void_sendIntNum(temp);
                id = (id * 10) + temp;
            }

            switch (id)
            {
            case ID0:
            case ID1:
            case ID2:
                H_LCD_void_sendString("Please enter your Password:");
                break;

            default:
                H_LCD_void_sendString("Wrong ID");
                break;
            }

            for(i = 0; i < 4; i++)
            {
                temp = Keypad_GetButtonState();
                H_LCD_void_sendIntNum(temp);
                password = (password * 10) + temp;
            }

            switch (password)
            {
                case PASSWORD0:
                case PASSWORD1:
                case PASSWORD2:
                    H_LCD_void_sendString("Welcome!");
                    break;

                default:
                    H_LCD_void_sendString("Wrong Password");
                    break;
            }*/

    while (1)
    {
    	if(Keypad_GetButtonState() == '1')
    	{
    		temp = Keypad_GetButtonState();
    		H_LCD_void_sendIntNum(temp);
    	}

        
        
        


   }
    

}

#elif 0

#include <avr/io.h>
#include <avr/interrupt.h>

#define LED_PIN PB0  // Assuming the LED is connected to PB0

volatile uint8_t overflowCounter = 0;

int main(void) {
    // Configure LED_PIN as an output
    DDRB |= (1 << LED_PIN);

    // Setup Timer0 with prescaler = 1024
    TCCR0 |= (1 << CS02) | (1 << CS00);

    // Enable Timer0 overflow interrupt
    TIMSK |= (1 << TOIE0);

    // Enable global interrupts
    sei();

    while (1) {
        // main loop
    }
}

ISR(TIMER0_OVF_vect) {
    overflowCounter++;
    if (overflowCounter >= 40) {
        overflowCounter = 0;
        // Toggle the LED
        PORTB ^= (1 << LED_PIN);
    }
}



#endif


#if 0

#include <avr/io.h>

void Timer0_PWM_Init() {
    // 1. Set PB3 (OC0) as output
    DDRB |= (1 << PB3);

    // 2. Set Timer 0 in Fast PWM mode with non-inverting output
    TCCR0 |= (1 << WGM00) | (1 << WGM01);  // Fast PWM mode
    TCCR0 |= (1 << COM01);                 // Clear OC0 on compare match (non-inverting mode)

    // 3. Set prescaler to 8 (This will affect the frequency of the PWM. You can choose other prescalers)
    TCCR0 |= (1 << CS01);

    // 4. Set OCR0 to desired duty cycle. 50% of 255 is 127.5. Rounded to 128.
    OCR0 = 128;
}

int main() {
    Timer0_PWM_Init();

    // The PWM signal is now being generated on OC0 (PB3) with a 50% duty cycle.
    while (1) {
        // Do nothing. PWM will keep running.
    }

    return 0;
}




#endif
