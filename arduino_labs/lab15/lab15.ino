#include <LiquidCrystal.h>

#define analogPin      0          // analog pin for measuring capacitor voltage
#define chargePin      13         // pin to charge the capacitor - connected to one end of the charging resistor
#define dischargePin   11         // pin to discharge the capacitor
#define resistorValue  10000.0F   // change this to whatever resistor value you are using
                                  // F formatter tells compiler it's a floating point value


LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)

unsigned long startTime;
unsigned long elapsedTime;
float microFarads;                // floating point variable to preserve precision, make calculations
float nanoFarads;


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);             // initialize serial transmission for debugging

  pinMode(chargePin, OUTPUT);     // set chargePin to output
  digitalWrite(chargePin, LOW);
}


void loop() {

  digitalWrite(chargePin, HIGH);  // set chargePin HIGH and capacitor charging

  startTime = millis();

  while(analogRead(analogPin) < 648) {}      // 647 is 63.2% of 1023, which corresponds to full-scale voltage

  elapsedTime = millis() - startTime;
  // convert milliseconds to seconds ( 10^-3 ) and Farads to microFarads ( 10^6 ),  net 10^3 (1000)
  microFarads = ((float)elapsedTime / resistorValue) * 1000;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(elapsedTime);       // print the value
  Serial.print(elapsedTime);
  lcd.print(" ms");         // print units and carriage return
  Serial.print(" ms | ");
  lcd.setCursor(0, 1);
  if (microFarads > 1){
    lcd.print((long)microFarads);       // print the value
    Serial.print((long)microFarads);
    lcd.print(" mF");         // print units and carriage return
    Serial.println(" mF");
  }
  else
  {
    // if value is smaller than one microFarad, convert to nanoFarads (10^-9 Farad).
    // This is  a workaround because Serial.print will not print floats
    nanoFarads = microFarads * 1000.0;      // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
    lcd.print((long)nanoFarads);         // print the value
    Serial.print((long)nanoFarads);
    lcd.print(" nF");          // print units and carriage return
    Serial.println(" nF");
  }

  /* dicharge the capacitor  */
  digitalWrite(chargePin, LOW);             // set charge pin to  LOW
  pinMode(dischargePin, OUTPUT);            // set discharge pin to output
  digitalWrite(dischargePin, LOW);          // set discharge pin LOW
  while(analogRead(analogPin) > 0) {}       // wait until capacitor is completely discharged
  pinMode(dischargePin, INPUT);            // set discharge pin back to input
}