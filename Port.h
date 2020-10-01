#ifndef __PORT_H__
#define __PORT_H__

#include "Main.h"


/* Leds' pins */
#define LED_1_PORT_DR   (GPIO_PORTB_DATA)
#define LED_1_PORT_CR   (GPIO_PORTB_CONTROL)
#define LED_1_PIN       (GPIO_PIN_6)


/* Fill missing code below */
/* Switches */
#define SW_PLUS_PORT_DR     (GPIO_PORTB_DATA)
#define SW_PLUS_PORT_CR     (GPIO_PORTB_CONTROL)
#define SW_PLUS_PIN         (GPIO_PIN_0)

#define SW_MINUS_PORT_DR    (GPIO_PORTB_DATA)
#define SW_MINUS_PORT_CR    (GPIO_PORTB_CONTROL)
#define SW_MINUS_PIN        (GPIO_PIN_1)

#define SW_PW_PORT_DR      (GPIO_PORTB_DATA)
#define SW_PW_PORT_CR      (GPIO_PORTB_CONTROL)
#define SW_PW_PIN          (GPIO_PIN_2)

/* SSD */
#define SSD_DATA_PORT_DR        (GPIO_PORTD_DATA)
#define SSD_DATA_PORT_CR        (GPIO_PORTD_CONTROL)

#define SSD_TENS_DR     (GPIO_PORTA_DATA)
#define SSD_TENS_CR     (GPIO_PORTA_CONTROL)
#define SSD_TENS_PIN    (GPIO_PIN_4)

#define SSD_UNITS_DR    (GPIO_PORTA_DATA)
#define SSD_UNITS_CR    (GPIO_PORTA_CONTROL)
#define SSD_UNITS_PIN   (GPIO_PIN_5)


#define HEAT_PORT_DR    (GPIO_PORTC_DATA)
#define HEAT_PORT_CR    (GPIO_PORTC_CONTROL)
#define HEAT_PIN    (GPIO_PIN_5)

#define FAN_PORT_DR    (GPIO_PORTC_DATA)
#define FAN_PORT_CR    (GPIO_PORTC_CONTROL)
#define FAN_PIN    (GPIO_PIN_2)

#define SENSOR_PORT_DR    (GPIO_PORTE_DATA)
#define SENSOR_PORT_CR    (GPIO_PORTE_CONTROL)
#define SENSOR_PIN    (GPIO_PIN_2)

#define SDA_DIR      (GPIO_PORTC_DATA) // Data pin for i2c
#define SDA_C    (GPIO_PORTC_CONTROL) // Data pin direction
#define SDA        (GPIO_PIN_4)

#define SCK_C    (GPIO_PORTC_CONTROL)      // Clock pin direction
#define SCK_DIR    (GPIO_PORTC_DATA)        // Clock pin for i2c
#define SCK      (GPIO_PIN_3)         // Clock pin for i2c

/*#define IDAT      (GPIO_PORTC_DATA) // Data pin for i2c
#define TIDAT    (GPIO_PORTC_CONTROL) // Data pin direction
#define DAT_PIN        (GPIO_PIN_4)

#define ICK_C    (GPIO_PORTC_CONTROL)      // Clock pin direction
#define ICK_DIR    (GPIO_PORTC_DATA)        // Clock pin for i2c
#define ICK_PIN      (GPIO_PIN_3)         // Clock pin for i2c*/
#endif // __PORT_H__
