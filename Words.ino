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
  strip.setPixelColor(pixelMap[8][5], c);
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
