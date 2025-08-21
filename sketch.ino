#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define buzzer 5
#define DHTPIN 4 
#define DHTTYPE DHT22  
const int SOIL_MOISTURE_PIN = 35;
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);

  // I2C pins for ESP32
  Wire.begin(32, 33);

  // LCD + Sensor
  lcd.init();
  lcd.backlight();
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("I am SanTiwari07.");
  delay(2000);
  lcd.clear();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int soilMoisturePercentage = map(analogRead(SOIL_MOISTURE_PIN), 0, 4095, 0, 100);

  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error  ");
    return;
  }

  // Serial debug
  Serial.print("Temp: "); Serial.print(t); Serial.println(" *C");
  Serial.print("Humidity: "); Serial.print(h); Serial.println(" %");
  Serial.print("Soil Moisture: "); Serial.print(soilMoisturePercentage); Serial.println(" %");
  Serial.println("---------------------");

  if (t >= 20 && t <= 35 && h >= 40 && h <= 70 && soilMoisturePercentage >= 44 && soilMoisturePercentage <= 68) {
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 0);
    lcd.print("All Good!      ");
    lcd.setCursor(0, 1);
    lcd.print("Plant is Happy :)");
  }
  else {

    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);

    if ((t > 37 || t < 18) && (h > 75 || h < 35) && (soilMoisturePercentage < 40 || soilMoisturePercentage > 72)) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("All Critical!");
      lcd.setCursor(0, 1);
      lcd.print("Check Plant!");
    }
    else if (t < 18) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Temp!");
    }
    else if (t > 37) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Temp!");
    }
    else if (soilMoisturePercentage < 40) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Moisture!");
      lcd.setCursor(0, 1);
      lcd.print("Water Needed");
    }
    else if (soilMoisturePercentage > 72) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Moisture!");
      lcd.setCursor(0, 1);
      lcd.print("Stop Watering");
    }
    else if (h > 75) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Humidity!");
    }
    else if (h < 35) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Humidity!");
    }
    else if (t > 37 && h > 75) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Temp &");
      lcd.setCursor(0, 1);
      lcd.print("High Humidity!");
    }
    else if (t > 37 && h < 35) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Temp &");
      lcd.setCursor(0, 1);
      lcd.print("Low Humidity!");
    }
    else if (t < 18 && h > 75) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Temp &");
      lcd.setCursor(0, 1);
      lcd.print("High Humidity!");
    }
    else if (t < 18 && h < 35) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Temp &");
      lcd.setCursor(0, 1);
      lcd.print("Low Humidity!");
    }
    else if (t > 37 && soilMoisturePercentage < 40) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Temp &");
      lcd.setCursor(0, 1);
      lcd.print("Low Moisture!");
    }
    else if (t < 18 && soilMoisturePercentage > 72) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Temp &");
      lcd.setCursor(0, 1);
      lcd.print("High Moisture!");
    }
    else if (h > 75 && soilMoisturePercentage > 72) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("High Humidity &");
      lcd.setCursor(0, 1);
      lcd.print("High Moisture!");
    }
    else if (h < 35 && soilMoisturePercentage < 40) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Low Humidity &");
      lcd.setCursor(0, 1);
      lcd.print("Low Moisture!");
    }
    
  }

  delay(2000); // update every 2s
}
