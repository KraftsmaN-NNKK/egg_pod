#include "edcational_robot.h"
#include <Arduino.h>

Robot::Robot(){}

void Robot::init(){
  pinMode(PWM1, OUTPUT); 
  pinMode(PWM2, OUTPUT); 
  pinMode(PWM3, OUTPUT); 
  pinMode(PWM4, OUTPUT);
  pinMode(PWM5, OUTPUT); 
  pinMode(PWM6, OUTPUT); 
  pinMode(PWM7, OUTPUT); 
  pinMode(PWM8, OUTPUT);
  pinMode(PWM9, OUTPUT); 
  pinMode(PWM10, OUTPUT); 
  pinMode(PWM11, OUTPUT); 

  pinMode(MA1, OUTPUT);   
  pinMode(MA2, OUTPUT);   
  pinMode(MA3, OUTPUT);   
  pinMode(MA4, OUTPUT); 

  pinMode(MB1, OUTPUT);   
  pinMode(MB2, OUTPUT);   
  pinMode(MB3, OUTPUT);   
  pinMode(MB4, OUTPUT);   

  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
  Serial3.begin(115200);
}

////////////////

Motor::Motor (){
	//init();
}

void Motor::init(){
  /*pinMode(PWM1, OUTPUT); //pin 5
  pinMode(PWM2, OUTPUT); //pin 6
  pinMode(PWM3, OUTPUT); //pin 7
  pinMode(PWM4, OUTPUT); //pin 8
  pinMode(MA1, OUTPUT);   //pin 23
  pinMode(MA2, OUTPUT);   //pin 27
  pinMode(MA3, OUTPUT);   //pin 31
  pinMode(MA4, OUTPUT);   //pin 35
  pinMode(MB1, OUTPUT);   //pin 25
  pinMode(MB2, OUTPUT);   //pin 29
  pinMode(MB3, OUTPUT);   //pin 33
  pinMode(MB4, OUTPUT);   //pin 37*/
}

void Motor::motor_1 (int pwm_value) {

  if (pwm_value > 0) {
    digitalWrite (MA1, 1);
    digitalWrite (MB1, 0);
    analogWrite  (PWM1, abs(pwm_value));
  }
  else if (pwm_value < 0) {
    digitalWrite (MA1, 0);
    digitalWrite (MB1, 1);
    analogWrite  (PWM1, abs(pwm_value));
  }
  else {
    digitalWrite (MA1, 0);
    digitalWrite (MB1, 0);
    analogWrite  (PWM1, 0);
  }
}

void Motor::motor_2 (int pwm_value) {

  if (pwm_value > 0) {
    digitalWrite (MA2, 1);
    digitalWrite (MB2, 0);
    analogWrite  (PWM2, abs(pwm_value));
  }
  else if (pwm_value < 0) {
    digitalWrite (MA2, 0);
    digitalWrite (MB2, 1);
    analogWrite  (PWM2, abs(pwm_value));
  }
  else {
    digitalWrite (MA2, 0);
    digitalWrite (MB2, 0);
    analogWrite  (PWM2, 0);
  }
}

void Motor::motor_3 (int pwm_value) {

  if (pwm_value > 0) {
    digitalWrite (MA3, 1);
    digitalWrite (MB3, 0);
    analogWrite  (PWM3, abs(pwm_value));
  }
  else if (pwm_value < 0) {
    digitalWrite (MA3, 0);
    digitalWrite (MB3, 1);
    analogWrite  (PWM3, abs(pwm_value));
  }
  else {
    digitalWrite (MA3, 0);
    digitalWrite (MB3, 0);
    analogWrite  (PWM3, 0);
  }
}

void Motor::motor_4 (int pwm_value) {

  if (pwm_value > 0) {
    digitalWrite (MA4, 1);
    digitalWrite (MB4, 0);
    analogWrite  (PWM4, abs(pwm_value));
  }
  else if (pwm_value < 0) {
    digitalWrite (MA4, 0);
    digitalWrite (MB4, 1);
    analogWrite  (PWM4, abs(pwm_value));
  }
  else {
    digitalWrite (MA4, 0);
    digitalWrite (MB4, 0);
    analogWrite  (PWM4, 0);
  }
}

void Motor::omuni(float angle1 , int percentage){
  float angle2;
  
  if((-3 * PI / 4 < angle1) && (angle1 <= -PI)){
	  angle2 = PI/4 - angle1;
  }
  else angle2 = angle1 - PI/4;
  
  float x = cos(angle2);
  float y = sin(angle2);
  
  float a = max(abs(x),abs(y));
  
  float X = x * (1/a);
  float Y = y * (1/a);
  
  int V1 = -X*255*percentage/100; 
  int V2 = -Y*255*percentage/100;
  int V3 = X*255*percentage/100;
  int V4 = Y*255*percentage/100;

  Motor::motor_1(V1);
  Motor::motor_2(V2);
  Motor::motor_3(V3);
  Motor::motor_4(V4);
}