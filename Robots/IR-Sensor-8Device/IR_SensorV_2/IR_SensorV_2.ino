int SensorPin=2;
int SensorPin_3=3;
int outPin=6;
int outPin2=7;

int SensorValue=LOW;
int SensorValue_3=LOW;
int outValue=LOW;
int outValue2=LOW;

void setup()
{
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    pinMode(2,OUTPUT); 
    pinMode(3,OUTPUT);

    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);

    delayMicroseconds(10);

    pinMode(2,INPUT);
    pinMode(3,INPUT);

 
    long time_3 = micros();  
    while (digitalRead(SensorPin_3) == HIGH && micros() - time_3 < 3000);
    int diff_3 = micros() - time_3;
    SensorValue_3=diff_3;

    long time_2 = micros();
    while (digitalRead(SensorPin) == HIGH && micros() - time_2 < 3000);
    int diff = micros() - time_2;
    SensorValue=diff;   
    
    if(SensorValue <1200)
    {
      outValue = HIGH;
    }
    else
    {
      outValue =LOW;
    }

    if(SensorValue_3 <1200)
    {
      outValue2 = HIGH;
    }
    else
    {
      outValue2 = LOW;
    }
   
    if(Serial.available()>0);
    {
        Serial.println(SensorValue);
        Serial.println(SensorValue_3);

        
    }

    delay(500);
}
