#include <display.h>

void Display::refreshContent()
{
//TODO: Insert your own output here
  display.drawString(10, 10, "Hello World");
  display.display();

// Example on the Display 
// 1. Zeile AI-Sensorik
// 2. Zeile: temperatur + air pressure or error message
// 3. Zeile: connected to WiFi ? + name

  
}

void Display::init()
{
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(50);
  digitalWrite(16, HIGH);
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);

  refreshContent();

  delay(400);
}

void Display::setReadSuccessful(bool successful)
{
  lastReadSuccessful = successful;
  refreshContent();
}

void Display::setSsid(char *ssid)
{
  wifiSsid = String(ssid);
  refreshContent();
}

void Display::setTemperature(float temperature)
{
  lastTemperature = temperature;
  refreshContent();
}
void Display::setPressure(float pressure)
{
  lastPressure = pressure;
  refreshContent();
}

void Display::setDateTime(String dateTime)
{
  this->dateTime = dateTime;
}
