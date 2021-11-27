#include "SPI.h"
char buff[]="Hello Slave\n";

void setup() {
  Serial.begin(115200);
  Serial.println("siemanero, tu ESP!");
  SPI.begin();
}

void loop() {
  Serial.println("sending stuff via SPI");
  // char recvBuff[32] = {0};
  for(int i=0; i < sizeof buff; i++) {
    char a = SPI.transfer(buff[i]);
    // recvBuff[i] = a;
    Serial.print(a);
  }
  Serial.print("\n");
  // recvBuff[sizeof buff] = '\0';
  // Serial.println(recvBuff);
  delay(1000);  
}