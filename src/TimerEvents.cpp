#include "TimerEvents.h"

#define SECONDS_PER_DAY        86400UL
#define MSECS_PER_SECOND       1000UL
#define TICS_PER_DAY           (SECONDS_PER_DAY * MSECS_PER_SECOND)

/* Inicialización (no hace nada en Arduino, pero queda para compatibilidad) */
void initTimer() {
  // En Arduino, millis() ya está disponible
}

/* Configura un evento a X milisegundos desde ahora */
void setTimerEvent(tTimerTime *event, dword miliSeconds) {
  dword now = millis();

  if (miliSeconds > TICS_PER_DAY) {
    miliSeconds = TICS_PER_DAY;
  }

  event->Start = now;
  event->Expiration = now + miliSeconds;
}

/* Devuelve true si ya expiró el evento */
bool TimerHasExpired(tTimerTime *event) {
  dword now = millis();

  // Expiración normal
  if (now >= event->Expiration) {
    return true;
  }

  // Manejo de overflow de millis()
  if ((now < event->Start) && ((now + TICS_PER_DAY) > event->Expiration)) {
    return true;
  }

  return false;
}

/* Tiempo actual en milisegundos */
dword getMillis() {
  return millis();
}

