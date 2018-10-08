int SensorPin1=5;       //Back Middle
int SensorPin2=6;       //Back Right
int SensorPin3=7;       //Front Right
int SensorPin4=8;       //Right
int SensorPin5=9;       //Front Left
int SensorPin6=10;      //Front Middle
int SensorPin7=11;      //Left
int SensorPin8=12;      //Back Left

int outPin=26;             //declares pin 6 for output
int outPin2=27;            //declares pin 7 for output
int outPin3=28;            //declares pin 8 for output
int outPin4=29;
int outPin5=30;
int outPin6=31;
int outPin7=32;
int outPin8=33;

int SensorValue1=LOW;      //pin9 begins off
int SensorValue2=LOW;    //pin10 begins off
int SensorValue3=LOW;    //pin 11 beings off
int SensorValue4=LOW;
int SensorValue5=LOW;
int SensorValue6=LOW;
int SensorValue7=LOW;
int SensorValue8=LOW;

int outValue1=LOW;
int outValue2=LOW;
int outValue3=LOW; 
int outValue4=LOW;
int outValue5=LOW;
int outValue6=LOW;
int outValue7=LOW;
int outValue8=LOW;

//========================================
//Ping sensors
const int pingPin1 = 24; //first ping
const int pingPin2 = 25; //second ping

int pingOut1 = 19;
int pintOut2 = 35;

