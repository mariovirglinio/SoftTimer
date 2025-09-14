# SoftTimer

**SoftTimer** is a lightweight Arduino library that provides simple software timers based on `millis()`.  
It allows you to create periodic or one-shot events without blocking your code with `delay()`.

---

## Features
- Non-blocking timers using `millis()`.
- Easy to set and check expiration.
- Supports long timeouts (up to 24 hours).
- Very small footprint, ideal for Arduino Uno, Nano, Mega, etc.

---

## Installation
1. Download or clone this repository into your Arduino `libraries` folder:
2. Restart the Arduino IDE.
3. Open **File > Examples > SoftTimer** to see usage examples.

---

## Example

```cpp
#include <SoftTimer.h>

tTimerTime myTimer;

void setup() {
Serial.begin(9600);
setTimerEvent(&myTimer, 1000); // 1 second
}

void loop() {
if (TimerHasExpired(&myTimer)) {
 Serial.println("1 second passed!");
 setTimerEvent(&myTimer, 1000); // reset timer
}
}

API
void initTPM2(void);

Initialize the internal timer counter (optional for Arduino).

void setTimerEvent(tTimerTime *event, unsigned long milliseconds);

Start a timer that expires after the given number of milliseconds.

bool TimerHasExpired(tTimerTime *event);

Check if the timer has expired.

unsigned long getMillis(void);

Return the number of milliseconds since the program started.
