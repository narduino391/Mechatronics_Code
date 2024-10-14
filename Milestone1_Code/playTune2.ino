#include "pitches.h"

int REST = 0;

//Stores melody
int melody2[] = {
    NOTE_E4,
    NOTE_G4,
    NOTE_A4,
    NOTE_A4,
    REST,
    NOTE_A4,
    NOTE_B4,
    NOTE_C5,
    NOTE_C5,
    REST,
    NOTE_C5,
    NOTE_D5,
    NOTE_B4,
    NOTE_B4,
    REST,
    NOTE_A4,
    NOTE_G4,
    NOTE_A4,
  };

  int noteDurations2[] = {
    8,
    8,
    4,
    8,
    8,
    8,
    8,
    4,
    8,
    8,
    8,
    8,
    4,
    8,
    8,
    8,
    8,
    4,
  };

//Initializes variables
int thisNote2 = 0;
unsigned long priorTime2 = 0;
int pauseBetweenNotes2 = 0;

bool playTune2() {
  unsigned long elapsedTime = millis() - tuneStartTime;
//Ensures appropriate timing
  if (elapsedTime - priorTime2 > pauseBetweenNotes2) {
    if (thisNote2 < sizeof(melody2)/sizeof(melody2[0])) {  // Check if all notes are played
      int noteDuration = 1000 / noteDurations2[thisNote2];
      tone(tonePin, melody2[thisNote2], noteDuration);
      pauseBetweenNotes2 = noteDuration * 1.30;
      priorTime2 = elapsedTime;
      thisNote2++;
    } else {
      thisNote2 = 0;  // Reset for next time
      return true;    // Tune is finished
    }
  }

  return false;  // Tune is not finished
}
