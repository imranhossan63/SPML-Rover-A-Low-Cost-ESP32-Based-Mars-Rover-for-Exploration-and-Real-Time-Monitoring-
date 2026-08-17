#include <BluetoothSerial.h>

 // Motor Driver Pins
 #define motor1_pin1 13
 #define motor1_pin2 12
 #define motor2_pin1 14
 #define motor2_pin2 27
 #define motor3_pin1 26
 #define motor3_pin2 25
 #define motor4_pin1 33
 #define motor4_pin2 32
 int val;
 BluetoothSerial SerialBT; // BluetoothSerial object
 int motorSpeed = 255;
 void setup() {
 Serial.begin(115200); // Serial Monitor for debugging
 SerialBT.begin("Mars_Rover"); // Bluetooth name
 Serial.println("Bluetooth␣Device␣Started,␣Waiting␣for␣Pairing...");
 
 // Set motor pins as outputs
 pinMode(motor1_pin1, OUTPUT);
 pinMode(motor1_pin2, OUTPUT);
 pinMode(motor2_pin1, OUTPUT);
 pinMode(motor2_pin2, OUTPUT);
 pinMode(motor3_pin1, OUTPUT);

 pinMode(motor3_pin2, OUTPUT);
 pinMode(motor4_pin1, OUTPUT);
 pinMode(motor4_pin2, OUTPUT);
 stopMotors(); // Ensure motors are stopped initially
 }
 void loop() {
 if (SerialBT.available()) { // Check if data is received via Bluetooth
 val = SerialBT.read(); // Read the received command
 stopMotors(); // Initialize with motors stopped
 switch (val) {
 
 case 'F': moveForward(); break;
 case 'B': moveBackward(); break;
 case 'L': turnLeft(); break;
 case 'R': turnRight(); break;
 case 'T': stopMotors(); break;
 default:
 Serial.println("Invalid␣Command"); // Debugging invalid commands
 }}}
 // Helper function to control a single motor’s pins
 void setMotor(int pin1, int pin2, int state1, int state2) {
 digitalWrite(pin1, state1);
 digitalWrite(pin2, state2);
 }
 // Movement functions
 void moveForward() {
  setMotor(motor1_pin1, motor1_pin2, LOW, HIGH);
 setMotor(motor2_pin1, motor2_pin2, LOW, HIGH);
 setMotor(motor3_pin1, motor3_pin2, LOW, HIGH);
 setMotor(motor4_pin1, motor4_pin2, LOW, HIGH);
 }
 void moveBackward() {
 setMotor(motor1_pin1, motor1_pin2, HIGH, LOW);
 setMotor(motor2_pin1, motor2_pin2, HIGH, LOW);
 setMotor(motor3_pin1, motor3_pin2, HIGH, LOW);
 setMotor(motor4_pin1, motor4_pin2, HIGH, LOW);
 }
 void turnLeft() {
 setMotor(motor1_pin1, motor1_pin2, LOW, LOW);
 setMotor(motor2_pin1, motor2_pin2, HIGH, LOW);
 setMotor(motor3_pin1, motor3_pin2, LOW, HIGH);
 setMotor(motor4_pin1, motor4_pin2, HIGH, LOW);
 }
 void turnRight() {
 setMotor(motor1_pin1, motor1_pin2, HIGH, LOW);
 setMotor(motor2_pin1, motor2_pin2, LOW, LOW);
 setMotor(motor3_pin1, motor3_pin2, HIGH, LOW);
 setMotor(motor4_pin1, motor4_pin2, LOW, HIGH);
 }
 void stopMotors() {
 setMotor(motor1_pin1, motor1_pin2, LOW, LOW);
 setMotor(motor2_pin1, motor2_pin2, LOW, LOW);
 setMotor(motor3_pin1, motor3_pin2, LOW, LOW);
 setMotor(motor4_pin1, motor4_pin2, LOW, LOW);
 }
