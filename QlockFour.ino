#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUM_LEDS 160
#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);
DS3231 Clock;

void setup() {

  // Start the serial port
  Serial.begin(57600);

  // Start the I2C interface
  Wire.begin();

  // Clear LED strip
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();

}

void loop() {

}
