#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  int adcValue = analogRead(34); // Read the analog value from the microphone on GPIO34

  // scale/shift the 12-bit ADC input value to a 4-bit value To achieve a 4-bit effect
  int fourBitValue = adcValue >> 8;

  // However, DACs on most Arduino-compatible boards, including ESP32, expect an 8-bit input (0-255).
  // So, we scale the 4-bit value back up to 8 bits for the DAC output.
  int dacValue = fourBitValue << 4; // Scale the 4-bit value up to 8-bit

  dacWrite(25, dacValue); // Output the scaled value to the DAC on GPIO25
  
  delayMicroseconds(120);
  // Using a short delay to control the frequency of the output signal
}
