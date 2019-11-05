// Mixly-智能楼道灯

void setup(){
  pinMode(8, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop(){
  Serial.println(digitalRead(8));
  Serial.println(analogRead(A1));
  if (analogRead(A1) > 140 || digitalRead(8) == 1) {
    digitalWrite(13,HIGH);
    delay(5000);

  } else {
    digitalWrite(13,LOW);

  }

}