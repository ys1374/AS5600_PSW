#include "AS5600_PsW.h"

//I2CMagneticSensorConfiguration AS5600 = {
//  .se = 0x36,
//  .bit_resolution = 12,
//  .angle_register = 0x0C,
//  .data_start_bit = 11
//};


AS5600_PsW::init() 
{	
	Wire.begin();

    Wire.beginTransmission(sensorI2CAddress); // I2C address of AS5600
    Wire.write(ConfigReg); // Address of CONF register (0x07)
    Wire.write(0b00000000); // MSB of CONF register (default value)
    Wire.write(0b00000001); // LSB of CONF register 
}

AS5600_PsW::rawAngle()
{
	uint16_t rawAngle{ 0 };
	uint8_t MSB{ 0 };
	uint8_t LSB{ 0 };

	Wire.beginTransmission(sensorI2CAddress);
	Wire.write(rawAngleRegister);
	wireCondition = Wire.endTransmission();

	if (wireCondition != 0) {
		//print sth here
		return
	}

	//Read Firstly MSB then LSB
	MSB = Wire.read();
	LSB = Wire.read();

	//numberOfLsbBits is Writen to include more I2C Sensor Later
	return (MSB << numberOfLsbBits) | LSB;
}



