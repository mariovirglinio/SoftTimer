#include <TimerEvents.h>

tTimerTime ledEvent;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  initTimer();
  setTimerEvent(&ledEvent, 1000); // 1 segundo
}

void loop() {
  if (TimerHasExpired(&ledEvent)) {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // toggle LED
    setTimerEvent(&ledEvent, 1000); // reprogramar
  }
}

