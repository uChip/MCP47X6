/**************************************************************************/
/*! 
    @file     MCP47X6.h
    @author   C. Schnarel
	@license  BSD (see license.txt)
	
    This is part of an Arduino library to interface with the Microchip
    MCP47X6 series of Digital-to-Analog converters which are connected
    via the I2C bus.

    This file is the MCP47X6 I2C device class header file
    Based on Microchip datasheets for the following part numbers
        MCP4706 (8-bit), MCP4716 (10-bit), MCP4726 (12-bit)
    These parts share a common programming interface

    (c) Copyright 2013-Dec-24 Chip Schnarel <schnarel@hotmail.com>

    Updates should (hopefully) always be available at
        https://github.com/uchip/MCP47X6

	@section  HISTORY

    2013-Dec-25  - First release, C. Schnarel
*/
/**************************************************************************/

#ifndef _MCP47X6_H_
#define _MCP47X6_H_

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif
#else
    #include "ArduinoWrapper.h"
#endif

#include <Wire.h>

// I2C Address of device
// MCP4706, MCP4716 & MCP4726 are factory programed for any of 0x60 thru 0x67
//  commonly 0x60
#define MCP47X6_DEFAULT_ADDRESS	0x60

/** Config Data Defn
 * Config = 0bCCCVVPPG
 */

// Programmable Gain definitions
#define MCP47X6_GAIN_MASK	0xFE
#define MCP47X6_GAIN_1X	0x00
#define MCP47X6_GAIN_2X	0x01

// Power Down Mode definitions
#define MCP47X6_PWRDN_MASK     0xF9
#define MCP47X6_AWAKE          0x00
#define MCP47X6_PWRDN_1K       0x02
#define MCP47X6_PWRDN_100K     0x04
#define MCP47X6_PWRDN_500K     0x06

// Reference Voltage definitions
#define MCP47X6_VREF_MASK             0xE7
#define MCP47X6_VREF_VDD              0x00
#define MCP47X6_VREF_VREFPIN	      0x10
#define MCP47X6_VREF_VREFPIN_BUFFERED 0x18

// Command definitioins
#define MCP47X6_CMD_MASK       0x1F
#define MCP47X6_CMD_VOLDAC     0x00
#define MCP47X6_CMD_VOLALL     0x40
#define MCP47X6_CMD_VOLCONFIG  0x80
#define MCP47X6_CMD_ALL        0x60


class MCP47X6 {
    public:
        MCP47X6();
        MCP47X6(uint8_t address);
        
        bool testConnection(void);

	   bool begin(void);
	   bool begin(uint8_t config);

        // Set the configuration bits for the DAC
        void setGain(uint8_t gain);
        void setVReference(uint8_t ref);
        bool saveSettings(void);

        // Set the DAC
        bool setOutputLevel(uint8_t level);
        bool setOutputLevel(uint16_t level);

	   // Power Down
	   // NOTE: writing any settings or DAC value
	   // will awaken device
        bool powerDown(uint8_t pdOutR);
        bool powerDown(void);

    private:
        bool writeConfigReg(uint8_t theConfig);
        uint8_t devAddr;
        uint8_t config;
};

#endif /* _MCP47X6_H_ */
