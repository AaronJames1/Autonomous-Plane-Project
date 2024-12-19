#include <SoftwareSerial.h>

// RX, TX

SoftwareSerial mySerial(10, 11); // Create software serial object. Pin 10 = RX, Pin 11 = TX 
//Fixed (RX,TX):(10,11)
//Select NL and CR when talking to radio
//******* Use Old Bootloader for Arduino Clones
//Ground Address:1
//Air Address:2
//AT+SEND=<Address>,<Payload Length>,<Data>
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // Start software serial communication at baud rate of 115200
  mySerial.begin(9600);
}

void loop() {
  // If data is available on the software serial port, print it to the serial monitor
 if (mySerial.available()) {
    Serial.write(mySerial.read());
    
  }
  
  // If data is available on the serial monitor, send it via software serial port
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }

}