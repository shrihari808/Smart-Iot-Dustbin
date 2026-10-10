#include <Servo.h>

Servo myServo; // Create a Servo object

unsigned long startTime; // Variable to store the time when the program started
const unsigned long timeout = 25000; // Timeout limit in milliseconds (25 seconds)

void setup() {
  Serial.begin(9600);         // Start serial communication at 9600 baud
  myServo.attach(9);          // Attach servo on pin 9
  myServo.write(0);           // Set initial position to 0 degrees
  
  startTime = millis(); // Record the start time
}

void loop() {
  // Check if the timeout has exceeded 25 seconds
  if (millis() - startTime > timeout) {
    Serial.println("Timeout exceeded 25 seconds. Exiting...");
    return; // Exit the loop if 25 seconds have passed
  }

  if (Serial.available() > 0) {   // Check if data is available on the serial port
    char receivedChar = Serial.read(); // Read the incoming byte

    if (receivedChar == '1') {
      myServo.write(90);          // Rotate to 90 degrees for recyclable item
      delay(2000);                // Hold for 2 seconds
      myServo.write(0);           // Return to original position (0 degrees)
      delay(1000);                // Wait for 1 second to complete the rotation
      Serial.println("Rotated Right and Returned");
    } 
    else if (receivedChar == '0') {
      myServo.write(0);           // Rotate to 0 degrees for organic item
      delay(2000);                // Hold for 2 seconds
      myServo.write(90);          // Return to original position (90 degrees)
      delay(1000);                // Wait for 1 second to complete the rotation
      Serial.println("Rotated Left and Returned");
    }
  }
}
