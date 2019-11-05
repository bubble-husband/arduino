// 以下是呼吸灯的代码：
void fadeON(int time) {
  for (int i = 0; i <= 255; i = i + (5)) {
    analogWrite(6,i);
    delay((time / (255 / 5)));
  }
}
void fadeON2(int time) {
  for (int i = 255; i >= 0; i = i + (-5)) {
    analogWrite(6,i);
    delay((time / (255 / 5)));
  }
}
void setup(){
  analogWrite(6,255);
  fadeON(2000);
  fadeON2(2000);
}
void loop(){
}
// 主要是通过延时以及通过调节灯的亮度来实现该功能

volatile int b1;
volatile int b2;
volatile int brightness;
volatile int state;
void setup(){
  brightness = 0;
  state = 1;
  b1 = 0;
  b2 = 0;
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}
void loop(){
  b1 = digitalRead(8);
  if (b1 != state) {
    b2 = digitalRead(8);
    delay(300);
    if (b2 == b1) {
      brightness = (long) ((brightness + 1)) % (long) (6);
      Serial.println(brightness);
      Serial.println(String("n") + String(b2));
    }
    b1 = !b1;
  }
  analogWrite(6,(brightness * 51));
}
// 以上代码为五档调节灯的代码，主要通过两个变量来记录读取到的按钮，实验抖动，避免档次的跳级，利用延时使调节灯更加稳定。