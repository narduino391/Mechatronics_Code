#include "pitches.h"

// Stores melody
int melody1[] = {
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5,
  NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_C5,
  NOTE_C6, NOTE_G6, NOTE_E6, NOTE_C6, NOTE_G6, NOTE_E6,
  
  NOTE_B4, NOTE_B5, NOTE_FS5, NOTE_DS5, NOTE_B5,
  NOTE_FS5, NOTE_DS5, NOTE_DS5, NOTE_E5, NOTE_F5,
  NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_B5
};

int noteDurations1[] = {
  16, 16, 16, 16,
  32, 16, 8, 16,
  16, 16, 16, 32, 16, 8,
  
  16, 16, 16, 16, 32,
  16, 8, 32, 32, 32,
  32, 32, 32, 32, 32, 16, 8
};

//Initializes variables
int thisNote1 = 0;
unsigned long priorTime1 = 0;
int pauseBetweenNotes1 = 0;

bool playTune1() {
  unsigned long elapsedTime = millis() - tuneStartTime;

//Ensures appropriate timing
  if (elapsedTime - priorTime1 > pauseBetweenNotes1) {
    if (thisNote1 < sizeof(melody1)/sizeof(melody1[0])) {
      int noteDuration = 1000 / noteDurations1[thisNote1];
      tone(tonePin, melody1[thisNote1], noteDuration);
      pauseBetweenNotes1 = noteDuration * 1.30;
      priorTime1 = elapsedTime;
      thisNote1++;
      return false;
    } else {
      thisNote1 = 0;
      return true;
    }
  }

  return false;
}


