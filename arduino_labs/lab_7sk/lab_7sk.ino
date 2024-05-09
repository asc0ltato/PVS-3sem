#define red_led 9
#define yellow_led 10
#define green_led 11
byte state = 1;
byte cnt;
void setup() {
  pinMode(red_led,HIGH);
  pinMode(yellow_led,HIGH);
  pinMode(green_led,HIGH);
  Serial.begin(9600);
}
void statemachine()
{
switch(state)
{
  case 1:
  digitalWrite(red_led,HIGH);
  digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,LOW);
  state++;
  break;

  case 2:
  digitalWrite(red_led,HIGH);
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,LOW);
  state++;
  break;

  case 3:
  digitalWrite(red_led,LOW);
  digitalWrite(yellow_led,LOW);
  digitalWrite(green_led,HIGH);
  state++;
  break;

  case 4:
  digitalWrite(red_led,LOW);
  digitalWrite(yellow_led,HIGH);
  digitalWrite(green_led,LOW);
  state=1;
  break;
}  

}
void loop() {
 cnt++;
 if(cnt == 100)
 {
 cnt =0;
 statemachine(); 
 }
 delay(10);
 //Serial.println(state);
}
