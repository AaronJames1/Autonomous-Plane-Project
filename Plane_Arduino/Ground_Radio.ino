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
  Serial.begin(115200);
  // Start software serial communication at baud rate of 115200
  mySerial.begin(115200);
}

void loop() {
  // If data is available on the software serial port, print it to the serial monitor
      if (Serial.available()){
      String message = Serial.readStringUntil('\n');
      mySerial.print(message + '\n');
    }

 if (mySerial.available()) {
Serial.print(mySerial.read());
 }
    // if (mySerial.read() == "pag") {
    //   Serial.write(1);
    // }
    // else {
    //   Serial.write(0);
    // }
    // }
  
  
  // If data is available on the serial monitor, send it via software serial port
  //if (Serial.available()) {
    //mySerial.write(Serial.read());
  //}
    // char buffer[8];
    // byte byteArray[2];

    // if (Serial.available()) {
    //   String len = Serial.readStringUntil('\n');
    //   int temp = len.toInt();
    //     byteArray[0] = temp & 0xFF;
    //     byteArray[1] = (temp>>8) & 0xFF;
    //     mySerial.write(byteArray, sizeof(byteArray));
    // }

}