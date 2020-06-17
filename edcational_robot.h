#ifndef edcational_robot_h
#define edcational_robot_h

#include <Arduino.h>

const byte PWM1 = 2; //motor1
const byte PWM2 = 3; //motor2
const byte PWM3 = 5; //motor3
const byte PWM4 = 6; //motor4
const byte PWM5 = 7; //free port
const byte PWM6 = 8; //free port
const byte PWM7 = 9; //Servo1
const byte PWM8 = 10; //Servo2
const byte PWM9 = 44; //free port
const byte PWM10 = 45; //free port
const byte PWM11 = 46; //free port

const byte MA1 = 23;
const byte MA2 = 27;
const byte MA3 = 31;
const byte MA4 = 35;

const byte MB1 = 25;
const byte MB2 = 29;
const byte MB3 = 33;
const byte MB4 = 37;

const byte D0 = 22;
const byte D1 = 24;
const byte D2 = 26;
const byte D3 = 28;
const byte D4 = 30;
const byte D5 = 32;
const byte D6 = 34;
const byte D7 = 36;
const byte D8 = 38;
const byte D9 = 40;
const byte D10 = 42;

class Robot{
    private :

    public : 
      Robot();
      void init();
      
};

class Motor{
    private : 
          
    public : 
      Motor();
      void init();
      void motor_1 (const int pwm_value);
      void motor_2 (const int pwm_value);
      void motor_3 (const int pwm_value);
      void motor_4 (const int pwm_value); 
      void omuni(float angle1 , int percentage);
};

#endif