int TriggerPin=2;//where the the ping is created
int EchoPin=A0;// Await the return of the ping, and it`s pulsr stays high untill it the ping sent is caught
float DistenceValue;
int delayeTime=50;

void setup()
{
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);// set serial monitor to 9600 baud rate for use
}

void loop()
{
  //creates a ping to send, to measure distence
  digitalWrite(TriggerPin,LOW);
    delay(delayeTime);
  digitalWrite(TriggerPin,HIGH);
    delay(delayeTime);
  digitalWrite(TriggerPin,LOW);

// pulseIn() measures the how long the high pulse have lasts in time

  DistenceValue=pulseIn(EchoPin,HIGH)/150.;// the value 150.00 is the slope of distence(inch) on pulse travel time, to convert the value from echoPin in milliseconds to a distence in inchs
  delay(250);
  
  Serial.print(DistenceValue);
  Serial.println(" Inch");//print the value of the time in millieseconds that a ping takes to come back
  delay(delayeTime);
}