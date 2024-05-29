#ifndef _AS5600_PsW_cbbca5380e886eb45660f9565d9e4d78f484a2d7d60682f313ec351bef31dbf4
#define _AS5600_PsW_cbbca5380e886eb45660f9565d9e4d78f484a2d7d60682f313ec351bef31dbf4

#include <Arduino.h>
#include "Wire.h"

class AS5600_PsW
	{
	public:
		void init();
		int rawAngle();




	private:
		//Masks
		static const uint8_t Mask01 = 0b00000011;
		static const uint8_t Mask23 = 0b00001100;
		static const uint8_t Mask45 = 0b00110000;
		static const uint8_t Mask67 = 0b11000000;

		//Registers
		static const uint8_t sensorI2CAddress = 0x36; //Sensor Address
		static const uint8_t ConfigReg = 0x07; //Config Register
		static const uint8_t rawAngle = 0x0c; // raw angle
		static const uint8_t Angle = 0x0e; // scaled output value of raw angle

};
#endif
