/*
 * PWM_32u4.cpp
 *
 * Created: 12/03/2024 14:28:04
 * Author : Luis Mi CONTROLLIUM
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000ul

void PWM_init(uint8_t pin) {
    // Configurar el pin como salida para PWM según el pin pasado como parámetro
    if (pin == 3) {
        DDRE |= (1 << DDE6); // PE6
    } else if (pin == 5) {
        DDRE |= (1 << DDE2); // PE2
    } else if (pin == 6) {
        DDRD |= (1 << DDD7); // PD7
    } else if (pin == 9) {
        DDRB |= (1 << DDB5); // PB5
    } else if (pin == 10) {
        DDRB |= (1 << DDB6); // PB6
    } else if (pin == 11) {
        DDRB |= (1 << DDB7); // PB7
    }

    // Configurar el Timer1 para el modo PWM de 8 bits
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS10);  // Prescaler 1
}

void PWM_setDutyCycle(uint8_t pin, uint8_t dutyCycle) {
    // Establecer el ciclo de trabajo para el PWM en el pin especificado
    if (pin == 3) {
        OCR1A = dutyCycle;
    } else if (pin == 5) {
        OCR1A = dutyCycle;
    } else if (pin == 6) {
        OCR1A = dutyCycle;
    } else if (pin == 9) {
        OCR1A = dutyCycle;
    } else if (pin == 10) {
        OCR1B = dutyCycle;
    } else if (pin == 11) {
        OCR1B = dutyCycle;
    }
}

int main(void)
{	
	
	DDRB|=(1<<PINB0);
	
  
	PWM_init(9);
	PWM_setDutyCycle(9,86);
    while (1) 
    {	
		
    }
}