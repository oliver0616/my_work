int SensorPin1=30;          //declares pin 9 for input
int SensorPin2=10;       //declares pin 10 for input
int SensorPin3=11;       //declares pin 11 for input
int SensorPin4=12;
int SensorPin5=13;

int outPin=6;             //declares pin 6 for output
int outPin2=7;            //declares pin 7 for output
int outPin3=8;            //declares pin 8 for output
int outPin4=5;
int outPin5=4;

int SensorValue1=LOW;      //pin9 begins off
int SensorValue2=LOW;    //pin10 begins off
int SensorValue3=LOW;    //pin 11 beings off
int SensorValue4=LOW;
int SensorValue5=LOW;

int outValue1=LOW;
int outValue2=LOW;
int outValue3=LOW; 
int outValue4=LOW;
int outValue5=LOW;

void setup()
{
    pinMode(6,OUTPUT);    
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    pinMode(30,OUTPUT);      // sends value out through IR pin 9
    pinMode(10,OUTPUT);     // sends value out through IR pin 10
    pinMode(11,OUTPUT);     // sends value out through IR pin 11
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);

    digitalWrite(30,HIGH);   // sets value on for IR pin 9
    digitalWrite(10,HIGH);  // sets value on for IR pin 10
    digitalWrite(11,HIGH);  // sets value on for IR pin 11
    digitalWrite(12,HIGH);
    digitalWrite(13,HIGH);
    
    delayMicroseconds(10);

    pinMode(30,INPUT);       // recieves value from sensor on pin 9
    long time1 = micros();
    while (digitalRead(SensorPin1) == HIGH && micros() - time1 < 3000);
    int diff1 = micros() - time1;
    SensorValue1=diff1;  
    delay(5);

    pinMode(10,INPUT);      // recieves value from sensor on pin 10
    long time2 = micros();  
    while (digitalRead(SensorPin2) == HIGH && micros() - time2 < 3000);
    int diff2 = micros() - time2;
    SensorValue2=diff2;
    delay(5); 

    pinMode(11,INPUT);      // recieves value from sensor on pin 11
    long time3 = micros();
    while (digitalRead(SensorPin3) == HIGH && micros() - time3 < 3000);
    int diff3 = micros() - time3;
    SensorValue3=diff3; 
    delay(5);

    pinMode(12,INPUT);
    long time4 = micros();
    while(digitalRead(SensorPin4) == HIGH && micros() - time4 < 3000);
    int diff4 = micros() - time4;
    SensorValue4 = diff4;
    delay(5);

    pinMode(13,INPUT);
    long time5 = micros();
    while(digitalRead(SensorPin5) == HIGH && micros() - time5 < 3000);
    int diff5 = micros() - time5;
    SensorValue5 = diff5;
    delay(5);
    
    if(SensorValue1 <1600)
    {
      outValue1 = HIGH;
      digitalWrite(6, HIGH);              //should send 5V through pin 6 if sensor is above tape
    }
    else
    {
      outValue1 =LOW;
      digitalWrite(6, LOW);               //should send 0V through pin 6 if sensor is not above tape
    }

    if(SensorValue2 <1600)
    {
      outValue2 = HIGH;
          digitalWrite(7, HIGH);          //should send 5V through pin 7 if sensor is above tape
        }
    else
    {
      outValue2 = LOW;
      digitalWrite(7, LOW);               //should send 0V through pin 7 if sensor is not above tape
    }

    if(SensorValue3 <1600)
    {
      outValue3 = HIGH;
          digitalWrite(8, HIGH);          //should send 5V through pin 8 if sensor is above tape
    }
    else
    {
      outValue3 = LOW;
      digitalWrite(8, LOW);               //should send 0V through pin 8 if sensor is not above tape
    }

    if(SensorValue4 <1600)
    {
      outValue4 = HIGH;
      digitalWrite(5, HIGH);
    }
    else
    {
      outValue4 = LOW;
      digitalWrite(5,LOW);
    }

    if(SensorValue5 <1600)
    {
      outValue5 = HIGH;
      digitalWrite(4, HIGH);
    }
    else
    {
      outValue5 = LOW;
      digitalWrite(4,LOW);
    }
   
   if(Serial.available()>0);
    {
        Serial.print("First:");
        Serial.println(SensorValue1);     //prints pin 9 value to serial monitor
        /*Serial.print("Second:");
        Serial.println(SensorValue2);   //prints pin 10 value to serial monitor
        Serial.print("Third:");
        Serial.println(SensorValue3);   //prints pin 11 value to serial monitor
        Serial.print("Fourth:");
        Serial.println(SensorValue4); 
        Serial.print("Fifth:");
        Serial.println(SensorValue5);*/
    }

    delay(200);                           //checks every 1/2 second
}
