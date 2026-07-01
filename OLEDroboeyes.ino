#include <FluxGarage_RoboEyes.h> //The main part of this project, FluxGarage's RoboEyes library that will help us create cool eyes
#include <SPI.h> //Not necessary to import, but allows SPI protocol to be used efficiently
#include <Wire.h> //A standard Arduino package library, good practice to import as it is used in further libraries
#include <Adafruit_GFX.h> // One of the two libraries needed to work the OLED(in my case SH1106) display.
#include <Adafruit_SH110X.h> //The second library needed to work the OLED display, if your display is a SSD1306, then you have to import another library.

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
/*Here we defined our screen's specifications along with a RESET condtion*/
Adafruit_SH1106G display=Adafruit_SH1106G(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,OLED_RESET); //Creating an object from the library to use to issue commands
RoboEyes<Adafruit_SH1106G> roboEyes(display); //Creating a RoboEyes object to allow usage of the functions of the RoboEyes library
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  if(!display.begin()){
    Serial.println("ALLOCATIION FAILED");
    for(;;);
  }
  roboEyes.begin(SCREEN_WIDTH,SCREEN_HEIGHT,100);
  roboEyes.setAutoblinker(ON,3,1); //This function sets the eyes to keep blinking at regular intervals
  roboEyes.setIdleMode(ON,3,2);//This function enables an "Idle Mode" a mode for the display when no new commands are being issued
  roboEyes.setCuriosity(ON);//This functions enables the curiosity mode which allows the eyes to go to and fro across the display.
  //roboEyes.anim_confused();

}
//The setup function starts our display, and configures the RoboEyes object to act in a certain manner as per our specifications.
void loop() {
  // put your main code here, to run repeatedly:
  roboEyes.update();//This function updates the RoboEyes objet, and in turn the display.

}
