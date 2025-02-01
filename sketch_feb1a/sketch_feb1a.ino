// init prototype
#include <Servo.h>

Servo myservo; // Object to control the servo

const int buttonPin = 7; // Button pin
int buttonState = 0; // Current state of the button
int lastButtonState = 0; // Last state of the button
int servoPosition = 0; // Servo position (0 or 180)
bool moving = false; // Flag to avoid multiple readings on the same click

void setup() {
myservo.attach(9); // Servo connected to pin 9
pinMode(buttonPin, INPUT_PULLUP); // Configure the button with internal pull-up resistor
}
void loop() {
buttonState = digitalRead(buttonPin);

// Check if the button was pressed (change from HIGH to LOW)
if (buttonState == LOW && lastButtonState == HIGH && !moving) {
moving = true; // Indicates that the servo is moving

if (servoPosition == 0) {
moveServo(180); // Move to 180°
servoPosition = 180;
} else {
moveServo(0); // Return to 0°
servoPosition = 0;
}

delay(300); // Small delay to avoid multiple readings
moving = false;
}

lastButtonState = buttonState; // Update the button state
}

// Function to move the servo smoothly
void moveServo(int targetPosition) {
int step = (targetPosition > servoPosition) ? 1 : -1;

for (int pos = servoPosition; pos != targetPosition; pos += step) {
myservo.write(pos);
delay(10); // Adjust this value to control the speed of the movement
}
}