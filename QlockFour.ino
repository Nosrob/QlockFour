#include <RTClib.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

const int LEDPIN = 13;
const int NUM_LEDS = 110;
const int BRIGHTNESS = 50;
const int ROWS = 10;
const int COLUMNS = 11;

const int BUT1 = 9;
const int BUT2 = 10;
const int BUT3 = 11;
const int BUT4 = 12;

const int MODE_DEFAULT = 0;
const int MODE_SECONDS = 1;
const int MODE_COLORCYCLE = 2;
const int MODE_WHITE_OVER_RAINBOW = 3;
const int TEST = -1;

int currentMode;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LEDPIN, NEO_RGBW + NEO_KHZ800);
DateTime displayedTime;
RTC_DS3231 rtc;
int pixelMap[ROWS][COLUMNS] = {
  {109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99},
  {88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98},
  {87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77},
  {66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76},
  {65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55},
  {44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54},
  {43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33},
  {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32},
  {21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
};

byte neopix_gamma[] = {
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
  2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
  5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
  10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
  17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
  25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
  37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
  51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
  69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
  90, 92, 93, 95, 96, 98, 99, 101, 102, 104, 105, 107, 109, 110, 112, 114,
  115, 117, 119, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 138, 140, 142,
  144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 167, 169, 171, 173, 175,
  177, 180, 182, 184, 186, 189, 191, 193, 196, 198, 200, 203, 205, 208, 210, 213,
  215, 218, 220, 223, 225, 228, 231, 233, 236, 239, 241, 244, 247, 249, 252, 255
};

void setup() {
  // Init serial port
  Serial.begin(9600);

  // Clear LED strip
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show();

  // Init RTC module
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  //Init pushbuttons
  pinMode(BUT1, INPUT);
  pinMode(BUT2, INPUT);
  pinMode(BUT3, INPUT);
  pinMode(BUT4, INPUT);

  // Init default mode
  currentMode = MODE_DEFAULT;
}

void loop() {
  DateTime now = rtc.now();
  if (digitalRead(BUT1) == HIGH) doButton1();
  if (digitalRead(BUT2) == HIGH) doButton2();
  if (digitalRead(BUT3) == HIGH) doButton3();
  if (digitalRead(BUT4) == HIGH) doButton4();


  if (currentMode == MODE_DEFAULT) {
    if (rtc.now().hour() == displayedTime.hour()
        && rtc.now().minute() == displayedTime.minute()
        && rtc.now().second() == displayedTime.second()) return;
    strip.clear();
    showTime(strip.Color(0, 0, 0, 200));
  }

  if (currentMode == MODE_COLORCYCLE) {
    for (uint16_t j = 0; j < 256; j++) {
      for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.clear();
        showTime(Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        delay(400);
      }
    }
  }

  if (currentMode == MODE_WHITE_OVER_RAINBOW) {
    for (int j = 0; j < 256; j++) {
      for (uint16_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, dimmerWheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
      showTime(strip.Color(0, 0, 0, 200));
      strip.show();
      delay(20);
    }
  }

  if (currentMode == MODE_SECONDS) {
    int sec = rtc.now().second();
    int leftDigit = sec / 10;
    int rightDigit = sec % 10;

    strip.clear();
    if (rightDigit == 0) DIGIT_ZERO(false , strip.Color(0, 0, 0, 200));
    if (leftDigit == 0) DIGIT_ZERO(true , strip.Color(0, 0, 0, 200));
    if (rightDigit == 1) DIGIT_ONE(false , strip.Color(0, 0, 0, 200));
    if (leftDigit == 1) DIGIT_ONE(true , strip.Color(0, 0, 0, 200));
    if (rightDigit == 2) DIGIT_TWO(false , strip.Color(0, 0, 0, 200));
    if (leftDigit == 2) DIGIT_TWO(true, strip.Color(0, 0, 0, 200));
    if (rightDigit == 3) DIGIT_THREE(false, strip.Color(0, 0, 0, 200));
    if (leftDigit == 3) DIGIT_THREE(true, strip.Color(0, 0, 0, 200));
    if (rightDigit == 4) DIGIT_FOUR(false, strip.Color(0, 0, 0, 200));
    if (leftDigit == 4) DIGIT_FOUR(true, strip.Color(0, 0, 0, 200));
    if (rightDigit == 5) DIGIT_FIVE(false, strip.Color(0, 0, 0, 200));
    if (leftDigit == 5) DIGIT_FIVE(true, strip.Color(0, 0, 0, 200));
    if (rightDigit == 6) DIGIT_SIX(false, strip.Color(0, 0, 0, 200));
    if (rightDigit == 7) DIGIT_SEVEN(false, strip.Color(0, 0, 0, 200));
    if (rightDigit == 8) DIGIT_EIGHT(false, strip.Color(0, 0, 0, 200));
    if (rightDigit == 9) DIGIT_NINE(false, strip.Color(0, 0, 0, 200));
    strip.show();
  }
}

// Add 1 minute with seconds reset to 0
void doButton1() {
  DateTime future (rtc.now() + TimeSpan(0, 0, 1, -rtc.now().second()));
  rtc.adjust(future);
  delay(200);
}

// Add 5 minutes
void doButton2() {
  DateTime future (rtc.now() + TimeSpan(0, 0, 5, 0));
  rtc.adjust(future);
  delay(200);
}


// Add 1 hour
void doButton3() {
  DateTime future (rtc.now() + TimeSpan(0, 1, 0, 0));
  rtc.adjust(future);
  delay(200);
}

// Cycle through lighting modes
void doButton4() {
  // TODO
}

void showTime(uint32_t c) {
  int hour = rtc.now().hour();
  int minute = rtc.now().minute();
  int second = rtc.now().second();

  IL(c);
  EST(c);

  if (minute >= 35) {
    MOINS(c);
    hour++;
  }

  if ((minute >= 5 && minute < 10) || (minute >= 55 && minute < 60)) CINQ_M(c);
  else if ((minute >= 10 && minute < 15) || (minute >= 50 && minute < 55)) DIX_M(c);
  else if (minute >= 15 && minute < 20) ET_QUART(c);
  else if (minute >= 45 && minute < 50) LE_QUART(c);
  else if ((minute >= 20 && minute < 25) || (minute >= 40 && minute < 45)) VINGT(c);
  else if ((minute >= 25 && minute < 30) || (minute >= 35 && minute < 40)) VINGT_CINQ(c);
  else if (minute >= 30 && minute < 35) ET_DEMIE(c);

  if (hour == 13 || hour == 1) UNE(c);
  else if (hour == 14 || hour == 2) DEUX(c);
  else if (hour == 15 || hour == 3) TROIS(c);
  else if (hour == 16 || hour == 4) QUATRE(c);
  else if (hour == 17 || hour == 5) CINQ_H(c);
  else if (hour == 18 || hour == 6) SIX(c);
  else if (hour == 19 || hour == 7) SEPT(c);
  else if (hour == 20 || hour == 8) HUIT(c);
  else if (hour == 21 || hour == 9) NEUF(c);
  else if (hour == 22 || hour == 10) DIX_H(c);
  else if (hour == 23 || hour == 11) ONZE(c);
  else if (hour == 12) MIDI(c);
  else if (hour == 24 || hour == 0) MINUIT(c);

  if (hour == 1) HEURE(c);
  else if ((hour > 1 && hour < 12) || (hour > 12 && hour < 24)) HEURES(c);


  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(minute, DEC);
  Serial.print(":");
  Serial.println(second, DEC);

  displayedTime = rtc.now();
  strip.show();
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

uint32_t dimmerWheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  float dimmerCoeff = 0.3;
  if (WheelPos < 85) {
    return strip.Color(dimmerCoeff * (255 - WheelPos * 3), 0, dimmerCoeff * (WheelPos * 3), 5);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, dimmerCoeff * (WheelPos * 3), dimmerCoeff * (255 - WheelPos * 3), 5);
  }
  WheelPos -= 170;
  return strip.Color(dimmerCoeff * (WheelPos * 3), dimmerCoeff * (255 - WheelPos * 3), 0, 5);
}

