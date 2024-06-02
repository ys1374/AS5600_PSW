#include "AS5600_PsW.h"

//I2CMagneticSensorConfiguration AS5600 = {
//  .se = 0x36,
//  .bit_resolution = 12,
//  .angle_register = 0x0C,
//  .data_start_bit = 11
//};


void AS5600_PsW::init()
{	
	Wire.begin();
}

word AS5600_PsW::readWire(uint8_t _wireRegisterToRead)
{
	uint8_t MSB{ 0 };
	uint8_t LSB{ 0 };

	Wire.beginTransmission(sensorI2CAddress);
	Wire.write(_wireRegisterToRead); //invove the sensor
	wireCondition = Wire.endTransmission();

	if (chechWireCondition(wireCondition) == 0) return;

	Wire.requestFrom(sensorI2CAddress, (uint8_t)2);

	//Read Firstly MSB then LSB
	MSB = Wire.read();
	LSB = Wire.read();

	//numberOfLsbBits is Writen to include more I2C Sensor Later
	return (MSB << numberOfLsbBits) | LSB;
}

bool AS5600_PsW::chechWireCondition(int _wireCondition)
{
	if (_wireCondition != 0) {
		//print sth here
		Serial.print("Error number: ");
		Serial.print(wireCondition);
		Serial.println(" happened in wire transmition of data.");
		Serial.println("1 : data too long to fit in transmit buffer.");
		Serial.println("2 : received NACK on transmit of address.");
		Serial.println("3 : received NACK on transmit of data.");
		Serial.println("4 : other error.");
		Serial.println("5 : timeout");
		delay(10000);
		wireCondition = -1;
		return 0;
	}
	else {
		wireCondition = -1;
		return 1;
	}
}

int AS5600_PsW::rawAngle()
{
	return readWire(rawAngleRegister);
}

float degreeAngle()
{
	return readWire(degreeAngleRegister);
}




//Wire.beginTransmission(sensorI2CAddress); // I2C address of AS5600
//Wire.write(configRegister); // Address of CONF register (0x07)
//Wire.write(0b00000000); // MSB of CONF register (default value)
//Wire.write(0b00000001); // LSB of CONF register 
//wireCondition = Wire.endTransmission();
//
//chechWireCondition(wireCondition);