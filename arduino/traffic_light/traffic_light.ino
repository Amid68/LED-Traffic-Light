// Project: Basic LED Traffic Light
// Description: This code simulates a basic LED Traffic Light
// Author: Ameed Othman
// Date: 03.09.2024

// Define constants
#define GREEN_PIN 9
#define YELLOW_PIN 10
#define RED_PIN 11
const int GREEN_DELAY = 5000;  
const int YELLOW_DELAY = 1000; 
const int RED_DELAY = 5000;

void setup() {       
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);    
}

void loop() {
  // Start with a red light
  digitalWrite(RED_PIN, HIGH);  
  delay(RED_DELAY);        
  // turn on yellow with red
  digitalWrite(YELLOW_PIN, HIGH);
  delay(YELLOW_DELAY);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW); 
  // turn on green  
  digitalWrite(GREEN_PIN, HIGH);
  delay(GREEN_DELAY);
  digitalWrite(GREEN_PIN, LOW);
  // turn on yellow alone
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  delay(YELLOW_DELAY);
  digitalWrite(YELLOW_PIN, LOW); 
}
