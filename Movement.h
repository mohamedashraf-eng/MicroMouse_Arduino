/*
  Author: Wx & Derwy.
  Date: 12/8/2021.
  Subject: Algorithms for car movment & motor control. 
*/
//======= ======= ======= ======= ======= ======= ======= ======= =======

//Header Guards:
#ifndef __Movement_H__
#define __Movement_H__


/****************************************
 *          Declared Functions          *
****************************************/

void L293d_INIT(void);
void MOVE_FORWARD(uint8_t);
void MOVE_BACKWARD(uint8_t);
void MOVE_LEFT(uint8_t);
void MOVE_RIGHT(uint8_t);

/****************************************
 *          Global Variables            *
****************************************/

//L293d declration and defintion:
const uint8_t L293d_PINS[] = 
                          {3, // PWM - ENABLE(1, 2).
                           5, // PWM - ENABLE(3, 4).
                           
                           2, // NORM - INPUT(1).
                           4, // NORM - INPUT(2).

                           7, // NORM - INPUT(3).
                           8  // NORM - INPUT(4).
                          };
// user friendly code                          
#define ENABLE12 L293d_PINS[0]
#define ENABLE34 L293d_PINS[1]

#define INPUT1 L293d_PINS[2]
#define INPUT2 L293d_PINS[3]
#define INPUT3 L293d_PINS[4]
#define INPUT4 L293d_PINS[5]      
                 

/****************************************
 *          Main Functions              *
****************************************/

// INITALAIZING THE L293d Motor driver.
void L293d_INIT(void)
{
  // set all the pins as output and init them with low volt.
  for(uint8_t i = 0; i < 6; i++)
  {
    pinMode(L293d_PINS[i], OUTPUT);
    digitalWrite(L293d_PINS, LOW);
  }
  delay(10);
}//end L293d_INIT


void MOVE_FORWARD(uint8_t MOTORS_SPEED)
{
  // Control the speed of motors.
  analogWrite(ENABLE12, MOTORS_SPEED);
  analogWrite(ENABLE34, MOTORS_SPEED);
  
  pinMode(INPUT1, HIGH);
  pinMode(INPUT2, LOW);

  pinMode(INPUT3, HIGH);
  pinMode(INPUT4, LOW);
  delay(10);
}//end MOVE_FORWARD


void MOVE_BACKWARD(uint8_t MOTORS_SPEED)
{
  // Control the speed of motors.
  analogWrite(ENABLE12, MOTORS_SPEED);
  analogWrite(ENABLE34, MOTORS_SPEED);
  
  pinMode(INPUT1, LOW);
  pinMode(INPUT2, HIGH);
  
  pinMode(INPUT3, LOW);
  pinMode(INPUT4, HIGH);
  
  delay(10);
}//end MOVE_BACKWARD


void MOVE_RIGHT(uint8_t MOTORS12_SPEED, uint8_t MOTORS34_SPEED)
{
  // Control the speed of motors.
  analogWrite(ENABLE12, MOTORS12_SPEED);
  analogWrite(ENABLE34, MOTORS34_SPEED);

  pinMode(INPUT1, LOW);
  pinMode(INPUT2, HIGH);
  
  pinMode(INPUT3, LOW);
  pinMode(INPUT4, LOW);
  delay(15);
}//end MOVE_RIGHT

void MOVE_LEFT(uint8_t MOTORS12_SPEED, uint8_t MOTORS34_SPEED)
{
  // Control the speed of motors.
  analogWrite(ENABLE12, MOTORS12_SPEED);
  analogWrite(ENABLE34, MOTORS34_SPEED);
  
  pinMode(INPUT1, LOW);
  pinMode(INPUT2, LOW);

  pinMode(INPUT3, LOW);
  pinMode(INPUT4, HIGH);
  
  delay(15);
}//end MOVE_LEFT

void U_TURN(uint8_t MOTORS12_SPEED, uint8_t MOTORS34_SPEED)
{

  
}
//======= ======= ======= ======= ======= ======= ======= ======= =======
#endif
