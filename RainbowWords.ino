void RAINBOW_IL() {
  for (uint16_t k = 0; k <= 1; k++) {
    strip.setPixelColor(pixelMap[0][k], Wheel((i+0*11+k) & 255));
  }
}

void RAINBOW_EST() {
  for (uint16_t k = 3; k <= 5; k++) {
    strip.setPixelColor(pixelMap[0][k], Wheel((i+0*11+k) & 255));
  }
}

void RAINBOW_UNE() {
  for (uint16_t k = 4; k <= 6; k++) {
    strip.setPixelColor(pixelMap[2][k], Wheel((i+2*11+k) & 255));
  }
}

void RAINBOW_DEUX() {
  for (uint16_t k = 7; k <= 10; k++) {
    strip.setPixelColor(pixelMap[0][k], Wheel((i+0*11+k) & 255));
  }
}

void RAINBOW_TROIS() {
  for (uint16_t k = 6; k <= 10; k++) {
    strip.setPixelColor(pixelMap[1][k], Wheel((i+1*11+k) & 255));
  }
}

void RAINBOW_QUATRE() {
  for (uint16_t k = 0; k <= 5; k++) {
    strip.setPixelColor(pixelMap[1][k], Wheel((i+1*11+k) & 255));
  }
}

void RAINBOW_CINQ_H() {
  for (uint16_t k = 7; k <= 10; k++) {
    strip.setPixelColor(pixelMap[3][k], Wheel((i+3*11+k) & 255));
  }
}

void RAINBOW_SIX() {
  for (uint16_t k = 4; k <= 6; k++) {
    strip.setPixelColor(pixelMap[3][k], Wheel((i+3*11+k) & 255));
  }
}

void RAINBOW_SEPT() {
  for (uint16_t k = 7; k <= 10; k++) {
    strip.setPixelColor(pixelMap[2][k], Wheel((i+2*11+k) & 255));
  }
}

void RAINBOW_HUIT() {
  for (uint16_t k = 0; k <= 3; k++) {
    strip.setPixelColor(pixelMap[3][k], Wheel((i+3*11+k) & 255));
  }
}

void RAINBOW_NEUF() {
  for (uint16_t k = 0; k <= 3; k++) {
    strip.setPixelColor(pixelMap[2][k], Wheel((i+2*11+k) & 255));
  }
}

void RAINBOW_DIX_H() {
  for (uint16_t k = 2; k <= 4; k++) {
    strip.setPixelColor(pixelMap[4][k], Wheel((i+4*11+k) & 255));
  }
}

void RAINBOW_ONZE() {
  for (uint16_t k = 0; k <= 3; k++) {
    strip.setPixelColor(pixelMap[5][k], Wheel((i+5*11+k) & 255));
  }
}

void RAINBOW_MIDI() {
  for (uint16_t k = 0; k <= 3; k++) {
    strip.setPixelColor(pixelMap[4][k], Wheel((i+4*11+k) & 255));
  }
}

void RAINBOW_MINUIT() {
  for (uint16_t k = 5; k <= 10; k++) {
    strip.setPixelColor(pixelMap[4][k], Wheel((i+4*11+k) & 255));
  }
}

void RAINBOW_HEURE() {
  for (uint16_t k = 5; k <= 9; k++) {
    strip.setPixelColor(pixelMap[5][k], Wheel((i+5*11+k) & 255));
  }
}

void RAINBOW_HEURES() {
  RAINBOW_HEURE();
  strip.setPixelColor(pixelMap[5][10], Wheel((i+5*11+10) & 255));
}

void RAINBOW_MOINS() {
  for (uint16_t k = 0; k <= 4; k++) {
    strip.setPixelColor(pixelMap[6][k], Wheel((i+6*11+k) & 255));
  }
}

void RAINBOW_LE() {
  for (uint16_t k = 6; k <= 7; k++) {
    strip.setPixelColor(pixelMap[6][k], Wheel((i+6*11+k) & 255));
  }
}

void RAINBOW_ET() {
  for (uint16_t k = 1; k <= 1; k++) {
    strip.setPixelColor(pixelMap[7][k], Wheel((i+7*11+k) & 255));
  }
}

void RAINBOW_QUART() {
  for (uint16_t k = 3; k <= 7; k++) {
    strip.setPixelColor(pixelMap[7][k], Wheel((i+7*11+k) & 255));
  }
}

void RAINBOW_CINQ_M() {
  for (uint16_t k = 6; k <= 9; k++) {
    strip.setPixelColor(pixelMap[8][k], Wheel((i+8*11+k) & 255));
  }
}

void RAINBOW_DIX_M() {
  for (uint16_t k = 8; k <= 10; k++) {
    strip.setPixelColor(pixelMap[6][k], Wheel((i+6*11+k) & 255));
  }
}


void RAINBOW_VINGT() {
  for (uint16_t k = 0; k <= 4; k++) {
    strip.setPixelColor(pixelMap[8][k], Wheel((i+8*11+k) & 255));
  }
}

void RAINBOW_ET_DEMIE() {
  for (uint16_t k = 0; k <= 7; k++) {
    strip.setPixelColor(pixelMap[9][k], Wheel((i+9*11+k) & 255));
  }
}

void RAINBOW_VINGT_CINQ() {
  RAINBOW_VINGT();
  strip.setPixelColor(pixelMap[8][5], Wheel((i+8*11+5) & 255));
  RAINBOW_CINQ_M();
}

void RAINBOW_ET_QUART() {
  RAINBOW_ET();
  RAINBOW_QUART();
}

void RAINBOW_LE_QUART() {
  RAINBOW_LE();
  RAINBOW_QUART();
}
