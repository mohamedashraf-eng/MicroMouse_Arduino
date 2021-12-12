/*
  Author: Wx & Derwy.
  Date: 12/8/2021.
  Subject: Main file to excute the code.
*/
//======= ======= ======= ======= ======= ======= ======= ======= =======

// Headers Included:
#include "Movement.h"
#include "IR_sensors.h"

// Global Variables:

// Timer interrupt variables.
unsigned long TIME[] = {0, 0, 0};

// Code Protection switch:
uint8_t SWITCH_PIN = 5;
bool START_SWITCH = false;


void setup() 
{
  // For debugging.
  //Serial.begin(115200);
  pinMode(SWITCH_PIN, INPUT);
  digitalWrite(SWITCH_PIN, LOW);
  
// code routine.
  // INIT FUNCTION FOR THE L293d.
  L293d_INIT();

  // INIT FUNCTION FOR T HE IR's.
  IR_INIT();


  // Setting init time for the code: (time in milliseconds)
  for(uint8_t i = 0; i < 3; i++) {TIME[i] = millis();}
}

void loop() 
{
  // Code controlability mechanism.
  START_SWITCH = digitalRead(SWITCH_PIN);
  
  while(START_SWITCH)
  {
    // Wait 10secondes to start.
    delay(10000);

    // Start the main routine:
  }

}
