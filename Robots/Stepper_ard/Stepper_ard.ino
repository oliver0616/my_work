#include <Stepper.h>
 
#define STEPS 200

Stepper stepper(STEPS, 4,5,6,7);

void setup() {
  pinMode(2, INPUT); 
  pinMode(3, INPUT);

  stepper.setSpeed(100);

  Serial.begin(9600); // Pour a bowl of Serial

  Serial.println("Stepper!");  
}

void loop() {
  //Serial.println(digitalRead(2)==HIGH);    
  //Serial.println(digitalRead(3)==HIGH); 
  Serial.println(digitalRead(4)==HIGH); 
  Serial.println(digitalRead(5)==HIGH);
  Serial.println(digitalRead(6)==HIGH);
  Serial.println(digitalRead(7)==HIGH);
  if(digitalRead(2)==HIGH)
  {
    if(digitalRead(3)==HIGH)
      stepper.step(-1);
    else
      stepper.step(1);
  }
  else
  {
    stepper.step(0);
  }
}








 
