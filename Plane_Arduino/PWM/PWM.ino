/*
Written By Aaron James
*/
#include <Servo.h>
#include <Wire.h>
#include <SoftwareSerial.h>
//#include <Adafruit_PWMServoDriver.h>

unsigned long Rudder;
unsigned long Elevator;
unsigned long Right;
unsigned long Left;
unsigned long Engine;
unsigned long Flaps;
int toggle;

Servo Rudder_servo;
Servo Elevator_servo;
Servo Right_servo;
Servo Left_servo;
Servo Engine_servo;
Servo Flaps_;

void setup() {
// put your setup code here, to run once:

//PWM pins are 3,5,6,9,10 and 11 for the NANO
//Network Address for lora transmitter and recievers [3]

//Inputs should be on pins 2 4 7 8 12
//Output should be on pins 3 5 6 9 10
//11 is a spare pin for either output/input

Serial.begin(115200);

Rudder_servo.attach(3);
Elevator_servo.attach(5);
Right_servo.attach(6);
Left_servo.attach(9);
Engine_servo.attach(10);


pinMode (2, INPUT);   //Rudder Input 
pinMode (4, INPUT);   //Elevator Input
pinMode (7, INPUT);   //Aileron Right Input
pinMode (8, INPUT);   //Aileron Left Input
pinMode (12, INPUT);  //Engine Input
pinMode (11, INPUT);  //Flaps Input

pinMode (3, OUTPUT);  //Rudder Output
pinMode (5, OUTPUT);  //Elevator Output
pinMode (6, OUTPUT);  //Aileron Right Output
pinMode (9, OUTPUT);  //Aileron Left Output
pinMode (10, OUTPUT); //Engine Output

}

void loop() {

Flaps = pulseIn(11, HIGH);
//Serial.println(Flaps);
if (Flaps > 1000 && Flaps <1200) {  //Data Collection
  toggle = 0;
  Serial.print(toggle);
}
else if (Flaps >1400 && Flaps <1600) {  //Manual
  toggle = 1;
  Serial.print(toggle);
}

else if (Flaps >1750 && Flaps <2000) {  //Automatic
  toggle = 2;
  Serial.print(toggle);
}

//If toggle = 0, it already gets printed


 if (toggle == 1) { //Manual

 Rudder=pulseIn(2, HIGH);
 Rudder_servo.writeMicroseconds(Rudder);
 Serial.println(Rudder);

 
 Elevator=pulseIn(4, HIGH);
 Elevator_servo.writeMicroseconds(Elevator);
 Serial.println(Elevator);


 Right=pulseIn(7, HIGH);
 Right_servo.writeMicroseconds(Right);
 Serial.println(Right);


 Left = pulseIn(8, HIGH);
 Left_servo.writeMicroseconds(Left);
 Serial.println(Left);


 Engine = pulseIn(12, HIGH);
 Engine_servo.writeMicroseconds(Engine);
 Serial.println(Engine);
}

if (toggle == 2) {  //Autonomous
static String inputString = "";  // A string to hold incoming data
    static boolean stringComplete = false;  // Whether the string is complete
    while (Serial.available()) {
      //Serial.print("Hello");
        char inChar = (char)Serial.read();
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
          Rudder_servo.writeMicroseconds(value);
            // Print only the integer value
        }
        inputString = "";  // Clear the string
        stringComplete = false;  // Reset the flag
    }
}



}