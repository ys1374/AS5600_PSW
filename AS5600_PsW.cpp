#include "AS5600_PsW.h"

AS5600_PsW::init() 
{
    Wire.beginTransmission(sensorI2CAddress); // I2C address of AS5600
    Wire.write(ConfigReg); // Address of CONF register (0x07)
    Wire.write(0b00000000); // MSB of CONF register (default value)
    Wire.write(0b00000001); // LSB of CONF register 
}

AS5600_PsW::rawAngle()
{

}
