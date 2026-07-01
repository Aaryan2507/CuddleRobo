#include <FluxGarage_RoboEyes.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SH1106G display=Adafruit_SH1106G(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,OLED_RESET);
RoboEyes<Adafruit_SH1106G> roboEyes(display);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if(!display.begin()){
    Serial.println("ALLOCATIION FAILED");
    for(;;);
  }
  roboEyes.begin(SCREEN_WIDTH,SCREEN_HEIGHT,100);
  roboEyes.setAutoblinker(ON,3,1);
  roboEyes.setIdleMode(ON,3,2);
  roboEyes.setCuriosity(ON);
  //roboEyes.anim_confused();

}

void loop() {
  // put your main code here, to run repeatedly:
  roboEyes.update();

}
