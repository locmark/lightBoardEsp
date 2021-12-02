#include "uart.hpp"
char buff[]="Hello Slave\n";

void setup() {
  Serial.begin(115200);
  Serial.println("siemanero, tu ESP!");
  UART_init();
}

void loop() {
  UART_update();
  
  Serial.print("inputState: ");
  Serial.println(PIC::inputState);
  Serial.print("outputState: ");
  Serial.println(PIC::outputState);
  Serial.print("dimmer_1: ");
  Serial.println(PIC::dimmer_1);
  Serial.print("dimmer_2: ");
  Serial.println(PIC::dimmer_2);
  Serial.print("dimmer_3: ");
  Serial.println(PIC::dimmer_3);
  Serial.print("dimmer_4: ");
  Serial.println(PIC::dimmer_4);
  Serial.print("dimmer_5: ");
  Serial.println(PIC::dimmer_5);
  Serial.print("dimmer_6: ");
  Serial.println(PIC::dimmer_6);
  Serial.print("dimmer_7: ");
  Serial.println(PIC::dimmer_7);
  Serial.print("current_1: ");
  Serial.println(PIC::current_1);
  Serial.print("current_2: ");
  Serial.println(PIC::current_2);
  Serial.print("current_3: ");
  Serial.println(PIC::current_3);
  Serial.print("current_4: ");
  Serial.println(PIC::current_4);
  Serial.print("current_5: ");
  Serial.println(PIC::current_5);
  Serial.print("current_6: ");
  Serial.println(PIC::current_6);
  Serial.print("current_7: ");
  Serial.println(PIC::current_7);

  delay(10);  
}