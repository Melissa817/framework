#include <Arduino.h>
#include <ESPDateTime.h>
#include <cmath>
#include <sensor.h>
#include <display.h>
#include <backend.h>

Display display;
Sensor sensor;
Backend backend;

// Always Adapt
//TODO: replace the wifi credentials with your own 
char *SSID = const_cast<char *>("wifiname");                        
char *PW = const_cast<char *>("wifipassword");                      

// Ignore:
//TODO: replace with credentials provided by email
const String BACKEND_UUID = "uuid";                                 
const String BACKEND_TOKEN = "token";                               
const float SENSOR_LAT = 49.12220;                                  
const float SENSOR_LON = 9.21182;                                   
const bool SENSOR_INDOOR = true;

void setup()
{

  Serial.begin(9600);

  display.init();

  backend.init(BACKEND_UUID, BACKEND_TOKEN, SENSOR_LAT, SENSOR_LON, SENSOR_INDOOR);

  backend.connectToWifi(SSID, PW);
  display.setSsid(SSID);

  if (!DateTime.begin(15 * 1000))
  {
    Serial.println("Read current time failed!");
  } 
  else {
    Serial.println(DateFormatter::format("%Y-%m-%dT%H:%M:%S.000Z", DateTime.now() + 2*3600));
  }
  sensor.initSensor();
}

void loop()
{

  bool readSuccessful = sensor.readTemperatureAndPressure();
  display.setReadSuccessful(readSuccessful);

  if (readSuccessful)
  {
    float t = sensor.getTemperature();
    float p = sensor.getPressure();
    display.setTemperature(t);
    display.setDateTime(DateFormatter::format("%d.%m.%Y %H:%M:%S", DateTime.now() + 2*3600));


    // Ignore :
    // TODO: Uncomment once UUID and TOKEN have been provided
    //backend.sendTemperatureMeasurement(t, DateFormatter::format("%Y-%m-%dT%H:%M:%S.000Z", DateTime.now()));
    //backend.sendPressureMeasurement(p, DateFormatter::format("%Y-%m-%dT%H:%M:%S.000Z", DateTime.now()));
  }

  delay(3000);
}