void DIGIT_ZERO(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[3][6 - shift], c);
  strip.setPixelColor(pixelMap[3][10 - shift], c);
  strip.setPixelColor(pixelMap[4][6 - shift], c);
  strip.setPixelColor(pixelMap[4][10 - shift], c);
  strip.setPixelColor(pixelMap[5][6 - shift], c);
  strip.setPixelColor(pixelMap[5][10 - shift], c);
  strip.setPixelColor(pixelMap[6][6 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][6 - shift], c);
  strip.setPixelColor(pixelMap[7][10 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}


void DIGIT_ONE(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[3][8 - shift], c);
  strip.setPixelColor(pixelMap[3][7 - shift], c);
  strip.setPixelColor(pixelMap[4][8 - shift], c);
  strip.setPixelColor(pixelMap[5][8 - shift], c);
  strip.setPixelColor(pixelMap[6][8 - shift], c);
  strip.setPixelColor(pixelMap[7][8 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}

void DIGIT_TWO(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[3][6 - shift], c);
  strip.setPixelColor(pixelMap[3][10 - shift], c);
  strip.setPixelColor(pixelMap[4][10 - shift], c);
  strip.setPixelColor(pixelMap[5][9 - shift], c);
  strip.setPixelColor(pixelMap[6][8 - shift], c);
  strip.setPixelColor(pixelMap[7][7 - shift], c);
  strip.setPixelColor(pixelMap[8][6 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
  strip.setPixelColor(pixelMap[8][10 - shift], c);
}

void DIGIT_THREE(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][6 - shift], c);
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[2][10 - shift], c);
  strip.setPixelColor(pixelMap[3][9 - shift], c);
  strip.setPixelColor(pixelMap[4][8 - shift], c);
  strip.setPixelColor(pixelMap[5][9 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][10 - shift], c);
  strip.setPixelColor(pixelMap[7][6 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}

void DIGIT_FOUR(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[3][9 - shift], c);
  strip.setPixelColor(pixelMap[3][8 - shift], c);
  strip.setPixelColor(pixelMap[4][9 - shift], c);
  strip.setPixelColor(pixelMap[4][7 - shift], c);
  strip.setPixelColor(pixelMap[5][9 - shift], c);
  strip.setPixelColor(pixelMap[5][6 - shift], c);
  strip.setPixelColor(pixelMap[6][6 - shift], c);
  strip.setPixelColor(pixelMap[6][7 - shift], c);
  strip.setPixelColor(pixelMap[6][8 - shift], c);
  strip.setPixelColor(pixelMap[6][9 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][9 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}

void DIGIT_FIVE(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][6 - shift], c);
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[2][10 - shift], c);
  strip.setPixelColor(pixelMap[3][6 - shift], c);
  strip.setPixelColor(pixelMap[4][6 - shift], c);
  strip.setPixelColor(pixelMap[4][7 - shift], c);
  strip.setPixelColor(pixelMap[4][8 - shift], c);
  strip.setPixelColor(pixelMap[4][9 - shift], c);
  strip.setPixelColor(pixelMap[5][10 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][6 - shift], c);
  strip.setPixelColor(pixelMap[7][10 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}

void DIGIT_SIX(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[3][7 - shift], c);
  strip.setPixelColor(pixelMap[4][6 - shift], c);
  strip.setPixelColor(pixelMap[5][6 - shift], c);
  strip.setPixelColor(pixelMap[5][7 - shift], c);
  strip.setPixelColor(pixelMap[5][8 - shift], c);
  strip.setPixelColor(pixelMap[5][9 - shift], c);
  strip.setPixelColor(pixelMap[6][6 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][6 - shift], c);
  strip.setPixelColor(pixelMap[7][10 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}

void DIGIT_SEVEN(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][6 - shift], c);
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[2][10 - shift], c);
  strip.setPixelColor(pixelMap[3][10 - shift], c);
  strip.setPixelColor(pixelMap[4][9 - shift], c);
  strip.setPixelColor(pixelMap[5][8 - shift], c);
  strip.setPixelColor(pixelMap[6][7 - shift], c);
  strip.setPixelColor(pixelMap[7][7 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
}

void DIGIT_EIGHT(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[3][6 - shift], c);
  strip.setPixelColor(pixelMap[3][10 - shift], c);
  strip.setPixelColor(pixelMap[4][6 - shift], c);
  strip.setPixelColor(pixelMap[4][10 - shift], c);
  strip.setPixelColor(pixelMap[5][7 - shift], c);
  strip.setPixelColor(pixelMap[5][8 - shift], c);
  strip.setPixelColor(pixelMap[5][9 - shift], c);
  strip.setPixelColor(pixelMap[6][6 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][6 - shift], c);
  strip.setPixelColor(pixelMap[7][10 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
  strip.setPixelColor(pixelMap[8][9 - shift], c);
}

void DIGIT_NINE(bool left, uint32_t c) {
  int shift = 0;
  if (left) shift = 6;
  strip.setPixelColor(pixelMap[2][7 - shift], c);
  strip.setPixelColor(pixelMap[2][8 - shift], c);
  strip.setPixelColor(pixelMap[2][9 - shift], c);
  strip.setPixelColor(pixelMap[3][6 - shift], c);
  strip.setPixelColor(pixelMap[3][10 - shift], c);
  strip.setPixelColor(pixelMap[4][6 - shift], c);
  strip.setPixelColor(pixelMap[4][10 - shift], c);
  strip.setPixelColor(pixelMap[5][7 - shift], c);
  strip.setPixelColor(pixelMap[5][8 - shift], c);
  strip.setPixelColor(pixelMap[5][9 - shift], c);
  strip.setPixelColor(pixelMap[5][10 - shift], c);
  strip.setPixelColor(pixelMap[6][10 - shift], c);
  strip.setPixelColor(pixelMap[7][6 - shift], c);
  strip.setPixelColor(pixelMap[7][9 - shift], c);
  strip.setPixelColor(pixelMap[8][7 - shift], c);
  strip.setPixelColor(pixelMap[8][8 - shift], c);
}
