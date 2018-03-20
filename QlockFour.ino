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
const int MODE_DEFAULT_COLORCYCLE = 2;

int stateButton1 = 0;
int stateButton2 = 0;
int stateButton3 = 0;
int stateButton4 = 0;

bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;
bool button4Pressed = false;


int currentMode;
uint32_t currentColor;
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
  currentMode = MODE_DEFAULT_COLORCYCLE;
  currentColor = strip.Color(0, 0, 0, 100);
}

void loop() {
  DateTime now = rtc.now();
  stateButton1 = digitalRead(BUT1);
  stateButton2 = digitalRead(BUT2);
  stateButton3 = digitalRead(BUT3);
  stateButton4 = digitalRead(BUT4);

  if (stateButton1 == HIGH) {
    doButton1();
  }
  if (stateButton2 == HIGH) {
    doButton2();
  }
  if (stateButton3 == HIGH) {
    doButton3();
  }
  if (stateButton4 == HIGH) {
    doButton4();
  }

  if (currentMode == MODE_DEFAULT) {
    if (rtc.now().hour() == displayedTime.hour() && rtc.now().minute() == displayedTime.minute()) return;
    showTime(currentColor);
  }

  if (currentMode == MODE_DEFAULT_COLORCYCLE) {
    for (uint16_t j = 0; j < 256; j++) {
      for (uint16_t i = 0; i < strip.numPixels(); i++) {
        showTime(Wheel(((i * 256 / strip.numPixels()) + j) & 255));
        delay(400);
      }
    }
  }

  if (currentMode == MODE_SECONDS) {
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

}

void IL(uint32_t c) {
  strip.setPixelColor(pixelMap[0][0], c);
  strip.setPixelColor(pixelMap[0][1], c);
}

void EST(uint32_t c) {
  strip.setPixelColor(pixelMap[0][3], c);
  strip.setPixelColor(pixelMap[0][4], c);
  strip.setPixelColor(pixelMap[0][5], c);
}

void UNE(uint32_t c) {
  strip.setPixelColor(pixelMap[3][4], c);
  strip.setPixelColor(pixelMap[3][5], c);
  strip.setPixelColor(pixelMap[3][6], c);
}

void DEUX(uint32_t c) {
  strip.setPixelColor(pixelMap[0][7], c);
  strip.setPixelColor(pixelMap[0][8], c);
  strip.setPixelColor(pixelMap[0][9], c);
  strip.setPixelColor(pixelMap[0][10], c);
}

void TROIS(uint32_t c) {
  strip.setPixelColor(pixelMap[1][6], c);
  strip.setPixelColor(pixelMap[1][7], c);
  strip.setPixelColor(pixelMap[1][8], c);
  strip.setPixelColor(pixelMap[1][9], c);
  strip.setPixelColor(pixelMap[1][10], c);
}

void QUATRE(uint32_t c) {
  strip.setPixelColor(pixelMap[1][0], c);
  strip.setPixelColor(pixelMap[1][1], c);
  strip.setPixelColor(pixelMap[1][2], c);
  strip.setPixelColor(pixelMap[1][3], c);
  strip.setPixelColor(pixelMap[1][4], c);
  strip.setPixelColor(pixelMap[1][5], c);
}

void CINQ_H(uint32_t c) {
  strip.setPixelColor(pixelMap[3][7], c);
  strip.setPixelColor(pixelMap[3][8], c);
  strip.setPixelColor(pixelMap[3][9], c);
  strip.setPixelColor(pixelMap[3][10], c);
}

void SIX(uint32_t c) {
  strip.setPixelColor(pixelMap[3][4], c);
  strip.setPixelColor(pixelMap[3][5], c);
  strip.setPixelColor(pixelMap[3][6], c);
}

void SEPT(uint32_t c) {
  strip.setPixelColor(pixelMap[2][7], c);
  strip.setPixelColor(pixelMap[2][8], c);
  strip.setPixelColor(pixelMap[2][9], c);
  strip.setPixelColor(pixelMap[2][10], c);
}

void HUIT(uint32_t c) {
  strip.setPixelColor(pixelMap[3][0], c);
  strip.setPixelColor(pixelMap[3][1], c);
  strip.setPixelColor(pixelMap[3][2], c);
  strip.setPixelColor(pixelMap[3][3], c);
}

void NEUF(uint32_t c) {
  strip.setPixelColor(pixelMap[2][0], c);
  strip.setPixelColor(pixelMap[2][1], c);
  strip.setPixelColor(pixelMap[2][2], c);
  strip.setPixelColor(pixelMap[2][3], c);
}

void DIX_H(uint32_t c) {
  strip.setPixelColor(pixelMap[4][2], c);
  strip.setPixelColor(pixelMap[4][3], c);
  strip.setPixelColor(pixelMap[4][4], c);
}

void ONZE(uint32_t c) {
  strip.setPixelColor(pixelMap[5][0], c);
  strip.setPixelColor(pixelMap[5][1], c);
  strip.setPixelColor(pixelMap[5][2], c);
  strip.setPixelColor(pixelMap[5][3], c);
}

void MIDI(uint32_t c) {
  strip.setPixelColor(pixelMap[4][0], c);
  strip.setPixelColor(pixelMap[4][1], c);
  strip.setPixelColor(pixelMap[4][2], c);
  strip.setPixelColor(pixelMap[4][3], c);
}

void MINUIT(uint32_t c) {
  strip.setPixelColor(pixelMap[4][5], c);
  strip.setPixelColor(pixelMap[4][6], c);
  strip.setPixelColor(pixelMap[4][7], c);
  strip.setPixelColor(pixelMap[4][8], c);
  strip.setPixelColor(pixelMap[4][9], c);
  strip.setPixelColor(pixelMap[4][10], c);
}

void HEURE(uint32_t c) {
  strip.setPixelColor(pixelMap[5][5], c);
  strip.setPixelColor(pixelMap[5][6], c);
  strip.setPixelColor(pixelMap[5][7], c);
  strip.setPixelColor(pixelMap[5][8], c);
  strip.setPixelColor(pixelMap[5][9], c);
}

void HEURES(uint32_t c) {
  HEURE(c);
  strip.setPixelColor(pixelMap[5][10], c);
}

void MOINS(uint32_t c) {
  strip.setPixelColor(pixelMap[6][0], c);
  strip.setPixelColor(pixelMap[6][1], c);
  strip.setPixelColor(pixelMap[6][2], c);
  strip.setPixelColor(pixelMap[6][3], c);
  strip.setPixelColor(pixelMap[6][4], c);
}

void LE(uint32_t c) {
  strip.setPixelColor(pixelMap[6][6], c);
  strip.setPixelColor(pixelMap[6][7], c);
}

void ET(uint32_t c) {
  strip.setPixelColor(pixelMap[7][0], c);
  strip.setPixelColor(pixelMap[7][1], c);
}

void QUART(uint32_t c) {
  strip.setPixelColor(pixelMap[7][3], c);
  strip.setPixelColor(pixelMap[7][4], c);
  strip.setPixelColor(pixelMap[7][5], c);
  strip.setPixelColor(pixelMap[7][6], c);
  strip.setPixelColor(pixelMap[7][7], c);
}

void CINQ_M(uint32_t c) {
  strip.setPixelColor(pixelMap[8][6], c);
  strip.setPixelColor(pixelMap[8][7], c);
  strip.setPixelColor(pixelMap[8][8], c);
  strip.setPixelColor(pixelMap[8][9], c);
}

void DIX_M(uint32_t c) {
  strip.setPixelColor(pixelMap[6][8], c);
  strip.setPixelColor(pixelMap[6][9], c);
  strip.setPixelColor(pixelMap[6][10], c);
}


void VINGT(uint32_t c) {
  strip.setPixelColor(pixelMap[8][0], c);
  strip.setPixelColor(pixelMap[8][1], c);
  strip.setPixelColor(pixelMap[8][2], c);
  strip.setPixelColor(pixelMap[8][3], c);
  strip.setPixelColor(pixelMap[8][4], c);
}

void ET_DEMIE(uint32_t c) {
  strip.setPixelColor(pixelMap[9][0], c);
  strip.setPixelColor(pixelMap[9][1], c);
  strip.setPixelColor(pixelMap[9][3], c);
  strip.setPixelColor(pixelMap[9][4], c);
  strip.setPixelColor(pixelMap[9][5], c);
  strip.setPixelColor(pixelMap[9][6], c);
  strip.setPixelColor(pixelMap[9][7], c);
}

void VINGT_CINQ(uint32_t c) {
  VINGT(c);
  strip.setPixelColor(pixelMap[9][5], c);
  CINQ_M(c);
}

void ET_QUART(uint32_t c) {
  ET(c);
  QUART(c);
}

void LE_QUART(uint32_t c) {
  LE(c);
  QUART(c);
}

void showTime(uint32_t c) {
  int hour = rtc.now().hour();
  int minute = rtc.now().minute();
  int second = rtc.now().second();

  displayedTime = rtc.now();
  strip.clear();

  IL(c);
  EST(c);

  if (minute >= 35) {
    MOINS(c);
    hour++;
    if (minute >= 35 && minute < 40) VINGT_CINQ(c);
    if (minute >= 40 && minute < 45) VINGT(c);
    if (minute >= 45 && minute < 50) LE_QUART(c);
    if (minute >= 50 && minute < 55) DIX_M(c);
    if (minute >= 55 && minute < 60) CINQ_M(c);
  } else {
    if (minute >= 5 && minute < 10) CINQ_M(c);
    if (minute >= 10 && minute < 15) DIX_M(c);
    if (minute >= 15 && minute < 20) ET_QUART(c);
    if (minute >= 20 && minute < 25) VINGT(c);
    if (minute >= 25 && minute < 30) VINGT_CINQ(c);
    if (minute >= 30 && minute < 35) ET_DEMIE(c);
  }

  if (hour == 13 || hour == 1) {
    UNE(c); HEURE(c);
  } else {
    if (hour == 14 || hour == 2) DIX_H(c);
    if (hour == 15 || hour == 3) TROIS(c);
    if (hour == 16 || hour == 4) QUATRE(c);
    if (hour == 17 || hour == 5) CINQ_H(c);
    if (hour == 18 || hour == 6) SIX(c);
    if (hour == 19 || hour == 7) SEPT(c);
    if (hour == 20 || hour == 8) HUIT(c);
    if (hour == 21 || hour == 9) NEUF(c);
    if (hour == 22 || hour == 10) DIX_H(c);
    if (hour == 23 || hour == 11) ONZE(c);
    HEURES(c);
  }
  if (hour == 24 || hour == 0) MINUIT(c);
  if (hour == 12) MIDI(c);

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
