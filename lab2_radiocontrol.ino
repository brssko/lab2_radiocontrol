/*
 * Lab 2 PADIOKEPYBANNA
 * BAPIAHT 1
 * Brusko A.V. RS-21MP
  */

#include <Servo.h>
Servo servo1;           //Створюємо об'єкт бібліотеки Servo
int angle = 0;            //Оголошуємо змінну для керування кутом повороту серво приводу

void setup() {
  pinMode(12, INPUT_PULLUP); //Назначаємо вивід 13 на вхід зі вбудованим pullup-опором
  servo1.attach(9);   //Назначаємо вивід, до якого підключимо серво привід
  servo1.write(0);    //Встановлюємо серво у початкову позицію
}

void loop() {
  if(digitalRead(12)==0){     //Якщо кнопка натиснута,
    if(angle<180){            //І кут менший ніж 180
      angle+=5;               //То збільшуємо кут повороту на 5*
      servo1.write(angle);    //І оновлюємо сигнал на GPIO
    }
    else{                     //Якщо ж кут повороту перевищив 180*
      angle=0;                //То обнулюємо його
      servo1.write(angle);    //І виводимо оновлений сигнал на GPIO
    }
    delay(100);               //Робимо затримку між зчитуваннями стану кнопки
  }
}
