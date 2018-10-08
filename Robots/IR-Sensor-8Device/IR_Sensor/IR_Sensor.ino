int SensorPin=9;
int SensorValue=LOW;

void setup()
{
    pinMode(13,OUTPUT); 
    Serial.begin(9600);
}

void loop()
{

    pinMode(9,OUTPUT);

    digitalWrite(9,HIGH);

    delayMicroseconds(10);

    pinMode(9,INPUT);

    long time = micros();

    //while (digitalRead(SensorPin) == HIGH && micros() - time < 3000);

    int diff = micros() - time;

    SensorValue=diff;

    if(Serial.available()>0);
    {
        Serial.println(SensorValue); 
    }
    delay(500);
}
