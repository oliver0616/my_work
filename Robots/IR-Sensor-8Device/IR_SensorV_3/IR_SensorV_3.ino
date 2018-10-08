int SensorPin=9;          //declares pin 9 for input
int SensorPin_3=10;       //declares pin 10 for input
int SensorPin_4=11;       //declares pin 11 for input
int outPin=6;             //declares pin 6 for output
int outPin2=7;            //declares pin 7 for output
int outPin3=8;            //declares pin 8 for output

int SensorValue=LOW;      //pin9 begins off
int SensorValue_3=LOW;    //pin10 begins off
int SensorValue_4=LOW;    //pin 11 beings off
int outValue=LOW;
int outValue2=LOW;
int outValue3=LOW; 

void setup()
{
    pinMode(6,OUTPUT);    
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    pinMode(9,OUTPUT);      // sends value out through IR pin 9
    pinMode(10,OUTPUT);     // sends value out through IR pin 10
    pinMode(11,OUTPUT);     // sends value out through IR pin 11

    digitalWrite(9,HIGH);   // sets value on for IR pin 9
    digitalWrite(10,HIGH);  // sets value on for IR pin 10
    digitalWrite(11,HIGH);  // sets value on for IR pin 11
    
    delayMicroseconds(10);

    pinMode(9,INPUT);       // recieves value from sensor on pin 9
    long time_2 = micros();
    while (digitalRead(SensorPin) == HIGH && micros() - time_2 < 3000);
    int diff = micros() - time_2;
    SensorValue=diff;  
    delay(5);

    pinMode(10,INPUT);      // recieves value from sensor on pin 10
    long time_3 = micros();  
    while (digitalRead(SensorPin_3) == HIGH && micros() - time_3 < 3000);
    int diff_3 = micros() - time_3;
    SensorValue_3=diff_3;
    delay(5); 

    pinMode(11,INPUT);      // recieves value from sensor on pin 11
    long time_4 = micros();
    while (digitalRead(SensorPin_4) == HIGH && micros() - time_4 < 3000);
    int diff_4 = micros() - time_4;
    SensorValue_4=diff_4; 
    delay(5);
    
    if(SensorValue <1600)
    {
      outValue = HIGH;
      digitalWrite(6, HIGH);              //should send 5V through pin 6 if sensor is above tape
    }
    else
    {
      outValue =LOW;
      digitalWrite(6, LOW);               //should send 0V through pin 6 if sensor is not above tape
    }

    if(SensorValue_3 <1600)
    {
      outValue2 = HIGH;
          digitalWrite(7, HIGH);          //should send 5V through pin 7 if sensor is above tape
        }
    else
    {
      outValue2 = LOW;
      digitalWrite(7, LOW);               //should send 0V through pin 7 if sensor is not above tape
    }

    if(SensorValue_4 <1600)
    {
      outValue3 = HIGH;
          digitalWrite(8, HIGH);          //should send 5V through pin 8 if sensor is above tape
        }
    else
    {
      outValue3 = LOW;
      digitalWrite(8, LOW);               //should send 0V through pin 8 if sensor is not above tape
    }
   
   if(Serial.available()>0);
    {
        Serial.print("First:");
        Serial.println(SensorValue);     //prints pin 9 value to serial monitor
        Serial.print("Second:");
        Serial.println(SensorValue_3);   //prints pin 10 value to serial monitor
        Serial.print("Third:");
        Serial.println(SensorValue_4);   //prints pin 11 value to serial monitor
    }

    delay(200);                           //checks every 1/2 second
}
