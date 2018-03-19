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
const int MODE_SANS_IL_EST = 2;

int stateButton1 = 0;
int stateButton2 = 0;
int stateButton3 = 0;
int stateButton4 = 0;

DateTime displayedTime;

bool button1Pressed = false;
bool button2Pressed = false;
bool button3Pressed = false;
bool button4Pressed = false;

int currentMode;
uint32_t currentColor;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LEDPIN, NEO_GRBW + NEO_KHZ800);
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
  currentMode = MODE_DEFAULT;
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
    IL_EST(currentColor);
    showTime(currentColor);
  }

  if (currentMode == MODE_SANS_IL_EST) {
    //showTime(currentColor);
  }

  if (currentMode == MODE_SECONDS) {
  }

  /*
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
  */
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

void setRow(int row, int x_start, int x_end, uint32_t c) {
  for ( int i = x_start; i <= x_end; i++ ) {
    strip.setPixelColor(pixelMap[row][i], c);
  }
  strip.show();
}

void IL_EST(uint32_t c) {
  setRow(0, 0, 1, c);
  setRow(0, 3, 5, c);
}

void H_UNE(uint32_t c) {
  setRow(2, 4, 6, c);
}

void H_DEUX(uint32_t c) {
  setRow(0, 7, 10, c);
}

void H_TROIS(uint32_t c) {
  setRow(1, 6, 10, c);
}

void H_QUATRE(uint32_t c) {
  setRow(1, 0, 5, c);
}

void H_CINQ(uint32_t c) {
  setRow(3, 7, 10, c);
}

void H_SIX(uint32_t c) {
  setRow(3, 4, 6, c);
}

void H_SEPT(uint32_t c) {
  setRow(2, 7, 10, c);
}

void H_HUIT(uint32_t c) {
  setRow(3, 0, 3, c);
}

void H_NEUF(uint32_t c) {
  setRow(2, 0, 3, c);
}

void H_DIX(uint32_t c) {
  setRow(4, 2, 4, c);
}

void H_ONZE(uint32_t c) {
  setRow(5, 0, 3, c);
}

void MIDI(uint32_t c) {
  setRow(4, 0, 3, c);
}

void MINUIT(uint32_t c) {
  setRow(4, 5, 10, c);
}

void HEURE(uint32_t c) {
  setRow(5, 5, 9, c);
}

void HEURES(uint32_t c) {
  setRow(5, 5, 10, c);
}

void MOINS_LE_QUART(uint32_t c) {
  setRow(6, 0, 4, c);
  setRow(6, 6, 7, c);
  setRow(7, 3, 7, c);
}

void MOINS(uint32_t c) {
  setRow(6, 0, 4, c);
}

void M_CINQ(uint32_t c) {
  setRow(8, 6, 9, c);
}

void M_DIX(uint32_t c) {
  setRow(6, 8, 10, c);
}

void ET_QUART(uint32_t c) {
  setRow(7, 0, 1, c);
  setRow(7, 3, 7, c);
}

void M_VINGT(uint32_t c) {
  setRow(8, 0, 4, c);
}

void M_VINGT_CINQ(uint32_t c) {
  setRow(8, 0, 10, c);
}

void ET_DEMIE(uint32_t c) {
  setRow(9, 0, 1, c);
  setRow(9, 3, 7, c);
}

void showTime(uint32_t c) {
  if (rtc.now().unixtime() - displayedTime.unixtime() < 60) {
    Serial.print("Same time\n");
    return;
  }
  displayedTime = rtc.now();
  strip.show(); // Clear the strip
  int hour = rtc.now().hour();
  int minute = rtc.now().minute();
  int second = rtc.now().second();

  if (minute >= 35) {
    MOINS(currentColor);
    hour++;
    if (minute >= 35 && minute < 40) M_VINGT_CINQ(currentColor);
    if (minute >= 40 && minute < 45) M_VINGT(currentColor);
    if (minute >= 45 && minute < 50) MOINS_LE_QUART(currentColor);
    if (minute >= 50 && minute < 55) M_DIX(currentColor);
    if (minute >= 55 && minute < 60) M_CINQ(currentColor);
  } else {
    if (minute >= 5 && minute < 10) M_CINQ(currentColor);
    if (minute >= 10 && minute < 15) M_DIX(currentColor);
    if (minute >= 15 && minute < 20) ET_QUART(currentColor);
    if (minute >= 20 && minute < 25) M_VINGT(currentColor);
    if (minute >= 25 && minute < 30) M_VINGT_CINQ(currentColor);
    if (minute >= 30 && minute < 35) ET_DEMIE(currentColor);
  }

  if (hour == 13 || hour == 1) {
    H_UNE(currentColor);
    HEURE(currentColor);
  } else {
    if (hour == 14 || hour == 2) H_DIX(currentColor);
    if (hour == 15 || hour == 3) H_TROIS(currentColor);
    if (hour == 16 || hour == 4) H_QUATRE(currentColor);
    if (hour == 17 || hour == 5) H_CINQ(currentColor);
    if (hour == 18 || hour == 6) H_SIX(currentColor);
    if (hour == 19 || hour == 7) H_SEPT(currentColor);
    if (hour == 20 || hour == 8) H_NEUF(currentColor);
    if (hour == 21 || hour == 9) H_NEUF(currentColor);
    if (hour == 22 || hour == 10) H_DIX(currentColor);
    if (hour == 23 || hour == 11) H_ONZE(currentColor);
    HEURES(currentColor);
  }
  if (hour == 24 || hour == 0) MINUIT(currentColor);
  if (hour == 12) MIDI(currentColor);
}
