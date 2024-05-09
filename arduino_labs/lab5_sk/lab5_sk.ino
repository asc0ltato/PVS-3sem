#define LED_RED_PIN 9
#define LED_GREEN_PIN 10
#define LED_BLUE_PIN 3
// для работы с текстом существуют объекты-строки (англ. string)
String message;
byte signals[3],index = 0;
bool is_text=false;//dotmod=true;

void setup()
{
 pinMode(LED_RED_PIN, OUTPUT);
 Serial.begin(9600);
}
void power_on()
{
analogWrite(LED_RED_PIN, 255);
analogWrite(LED_GREEN_PIN, 255);
analogWrite(LED_BLUE_PIN, 255);  
}
void power_off()
{
analogWrite(LED_RED_PIN, 0);
analogWrite(LED_GREEN_PIN, 0);
analogWrite(LED_BLUE_PIN, 0);  
}
void writesignal(byte signal_arr[3])
{
if((!is_text))
{
analogWrite(LED_RED_PIN, signal_arr[0]);
analogWrite(LED_GREEN_PIN, signal_arr[1]);
analogWrite(LED_BLUE_PIN, signal_arr[2]); 
}
else{Serial.println("out of range");} 
}
void separate(bool text_trig)
{ bool islast=false;
  if(!text_trig && (0<=message.toInt()&&message.toInt()<=255)){
  signals[index++]=message.toInt();
  message = "";}
  else{is_text=true;}
  if(is_text&& islast){Serial.println("out of range");}
}
//void clear_sign(){for(byte i =0;i<3;i++){signals[i]=0;}}//clear_sign();
void loop()
{
 //передаваемые  с компьютера данные поставляются байт за
 // байтом, в виде отдельных символов (англ. character). Нам
 // нужно последовательно их обрабатывать пока (англ. while)
 // в порту доступны (англ. available) новые данные
 while (Serial.available()) {
 char incomingChar = Serial.read();
 
 if (incomingChar >= 48 && incomingChar <= 57) { message += incomingChar;}
 else if(incomingChar == ',' && index<3) 
 {
  //dotmod=false;
  separate(is_text);
  }
  //else{Serial.println("out of range");}
 
 else if (incomingChar == '\n') {
message.toLowerCase();

if((!is_text)){separate(is_text);writesignal(signals);}
else if(message=="on"&&!index){power_on();}
else if(message=="off"&&!index){power_off();}
else{Serial.println("out of range");}
//if(index){Serial.println("out of range");}
 
 message = "";is_text=false;index=0;
 // обнуляем накопленное сообщение, чтобы начать всё заново
 }
 else{message+=incomingChar;is_text=true;}
 }
 
}

