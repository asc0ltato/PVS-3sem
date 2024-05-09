#define LED 13
#define LDR 0
#define Poti 1
short cnt = 0;

void setup() 
{
  pinMode(LED,OUTPUT);
}

void loop() 
{
  
  if(analogRead(LDR)>analogRead(Poti))cnt = 0;
  if(analogRead(LDR)<analogRead(Poti))cnt++;

  if(cnt>300)
  {
    digitalWrite(LED,HIGH);
    do{
      delay(5000);
    }while(analogRead(LDR)<analogRead(Poti));
    cnt = 0;
  }
  digitalWrite(LED,LOW);
  delay(10);
}