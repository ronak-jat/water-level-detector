#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <math.h>

// Set the I2C address of the LCD (change if necessary)
LiquidCrystal_I2C lcd(0x27, 16, 2); // Try 0x3F if 0x27 doesn’t work

// Ultrasonic sensor pin definitions
const int trigPin = 8, echoPin = 9;

// Tank depth configuration
const float tankEmptyDepth = 8.6; // Distance from sensor to empty tank bottom (in cm)
const float tankFullDepth = 1.2;  // Distance from sensor to full tank level (in cm)

// Tank dimensions (in cm)
const float tankHeight = 7.4;   // Height of the tank
const float tankLength = 22.0;  // Length of the tank
const float tankBreadth = 11.5; // Breadth of the tank

// Variables for water level measurement
float currentLevel = 0;
float lastLevel = 0;
unsigned long timeHigh; // Echo response time

void setup() {
  // Initialize I2C communication with LCD
  lcd.init();
  lcd.backlight();  // Turn on LCD backlight

  // Set up ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW); // Ensure trigger starts low

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print(" Water Level Meter ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Trigger ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time for the echo response
  timeHigh = pulseIn(echoPin, HIGH);

  if (timeHigh == 0) {
    // If no response, show error message
    showError();
  } else {
    // Convert time to distance (in cm)
    currentLevel = timeHigh / 58.0;

    // Ensure level stays within the defined range
    if (currentLevel > tankEmptyDepth) {
      currentLevel = tankEmptyDepth;
    } else if (currentLevel < tankFullDepth) {
      currentLevel = tankFullDepth;
    }

    // Only update display if level has changed
    if (currentLevel != lastLevel) {
      lastLevel = currentLevel;
      showCurrentLevel();
    }
  }

  delay(2000); // Delay before next measurement
}

void showError() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" ERROR: Timeout ");
}

void showCurrentLevel() {
  // Calculate water percentage
  float ratio = 1 - (currentLevel - tankFullDepth) / (tankEmptyDepth - tankFullDepth);
  int percentLevel = round(abs(ratio) * 100.0) ;

  // Calculate water height in the tank
  float waterHeight = tankHeight * ratio;

  // Calculate water volume (in cm³)
  float waterVolume = waterHeight * tankLength * tankBreadth;

  // Display water level percentage
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(percentLevel);
  lcd.print("%");

  // Display water volume
  lcd.setCursor(0, 1);
  lcd.print("Vol: ");
  lcd.print(waterVolume, 1); // Display volume with 1 decimal place
  lcd.print(" cm3");

  // Display progress bar (10 characters max)
  int bars = (percentLevel * 10) / 100;
  lcd.setCursor(10, 1);
  for (int i = 0; i < bars; i++) {
    lcd.write(255); // Full block character
  }
}
