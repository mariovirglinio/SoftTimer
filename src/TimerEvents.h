#ifndef TIMEREVENTS_H
#define TIMEREVENTS_H

#include <Arduino.h>

typedef unsigned long dword;

/* Estructura de un evento temporizado */
typedef struct {
  dword Start;
  dword Expiration;
} tTimerTime;

/* Inicializa el sistema de timers (opcional en Arduino) */
void initTimer();

/* Programa un evento con duración en milisegundos */
void setTimerEvent(tTimerTime *event, dword miliSeconds);

/* Devuelve true si el evento ha expirado */
bool TimerHasExpired(tTimerTime *event);

/* Devuelve el tiempo actual en ms desde el arranque */
dword getMillis();

#endif

