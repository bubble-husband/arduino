// Mixly 数码管时钟实验

// 滚动字符串：
#include <SevenSegmentTM1637.h>

SevenSegmentTM1637  display(A0,A5);

void setup(){
   display.begin();
  while (true) {
    display.print("abcdefgh");
  }
}

void loop(){

}
// 显示自定义时间：
#include <SevenSegmentExtended.h>
#include <SevenSegmentTM1637.h>

SevenSegmentExtended  display(A0,A5);

void setup(){
   display.begin();
  while (true) {
    display.printTime(12,30,HIGH);
  }
}

void loop(){

}

// 实现时钟：
#include <SevenSegmentExtended.h>
#include <SevenSegmentTM1637.h>

SevenSegmentExtended  display(A0,A5);
volatile int min2;
volatile int second;

void setup(){
  pinMode(11, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  min2 = 0;
  second = 0;
   display.begin();
}

void loop(){
  Serial.println(digitalRead(11));
  if (digitalRead(11) == 0) {
    digitalWrite(9,HIGH);

  } else {
    digitalWrite(9,LOW);

  }

  display.setBacklight(20);
  display.printTime(min2,second,HIGH);
  delay(1000);
  second = second + 1;
  if (second == 60) {
    second = 0;
    min2 = min2 + 1;
    if (min2 == 0) {
      min2 = 0;

    }

  }

}