long duration, inches,cm;
long duration2, inches2,cm2;
//=========================================
void setup()
{
    pinMode(26,OUTPUT);    
    pinMode(27,OUTPUT);
    pinMode(28,OUTPUT);
    pinMode(29,OUTPUT);
    pinMode(30,OUTPUT);
    pinMode(31,OUTPUT);
    pinMode(32,OUTPUT);
    pinMode(33,OUTPUT);
    pinMode(34,OUTPUT);
    pinMode(35,OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    pinMode(5,OUTPUT);      // sends value out through IR pin 9
    pinMode(6,OUTPUT);     // sends value out through IR pin 10
    pinMode(7,OUTPUT);     // sends value out through IR pin 11
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);

    digitalWrite(5,HIGH);   // sets value on for IR pin 9
    digitalWrite(6,HIGH);  // sets value on for IR pin 10
    digitalWrite(7,HIGH);  // sets value on for IR pin 11
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    
    delayMicroseconds(10);

    pinMode(5,INPUT);       // recieves value from sensor on pin 9
    long time1 = micros();
    while (digitalRead(SensorPin1) == HIGH && micros() - time1 < 3000);
    int diff1 = micros() - time1;
    SensorValue1=diff1;  
    delay(5);

    pinMode(6,INPUT);      // recieves value from sensor on pin 10
    long time2 = micros();  
    while (digitalRead(SensorPin2) == HIGH && micros() - time2 < 3000);
    int diff2 = micros() - time2;
    SensorValue2=diff2;
    delay(5); 

    pinMode(7,INPUT);      // recieves value from sensor on pin 11
    long time3 = micros();
    while (digitalRead(SensorPin3) == HIGH && micros() - time3 < 3000);
    int diff3 = micros() - time3;
    SensorValue3=diff3; 
    delay(5);

    pinMode(8,INPUT);
    long time4 = micros();
    while(digitalRead(SensorPin4) == HIGH && micros() - time4 < 3000);
    int diff4 = micros() - time4;
    SensorValue4 = diff4;
    delay(5);

    pinMode(9,INPUT);
    long time5 = micros();
    while(digitalRead(SensorPin5) == HIGH && micros() - time5 < 3000);
    int diff5 = micros() - time5;
    SensorValue5 = diff5;
    delay(5);

    pinMode(10,INPUT);       
    long time6 = micros();
    while (digitalRead(SensorPin6) == HIGH && micros() - time6 < 3000);
    int diff6 = micros() - time6;
    SensorValue6=diff6;  
    delay(5);
    
    pinMode(11,INPUT);       
    long time7 = micros();
    while (digitalRead(SensorPin7) == HIGH && micros() - time7 < 3000);
    int diff7 = micros() - time7;
    SensorValue7=diff7;  
    delay(5);

    pinMode(12,INPUT);       
    long time8 = micros();
    while (digitalRead(SensorPin8) == HIGH && micros() - time8 < 3000);
    int diff8 = micros() - time8;
    SensorValue8=diff8;  
    delay(5);
    
    if(SensorValue1 <1600)
    {
      outValue1 = HIGH;
      digitalWrite(26, HIGH);              //should send 5V through pin 6 if sensor is above tape
    }
    else
    {
      outValue1 =LOW;
      digitalWrite(26, LOW);               //should send 0V through pin 6 if sensor is not above tape
    }

    if(SensorValue2 <1600)
    {
      outValue2 = HIGH;
          digitalWrite(27, HIGH);          //should send 5V through pin 7 if sensor is above tape
        }
    else
    {
      outValue2 = LOW;
      digitalWrite(27, LOW);               //should send 0V through pin 7 if sensor is not above tape
    }

    if(SensorValue3 <1600)
    {
      outValue3 = HIGH;
          digitalWrite(28, HIGH);          //should send 5V through pin 8 if sensor is above tape
    }
    else
    {
      outValue3 = LOW;
      digitalWrite(28, LOW);               //should send 0V through pin 8 if sensor is not above tape
    }

    if(SensorValue4 <1600)
    {
      outValue4 = HIGH;
      digitalWrite(29, HIGH);
    }
    else
    {
      outValue4 = LOW;
      digitalWrite(29,LOW);
    }

    if(SensorValue5 <1600)
    {
      outValue5 = HIGH;
      digitalWrite(30, HIGH);
    }
    else
    {
      outValue5 = LOW;
      digitalWrite(30,LOW);
    }
    
     if(SensorValue6 <1600)
    {
      outValue6 = HIGH;
      digitalWrite(31, HIGH);
    }
    else
    {
      outValue6 = LOW;
      digitalWrite(31,LOW);
    }

     if(SensorValue7 <1600)
    {
      outValue7 = HIGH;
      digitalWrite(32, HIGH);
    }
    else
    {
      outValue7 = LOW;
      digitalWrite(32,LOW);
    }

    if(SensorValue8 <1600)
    {
      outValue8 = HIGH;
      digitalWrite(33, HIGH);
    }
    else
    {
      outValue8 = LOW;
      digitalWrite(33,LOW);
    }

    if(Serial.available()>0);
    {
        //Serial.print("First:");
        //Serial.println(SensorValue1);     //prints pin 9 value to serial monitor
        Serial.print("Second:");
        Serial.println(SensorValue2);   //prints pin 10 value to serial monitor
        Serial.print("Third:");
        Serial.println(SensorValue3);   //prints pin 11 value to serial monitor
        Serial.print("Fourth:");
        Serial.println(SensorValue4); 
        Serial.print("Fifth:");
        Serial.println(SensorValue5);
        Serial.print("Sixth:");
        Serial.println(SensorValue6);
        Serial.print("Seventh:");
        Serial.println(SensorValue7);
        Serial.print("Eighth:");
        Serial.println(SensorValue8);
    }

    //delay(200);
    delay(1000); 
//============================================================================================================
  //first ping
  pinMode(19, OUTPUT);
  digitalWrite(19, LOW);
  delayMicroseconds(2);
  digitalWrite(19, HIGH);
  delayMicroseconds(5);
  digitalWrite(19, LOW);
  pinMode(19, INPUT);
  duration = pulseIn(19, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  /*Serial.print(inches);
  Serial.print("in(1), ");
  Serial.print(cm);
  Serial.print("cm(1)");
  Serial.println();*/

  delay(100);
 /* // second ping
  

  pinMode(pingPin2, OUTPUT);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin2, LOW);

  pinMode(pingPin2, INPUT);
  duration2 = pulseIn(pingPin2, HIGH);

  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);

  Serial.print(inches2);
  Serial.print("in(2), ");
  Serial.print(cm2);
  Serial.print("cm(2)");
  Serial.println();

  delay(100);  */
//===================================================================================  
                            //checks every 1/2 second
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
