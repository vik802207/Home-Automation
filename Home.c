#include <Keypad.h>
#include <Servo.h>

// Set up keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Set up servo
Servo lockServo;
const int servoPin = 10;
const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;
const int tmp36Pin = A1;
const int gasSensorPin = A2;
const int buzzerPin = 13;

// Temperature threshold (in Celsius) to simulate turning on the AC
const int tempThreshold = 30; // Adjust as needed
// Gas threshold (analog value from 0 to 1023)
const int gasThreshold = 150;

// Correct password
String password = "1234";
String input = "";

void setup() {
  Serial.begin(9600);
  lockServo.attach(servoPin);
  lockServo.write(0); // Lock the safe at the start
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
   pinMode(buzzerPin, OUTPUT);
  setLEDColor(0, 0, 255); // Blue: Safe is locked
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.println(key);
    
    if (key == '#') {
      if (input == password) {
        Serial.println("Correct Password!");
        setLEDColor(0, 255, 0); // Green: Correct
        lockServo.write(90); // Unlock the safe
        delay(5000); // Keep unlocked for 5 seconds
        lockServo.write(0); // Lock the safe again
        setLEDColor(0, 0, 255); // Blue: Safe is locked
      } else {
        Serial.println("Incorrect Password!");
        setLEDColor(255, 0, 0); // Red: Incorrect
        delay(1000);
        setLEDColor(0, 0, 255); // Blue: Safe is locked
      }
      input = ""; // Clear input
    } else if (key == '*') {
      input = ""; // Clear input if '*' is pressed
    } else {
      input += key; // Append the key to the input string
    }
  }
    int tempValue = analogRead(tmp36Pin);
  float voltage = tempValue * (5.0 / 1023.0); // Convert to voltage
  float temperature = (voltage - 0.5) * 100; // Convert to Celsius
  //Serial.print("Temperature: ");
  //Serial.println(temperature);
   if (temperature > tempThreshold) {
    Serial.println("Temperature too high! Turning on AC (simulated).");
    // Add your AC control code here, if needed
  }
   int gasValue = analogRead(gasSensorPin);
  //Serial.print("Gas Level: ");
  //Serial.println(gasValue);

  if (gasValue > gasThreshold) {
    //Serial.println("Gas detected! Triggering alarm.");
   digitalWrite(buzzerPin, LOW);
  } else {
     tone(buzzerPin,220,100); // Turn on the buzzer
     // Turn off the buzzer
  }
  
}

// Function to set the RGB LED color
void setLEDColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
