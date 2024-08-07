#include <Keypad.h>

#include <LiquidCrystal_I2C.h>

#define Password_Length 5
#include <Servo.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};


Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);




LiquidCrystal_I2C lcd(0x27, 16, 2);

char Data[Password_Length];
char Master[Password_Length] = "1234";
byte data_count = 0, master_count = 0;
char customKey;
int num = 1;

int LED_GREEN = 12;
int LED_RED = 13;
int BUZZER = 11;

int servoPin=10;
Servo servo1;

void setup()
{
  lcd.init();  /*LCD display initialized*/
  lcd.clear();     /*Clear LCD Display*/
  lcd.backlight();      /*Turn ON LCD Backlight*/
  Serial.begin(9600);


  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
 
  servo1.attach(servoPin);
}

void loop()
{
  if(data_count < Password_Length-1){
    lcd.setCursor(0,0);   /*Set cursor to Row 1*/
    lcd.print("Enter Password"); /*print text on LCD*/
    customKey = customKeypad.getKey();
     if (customKey){
    Data[data_count] = customKey;
    lcd.setCursor(data_count,1);
    lcd.print(Data[data_count]);
    data_count++;
    }
  }

 
  if(data_count == Password_Length-1){
    lcd.clear();

    if(!strcmp(Data, Master)){
     
      lcd.print("CORRECT");
      digitalWrite(12, HIGH);
      tone(BUZZER, 100, 1000);
      delay(2000);
      servo1.write(0);
   delay(5000);
      servo1.write(90);
      delay(5000);
    }
    else{
      lcd.print("WRONG");
      digitalWrite(13, HIGH);
      tone(BUZZER, 100);
      delay(100);
      noTone(BUZZER);
      tone(BUZZER, 220);  
      delay(200);
      num++;
      data_count = 0;
      delay(1000);
      if(num == 4){
        lcd.clear();
        lcd.print("3x spatne");
        delay(2000);
        lcd.clear();
        lcd.print("Blokuji");
        delay(2000);
        lcd.noDisplay();
      }
      digitalWrite(10, LOW);
    }
 
  }

}


master 01
void setup()

{

pinMode(2,INPUT_PULLUP ); // initialize the pushbutton pin as an input

Serial.begin(9600); // start serial for output

}

void loop()

{

  if(digitalRead(2) == LOW){
  Serial.write(1);
  }else{
  Serial.write(0);
  }
 
delay(100);
}

slave 


void setup()

{
Serial.begin(9600);
  pinMode(9, OUTPUT);

}


void loop()

{

  if(Serial.available() > 0){
  int val = Serial.read();
   
    if(val == 0){
    digitalWrite(9,LOW);
    }else{
    digitalWrite(9,HIGH);
    }
 
  }

}
