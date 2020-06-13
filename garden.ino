/*
* Andrew Barlow
* Automated Indoor Herb Gardening System
*
* This project aims to automatically water and light a small herb garden using an arduino
*
* My current watering strategy is to use a sensor to detect soil wetness and water at a certain dryness
*
* For lighting I plan on using Sparkfun's DS3234 Breakout board to keep track of the time and
* use some strips of LED grow lights to light it during the daytime
* Will probably use a
*
* disclaimer some code is from Sparkfun's DS3234 demo to make things easier (this is a project for fun)
*
*/



//////////////////////////////////
// Libraries /////////////////////
//////////////////////////////////

#include <SPI.h>
#include <SparkFunDS3234RTC.h>



//////////////////////////////////
// Custom Definitions ////////////
//////////////////////////////////

// Comment out the line below if you want date printed before month.
// E.g. October 31, 2016: 10/31/16 vs. 31/10/16
#define PRINT_USA_DATE



//////////////////////////////////
// Configurable Pin Definitions //
//////////////////////////////////

// a button pin to test the motor without waiting till noon
#define BUTTON 6

// light out, expected to change based on final circuit setup but should have pwm
// implementation will be a mosfet interacting with an external power supply
#define LIGHT 9

// Moisture sensor, analog input
#define MOISTURE A1

// water pump control, not sure which pin to use yet
#define PUMP 4

#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin


//////////////////////////////////
// GLOBAL VARIABLES //////////////
//////////////////////////////////

// if on, enable serial logging for debugging
bool debug = true;

// are the lights on?
bool lightsOn = true;
// how bright are the lights?
int lightVal = 0;

// bool to determine if water pump should be running
bool pumpOn = false;

// keep hour, minute, second vals as their own variables to be refreshed/referenced by functions instead of making repeated calls to the rtc
int h;
int m;
int s;


//////////////////////////////////
// HELPER FUNCTIONS //////////////
//////////////////////////////////

// Test various parts by vals passed
void testSensors(bool Time, bool Water, bool Lighting) {

  if (debug) {

    // output the current time
    if (Time) {
    Serial.print("time: ");
    Serial.print(h);
    Serial.print(":");
    Serial.print(m);
    Serial.print(":");
    Serial.print(s);
    Serial.print("  ");
    }

    if (Water) {
      Serial.print("  Water: ");
      if (pumpOn) {
        Serial.print("PUMP ON  ");
      }
      else {
        Serial.print("PUMP OFF  ");
      }
    }

    if (Lighting) {
    //print Light val
    Serial.print("  Lighting:  ");
    Serial.print(lightVal);
    }

  Serial.println();
  }

}

// update time values
void refresh() {
  rtc.update();
  h = rtc.hour();
  m = rtc.minute();
  s = rtc.second();
}

// take time and map it to the appropriate lighting val
// will ramp up from 0->255 from 7am->8am and back down from 7pm->8pm
void lights() {

  // edge cases
  if (h == 7 || h == 14) {
    lightsOn = true;

    // map minute value to light value
    lightVal = map(m, 0, 60, 0, 255);
  }
  // full strength in daytime
  else if (h > 7 && h < 19) {
    lightsOn = true;
    lightVal = 255;
  }
  // off at night
  else {
    lightsOn = false;
    lightVal = 0;
  }


  // take calculated value and get them lights to shine or nah
  // written a lil redundantly, might change later
  if (lightsOn) {
    analogWrite(LIGHT, lightVal);
  }
  else {
    analogWrite(LIGHT, 0);
  }

}

void water() {

  // if the button is pressed or it is noon then turn pump on
  pumpOn = digitalRead(BUTTON) || ((h == 12) && (m == 0));

  if (pumpOn) {
    digitalWrite(PUMP, HIGH);
  }
  else {
    digitalWrite(PUMP, LOW);
  }

}


//////////////////////////////////
// SETUP /////////////////////////
//////////////////////////////////

void setup() {

  if (debug) {
    //Serial output
    Serial.begin(9600);
  }
  // pin inits
  pinMode(3, OUTPUT);
  pinMode(BUTTON, INPUT);
  pinMode(LIGHT, OUTPUT);
  pinMode(PUMP, OUTPUT);
  // pinMode(MOISTURE, INPUT);



  // use pin def to start rtc module
  rtc.begin(DS13074_CS_PIN);

  // use autoTime() to set RTC with compiler's time; a few secs off but close enough
  rtc.autoTime();

  // update clock, set global vars for use
  refresh();
}

//////////////////////////////////
// LOOP //////////////////////////
//////////////////////////////////

void loop() {
  refresh();
  
  testSensors(1, 1, 1);

  lights();

  water();




}
