#include <ezButton.h>

/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers

const int stepPin = 3; 
const int dirPin = 4; 
const int buttonPin = 7;

int buttonState = 0;
int currentState = 0;

ezButton button(buttonPin);

int customDelayMapped, customDelay;
 
void setup() {
  button.setDebounceTime(50);
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if(button.isPressed()){
    buttonState++;
    Serial.print(buttonState);
    Serial.print("\n");
  }

  currentState = buttonState % 2;
  switch(currentState){
    case 0:
      digitalWrite(dirPin, HIGH);
    default:
      digitalWrite(dirPin, LOW);
  }

  customDelayMapped = delay();
 // digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 200; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(customDelayMapped); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(customDelayMapped); 
  }
  Serial.print(String(customDelayMapped) + "\n");
}

int delay(){
  customDelay = analogRead(A0);
  int newCustom = map(customDelay, 0, 1023, 500, 5000);
  return newCustom;
  }