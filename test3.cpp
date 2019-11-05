// Mixly遥控调光器

#include <IRremote.h>

IRrecv irrecv_2(2);
decode_results results_2;

long ir_item;
volatile int led;
volatile int ledstate;

void setup(){
  led = 0;
  ledstate = 0;
  Serial.begin(9600);
  irrecv_2.enableIRIn();
}

void loop(){
  if (irrecv_2.decode(&results_2)) {
    ir_item=results_2.value;
    String type="UNKNOWN";
    String typelist[14]={"UNKNOWN", "NEC", "SONY", "RC5", "RC6", "DISH", "SHARP", "PANASONIC", "JVC", "SANYO", "MITSUBISHI", "SAMSUNG", "LG", "WHYNTER"};
    if(results_2.decode_type>=1&&results_2.decode_type<=13){
      type=typelist[results_2.decode_type];
    }
    Serial.print("IR TYPE:"+type+"  ");
    Serial.println(led);
    Serial.println(ir_item,HEX);
    if (ir_item == 0xFF629D) {
      ledstate = !ledstate;
      led = ledstate * 128;

    }
    analogWrite(9,led);
    if (ledstate == 1) {
      if (ir_item == 0xFFE21D) {
        led = constrain(led + 20, 5, 255);

      }
      if (ir_item == 0xFFA25D) {
        led = constrain(led - 20, 5, 255);

      }
      analogWrite(9,led);

    }
    irrecv_2.resume();
  } else {
  }

}