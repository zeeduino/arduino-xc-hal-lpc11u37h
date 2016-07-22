/*
  pins_arduino.cpp - pin definitions
  Copyright (c) 2016 Ravendyne Inc.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "chip.h"
#include "pins_arduino.h"

#include "timer_11xx.h"
#include "gpio_11xx_1.h"

#include "pins_arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Settings for PWM channels - LPCXpresso 1347
 */
const PwmMappingType g_ArduinoPinMappingPwm[] =
{
        [PWM_0] = { LPC_TIMER32_0, 1, 0, (IOCON_FUNC1 | IOCON_MODE_INACT) },
        [PWM_1] = { LPC_TIMER32_0, 2, 0, (IOCON_FUNC1 | IOCON_MODE_INACT) },
        [PWM_2] = { LPC_TIMER32_0, 3, 0, (IOCON_FUNC1 | IOCON_MODE_INACT) },
        [PWM_3] = { LPC_TIMER16_0, 0, 0, (IOCON_FUNC2 | IOCON_MODE_INACT) },
        [PWM_4] = { LPC_TIMER16_0, 1, 0, (IOCON_FUNC2 | IOCON_MODE_INACT) },
        [PWM_5] = { LPC_TIMER16_0, 2, 0, (IOCON_FUNC2 | IOCON_MODE_INACT) },
        [PWM_6] = { LPC_TIMER16_1, 0, 0, (IOCON_FUNC1 | IOCON_MODE_INACT) },
        [PWM_7] = { LPC_TIMER16_1, 1, 0, (IOCON_FUNC1 | IOCON_MODE_INACT) }
};

/*
 * Pins IOCON intialization values for digital outputs - LPCXpresso 1347
 * Order and position in the array corresponds to order and position of entries in g_ArduinoPinDescription
 * This is used when we need a pin to be digital I/O, i.e. for digitalWrite() etc.
 */
const DigitalMappingType g_ArduinoPinMappingDigital[] =
{
        //         PORT, GPIO mode function, Output with pullup mode function , Output with pulldown mode function, Reserved },
        // 0 - 1, UART
        { LPC_GPIO, (IOCON_FUNC0), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.18
        { LPC_GPIO, (IOCON_FUNC0), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.19

        // 2 - 12, Digital pins
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
		{ NULL, (0), (0), (0), (0) }, // P.p
        { LPC_GPIO, (IOCON_FUNC0), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 1.3

/*
        // 14 - 19, Analog 0 - 5
        { LPC_GPIO, (IOCON_FUNC1 | IOCON_DIGMODE_EN), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.11
        { LPC_GPIO, (IOCON_FUNC1 | IOCON_DIGMODE_EN), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.12
        { LPC_GPIO, (IOCON_FUNC1 | IOCON_DIGMODE_EN), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.13
        { LPC_GPIO, (IOCON_FUNC1 | IOCON_DIGMODE_EN), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.14
        { LPC_GPIO, (IOCON_FUNC0 | IOCON_DIGMODE_EN), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.16
        { LPC_GPIO, (IOCON_FUNC0 | IOCON_DIGMODE_EN), (IOCON_MODE_PULLUP), (IOCON_MODE_PULLDOWN), (0) }, // 0.23
*/
};

/*
 * Pins descriptions - LPCXpresso 1347
 */
const ArduinoPinDescriptionType g_ArduinoPinDescription[] =
{
        // pins PIO0_0, PIO0_9, PIO0_10, PIO0_15 are connected to programmer on LPCXpresso LPC1347 board
        // PIO0_3 is connected to USB_VBUS, PIO0_6 is connected to USB_CONECT

        // 0 - 1, UART
        { 0, 18, (IOCON_FUNC1 | IOCON_MODE_INACT), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 0 - RX
        { 0, 19, (IOCON_FUNC1 | IOCON_MODE_INACT), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 1 - TX

        // 2 - 12, Digital pins
        // All digital pins are selected such that GPIO is on IOCON_FUNC0
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 2 - pulseIn
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 3 - PWM, 16B0_MAT2
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 4 - pulseIn
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 5 - PWM, 16B0_MAT1
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 6 - PWM, 16B0_MAT0
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 7 - LED
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 8 - PWM, 16B1_MAT0
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 9 - PWM, 16B1_MAT1
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 10 - PWM, 32B0_MAT3
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 11 - PWM, 32B0_MAT2
		{ 99, 99, (0), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 12 - PWM, 32B0_MAT1
        { 1,  3,  (IOCON_FUNC0 | IOCON_MODE_PULLDOWN), NO_ADC, NOT_ON_PWM, NO_EXT_INT }, // 13 - LED
/*
        // 14 - 19, Analog 0 - 5
        { 0,  11, (IOCON_FUNC2 | IOCON_ADMODE_EN      | IOCON_FILT_DIS), ADC_0, NOT_ON_PWM, NO_EXT_INT },    // 14 - AD0
        { 0,  12, (IOCON_FUNC2 | IOCON_ADMODE_EN      | IOCON_FILT_DIS), ADC_1, NOT_ON_PWM, NO_EXT_INT },    // 15 - AD1
        { 0,  13, (IOCON_FUNC2 | IOCON_ADMODE_EN      | IOCON_FILT_DIS), ADC_2, NOT_ON_PWM, NO_EXT_INT },    // 16 - AD2
        { 0,  14, (IOCON_FUNC2 | IOCON_ADMODE_EN      | IOCON_FILT_DIS), ADC_3, NOT_ON_PWM, NO_EXT_INT },    // 17 - AD3
        { 0,  16, (IOCON_FUNC1 | IOCON_ADMODE_EN      | IOCON_FILT_DIS), ADC_4, NOT_ON_PWM, NO_EXT_INT },    // 18 - AD5
        { 0,  23, (IOCON_FUNC1 | IOCON_ADMODE_EN      | IOCON_FILT_DIS), ADC_5, NOT_ON_PWM, NO_EXT_INT },    // 19 - AD7
*/
};

// why extern? const is internal (like static) by default and we didn't declare this one in pins_arduino.h
// Simple: http://stackoverflow.com/a/14894897/2268559
extern const uint32_t arduinoPinsArrayLength = sizeof(g_ArduinoPinDescription) / sizeof(ArduinoPinDescriptionType);

void Variant_Pins_Init()
{
    uint32_t ix;

    for (ix = 0; ix < arduinoPinsArrayLength; ix++ )
    {
        if(g_ArduinoPinDescription[ix].port == 99) continue;

        Chip_IOCON_PinMuxSet(LPC_IOCON, g_ArduinoPinDescription[ix].port, g_ArduinoPinDescription[ix].pin, g_ArduinoPinDescription[ix].modefunc);
    }

    // Take care of USB_VBUS and USB_CONNECT on LPCXpresso 1347 board
    Chip_IOCON_PinMuxSet(LPC_IOCON, 0, 3, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* PIO0_3 used for USB_VBUS */
    Chip_IOCON_PinMuxSet(LPC_IOCON, 0, 6, (IOCON_FUNC1 | IOCON_MODE_INACT)); /* PIO0_6 used for USB_CONNECT */
}

#ifdef __cplusplus
}
#endif



