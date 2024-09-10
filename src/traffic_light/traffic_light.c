#include <avr/io.h>
#include "../timer.h"
#include "traffic_light.h"

#define GREEN_PIN PB1 	// Arduino Pin 9 -> PB1
#define YELLOW_PIN PB2	// Arduino Pin 10 -> PB2
#define RED_PIN PB3		// Arduino Pin 11 -> PB3

// Delays for each LED in ms
#define GREEN_DELAY 5000
#define YELLOW_DELAY 1000
#define RED_DELAY 5000

void traffic_light_init(void) {
	// set pins as output
	DDRB |= (1 << GREEN_PIN);
	DDRB |= (1 << YELLOW_PIN);
	DDRB |= (1 << RED_PIN);
}

void traffic_light_run(void) {
	// red light on
	PORTB |= (1 << RED_PIN);
	delay_ms(RED_DELAY);

	// yellow and red lights on
	PORTB |= (1 << YELLOW_PIN);
	delay_ms(YELLOW_DELAY);

	// turn off yellow and red
	PORTB &= ~(1 << RED_PIN);
	PORTB &= ~(1 << YELLOW_PIN);

	// green light on
	PORTB |= (1 << GREEN_PIN);
	delay_ms(GREEN_DELAY);

	// turn off green and turn on yellow
	PORTB &= ~(1 << GREEN_PIN);
	PORTB |= (1 << YELLOW_PIN);
	delay_ms(YELLOW_DELAY);

	// turn off yellow
	PORTB &= ~(1 << YELLOW_PIN);
}
