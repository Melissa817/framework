#include <Arduino.h>
#include <Wire.h>
#include <limits>
#include <sensor.h>

#define I2C_SDA 21
#define I2C_SCL 13
#define I2C_ADDR 0x76

// Chip ID and important registers
#define BMP280_CHIP_ID 0x58
#define BMP280_CHIP_ID_REG 0xD0

// Calibration data registers
#define BMP_DIG_T1_REG 0x88
#define BMP_DIG_T2_REG 0x8A
#define BMP_DIG_T3_REG 0x8C
#define BMP_DIG_P1_REG 0x8E
#define BMP_DIG_P2_REG 0x90
#define BMP_DIG_P3_REG 0x92
#define BMP_DIG_P4_REG 0x94
#define BMP_DIG_P5_REG 0x96
#define BMP_DIG_P6_REG 0x98
#define BMP_DIG_P7_REG 0x9A
#define BMP_DIG_P8_REG 0x9C
#define BMP_DIG_P9_REG 0x9E

// Configuration registers
#define BMP_CONFIG_REG 0xF4
#define BMP_FILTER_REG 0xF5

// Temperature registers
#define BMP_TEMP_MSB_REG 0xFA
#define BMP_TEMP_LSB_REG 0xFB
#define BMP_TEMP_XLSB_REG 0xFC

// Pressure registers
#define BMP_PRESS_MSB_REG 0xF7
#define BMP_PRESS_LSB_REG 0xF8
#define BMP_PRESS_XLSB_REG 0xF9

uint16_t Sensor::read16(byte reg)
{
   // TODO: Read 2 registers in sequence
  // - Read LSB
  // - Read MSB
  // - Combine into 16-bit value (MSB << 8 | LSB)
  return 0;
}

uint8_t Sensor::read8(byte reg)
{
 // TODO: Read 1 byte from the given register
  // - Start transmission
  // - Send register address
  // - Request and read 1 byte
  // - Add error handling (try-catch)
  return 0;
}

void Sensor::write8(byte reg, uint8_t val)
{
 // TODO: Write 1 byte to the given register
  // - Start transmission
  // - Send register address and value
  // - End transmission
}

void Sensor::initSensor()
{
 // TODO: Initialize I2C with SDA and SCL pins

  // TODO: Read sensor chip ID
  // - Check if ID matches BMP280_CHIP_ID (0x58)

  // TODO: Read calibration data
  // - Read dig_T1, dig_T2, dig_T3
  // - Read dig_P1 through dig_P9

  // TODO: Configure the sensor
  // - Set filter settings
  // - Set measurement mode
}

float Sensor::getTemperature()
{
   // TODO: Return the calculated temperature
   return temperature;
}

float Sensor::getPressure()
{
    // TODO: Return the calculated pressure
    return pressure;
}

int32_t Sensor::readRawData(byte msbReg, byte lsbReg, byte xlsbReg)
{
 // TODO: Read raw sensor data
  // - Read MSB, LSB, XLSB from provided register addresses
  // - Assemble 20-bit raw value
  return 0;
}

int32_t Sensor::readRawTemperature()
{
  // TODO: Read raw temperature data
  return 0;
}

int32_t Sensor::readRawPressure()
{
  // TODO: Read raw pressure data
  return 0;
}

float Sensor::compensateTemperature(int32_t adc_T)
{
  // TODO: Calculate the real temperature using calibration data
  // - Follow the datasheet formula (floating point version)
  return 0.0;
}

float Sensor::compensatePressure(int32_t adc_P)
{
  // TODO: Calculate the real pressure using calibration data
  // - Follow the datasheet formula (floating point version)
  return 0.0;
}

bool Sensor::readTemperatureAndPressure()
{
  try
  {
    // TODO: Read raw temperature and pressure values
    // - Read raw temperature
    // - Read raw pressure

    // TODO: Apply compensation formulas
    // - Calculate actual temperature
    // - Calculate actual pressure

    // TODO: Save the calculated values to the class variables

    // TODO: Reset forced mode (write to the config register)

    return true;
  }
  catch (uint8_t err)
  {
    Serial.println("Sensor error: " + String(err));
    return false;
  }
}
