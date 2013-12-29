MCP47X6 Digital-to-Analog Converter Library
===============

This is an Arduino library for interfacing to Microchip MCP47X6 series of DACs.  The following devices are supported.

    MCP4706	8-bit
    MCP4716	10-bit
    MCP4726	12-bit

The DACs are accurate to about 0.4%.

The DACs communicate over the I2C bus.  This library uses the Arduino Wire.h library for that communication.

The devices support three power down modes which reduce current consumption to a couple hundred nano amps at room temp.

This code is (c) copyright 2013, C. Schnarel.  See the attached license.txt file for distribution and derivative permissions.
