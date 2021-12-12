/*
  Author: Wx & Derwy.
  Date: 12/8/2021.
  Subject: IR sensors handling. 
*/
//======= ======= ======= ======= ======= ======= ======= ======= =======

//Header Guards:
#ifndef __IR_Sensors_H__
#define __IR_Sensors_H__


/****************************************
 *          Declared Functions          *
****************************************/

void IR_INIT(void);
bool IR1_INPUT(void);
bool IR2_INPUT(void);
bool IR3_INPUT(void);

/****************************************
 *          Global Variables            *
****************************************/

//L293d declration and defintion:
const uint8_t IR_PINS[] = 
                          {6,  // IR_Sensor(1) INPUT.
                           12, // IR_Sensor(2) INPUT.
                           13  // IR_Sensor(3) INPUT.     
                          };

// user friendly code.
#define IR1_DATA IR_PINS[0]
#define IR2_DATA IR_PINS[1]
#define IR3_DATA IR_PINS[2]

/****************************************
 *          Main Functions              *
****************************************/

// INITALAIZING THE IR Sensors.
void IR_INIT(void)
{
  // set all the pins as output and init them with low volt.
  for(uint8_t i = 0; i < 3; i++)
  {
    pinMode(IR_PINS[i], INPUT);
    digitalWrite(IR_PINS[i], LOW);
  }
  delay(10);
}//end IR_INIT.

bool IR1_INPUT(void)
{
  uint8_t IR1_READ = 0;


  IR1_READ = digitalRead(IR1_DATA);
  
  return IR1_READ;
}//end IR1_INPUT.

bool IR2_INPUT(void)
{
  uint8_t IR2_READ = 0;


  IR2_READ = digitalRead(IR2_DATA);
  
  return IR2_READ;
}//end IR2_INPUT.

bool IR3_INPUT(void)
{
  uint8_t IR3_READ = 0;


  IR3_READ = digitalRead(IR3_DATA);
  
  return IR3_READ;
}//end IR3_INPUT.

//======= ======= ======= ======= ======= ======= ======= ======= =======
#endif
