/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

#define LED0 IOPORT_CREATE_PIN(IOPORT_PORTA, 14)

int main (void)
{
	system_init();

	/* Insert application code here, after the board has been initialized. */
	ioport_init();									// call before using IOPORT service
	ioport_set_pin_dir(LED0, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED0, HIGH);
	delay_ms(500);
	ioport_set_pin_level(LED0, LOW);
	delay_ms(500);
}
