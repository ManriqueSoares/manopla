 
//Prateek
//www.prateks.in
//https://www.youtube.com/c/JustDoElectronics

#include <ESP32Servo.h>
#include <ezButton.h>
#define BUTTON_PIN 26 // ESP32 pin GIOP33 connected to button's pin
#define SERVO_PIN  21 // ESP32 pin GIOP26 connected to servo motor's pin
ezButton button(BUTTON_PIN); 
Servo servo;                 
int angle = 0; 

void setup() {
  Serial.begin(9600);         
  button.setDebounceTime(50); 
  servo.attach(SERVO_PIN);   

  servo.write(angle);
}

void loop() {
  button.loop(); 

  if (button.isPressed()) {
    if (angle == 0)
      angle = 180;
    else if (angle == 180)
      angle = 0;
    Serial.print("The button is pressed => rotate servo to ");
    Serial.print(angle);
    Serial.println("°");
    servo.write(angle);
  }
}

