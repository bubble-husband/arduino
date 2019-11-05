// Mixly按键控制LED灯

volatile int b1;
volatile int b2;
volatile int click;
volatile int lastState;
volatile int toggle;

void setup(){
  lastState = digitalRead(11);
  toggle = 1;
  click = 0;
  b1 = 1;
  b2 = 1;
  pinMode(11, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(9, OUTPUT);
}

void loop(){
  Serial.println(toggle);
  b1 = digitalRead(11);
  if (b1 != lastState) {
    b2 = digitalRead(11);
    if (b2 == b1) {
      lastState = b1;
      click = click + 1;

    }

  }
  if (click == 2) {
    click = 0;
    toggle = !toggle;
    digitalWrite(9,toggle);

  }

}