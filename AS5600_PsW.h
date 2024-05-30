#ifndef _AS5600_PsW_cbbca5380e886eb45660f9565d9e4d78f484a2d7d60682f313ec351bef31dbf4
#define _AS5600_PsW_cbbca5380e886eb45660f9565d9e4d78f484a2d7d60682f313ec351bef31dbf4

#include <Arduino.h>
#include "Wire.h"

class AS5600_PsW
	{
	public:
		void init();
		int rawAngle();
		bool chechWireCondition(int);




	private:
		//LSB bits
		int numberOfLsbBits{ 8 };

		int wireCondition{ -1 };//0 to 5 are taken already

		//Masks
		//static const uint8_t mask01 = 0b00000011;
		//static const uint8_t mask23 = 0b00001100;
		//static const uint8_t mask45 = 0b00110000;
		//static const uint8_t mask67 = 0b11000000;
		//static const uint8_t lsbMask = 0b00000000;
		//static const uint8_t msbMask = 0b00000000;
		

		//Registers
		static const uint8_t sensorI2CAddress{ 0x36 }; //Sensor Address
		static const uint8_t configRegister{ 0x07 }; //Config Register
		static const uint8_t rawAngleRegister{ 0x0C }; // raw angle
		static const uint8_t angleRegister{ 0x0E }; // scaled output value of raw angle

};



//struct I2CMagneticSensorConfiguration {
//	int sensorI2CAddress;
//	int configRegister;
//	int rawAngleRegister;
//	int angleRegister;
//};

//extern I2CMagneticSensorConfiguration AS5600;
#endif
