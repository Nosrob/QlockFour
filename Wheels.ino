// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
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
