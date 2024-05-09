#include <LiquidCrystal.h>

//#define _LCD_TYPE 2
//#include <font_LCD_1602_RUS.h>
///#include <LCD_1602_RUS_ALL.h>

byte v_char[] = {
  B00000,
  B00000,
  B00000,
  B11100,
  B10010,
  B11100,
  B10010,
  B11100
};
byte d_char[] = {
  B00000,
  B00000,
  B00000,
  B00110,
  B01010,
  B01010,
  B01110,
  B10001
};

byte D_char[] = {
  B00000,
  B00000,
  B00110,
  B01010,
  B01010,
  B01010,
  B01110,
  B10001
};

byte ch_char []= {
  B00000,
  B00000,
  B11001,
  B01001,
  B01111,
  B00001,
  B00001,
  B00001
};

byte n_char[] = {
  B00000,
  B00000,
  B00000,
  B10010,
  B10010,
  B11110,
  B10010,
  B10010
};
byte i_char[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10010,
  B10110,
  B11010,
  B10010
};
byte l_char[] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B01010,
  B10001,
  B10001,
  B10001
};
// Так как используемый дисплей не имеет русских символов нужен набор кастомных символов
LiquidCrystal lcd(13, 12, 11,10, 9, 8 );
//String nameline = "Савко Александр Дмитриевич";
//String nameline = "Ca\x07ko";
String nameline=String("Ca\x07ko A\x06")+String("ekca\x04\x01p \x02m\x05tp\x05")+String("e\x07\x05\x03");
int index = 0;
int cutleng=nameline.length();
void setup()
{
    lcd.createChar(7, v_char);
    lcd.createChar(1, d_char);
    lcd.createChar(2, D_char);
    lcd.createChar(3, ch_char);
    lcd.createChar(4, n_char);
    lcd.createChar(5, i_char);
    lcd.createChar(6, l_char);
    

 // начинаем работу с экраном. Сообщаем объекту количество
 // строк и столбцов. Опять же, вызывать pinMode не требуется:
 // функция begin сделает всё за нас
 lcd.begin(16, 2);
 // печатаем сообщение на первой строке

}
void loop()
{
if(index > cutleng){index =0;}
 lcd.print(nameline.substring(index,index+15));
 delay(1000);
 index++;
lcd.clear();
}

