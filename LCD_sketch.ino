#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 7
#define DHTTYPE DHT11

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);

  lcd.setCursor(0, 0);
  lcd.print(F("Temp: "));
  lcd.print(f);
  lcd.setCursor(0, 1 );
  lcd.print(F("Ht In: "));
  lcd.print(hif);
}
