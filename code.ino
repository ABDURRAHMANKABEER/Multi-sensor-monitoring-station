#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Initialize the 20x4 I2C LCD at address 0x27
LiquidCrystal_I2C lcd(0x27, 20, 4);

void readDHT22() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 2);
    lcd.print(F("DHT Sensor Error!   "));
    lcd.setCursor(0, 3);
    lcd.print(F("                    "));
    return;
  }

  // Row 2: Humidity
  lcd.setCursor(0, 2);
  lcd.print(F("Humidity: "));
  lcd.print(h, 1); // 1 decimal place
  lcd.print(F("%     ")); // Extra spaces clear leftover characters

  // Row 3: Temperature
  lcd.setCursor(0, 3);
  lcd.print(F("Temp:     "));
  lcd.print(t, 1);
  lcd.print(F(" C    "));
}

void readAnalogSensors() {
  float light = analogRead(A0) / 1024.0 * 5.0;
  float volt = analogRead(A1) / 1024.0 * 5.0;

  // Row 0: Light sensor
  lcd.setCursor(0, 0);
  lcd.print(F("Light:    "));
  lcd.print(light, 2); // 2 decimal places
  lcd.print(F(" V    "));

  // Row 1: Potentiometer
  lcd.setCursor(0, 1);
  lcd.print(F("Pot:      "));
  lcd.print(volt, 2);
  lcd.print(F(" V    "));
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  lcd.init();          // Initialize the I2C LCD
  lcd.backlight();     // Turn on the backlight
}

void loop() {
  readAnalogSensors();
  readDHT22();
  
  delay(2000);
}
