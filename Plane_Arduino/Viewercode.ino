#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX (choose any available pins)

void setup() {
    Serial.begin(115200); // Initialize serial communication over USB
    mySerial.begin(115200); // Initialize SoftwareSerial
}

void loop() {
    // Read data from USB (Serial Monitor)
    // byte pag = 0;
    // int temp = 0;
    // if (mySerial.available()) {
    //   byte receivedBytes[2];
    //   receivedBytes[0] = mySerial.read();
    //   receivedBytes[1] = mySerial.read();

    //   temp = receivedBytes[1] << 8 | receivedBytes[0];
    //     Serial.print("Received");
    //     Serial.println(temp);
    // }
    static String inputString = "";  // A string to hold incoming data
    static boolean stringComplete = false;  // Whether the string is complete
    while (mySerial.available()) {
      //Serial.print("Hello");
        char inChar = (char)mySerial.read();
        if (inChar == '\n') {
          
          stringComplete = true;
        }
        else{
          inputString += inChar;
        }
    }
    if (stringComplete) {
        int value = inputString.toInt();
        if (value >=1000 && value <= 9999){
          //int value = inputString.toInt();  // Convert the received string to an integer
          Serial.println(value);
            // Print only the integer value
        }
        inputString = "";  // Clear the string
        stringComplete = false;  // Reset the flag
    }
    // if (Serial.available()) {
    //     char receivedChar = Serial.read();
    //     // Process receivedChar as needed
    //     // ...
    //     // Send data to another Arduino via SoftwareSerial
    //     Serial.println(receivedChar);
    // }
    //delay(100);
  mySerial.write(1);
   }

