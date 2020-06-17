#include "edcational_robot.h"

Robot Robot;
Motor Motor;

int IR_ball[8];
int ball_angle;
int go_angle;

void setup(){
  Robot.init();
}

void loop(){
  get_IR_ball();
  long x = IR_ball[0] * 1000 + (IR_ball[1] * 707) - (IR_ball[3] * 707) - IR_ball[4] * 1000 - (IR_ball[5] * 707) + (IR_ball[7] * 707);
  long y = (IR_ball[1] * 707) + IR_ball[2] * 1000 + (IR_ball[3] * 707) - (IR_ball[5] * 707) - IR_ball[6] * 1000 - (IR_ball[7] * 707);
  ball_angle = atan2(y,x) * 100;
  robot_go_angle();
  Motor.omuni(go_angle / 100 , 60);
}

void get_IR_ball(){
  for(int i = 0; i < 8; i++){
    IR_ball[i] = analogRead(i);
  }
}

void robot_go_angle() {
  if ((314 / 3 <= ball_angle) && (ball_angle <= 2 * 314 / 3)) {
    go_angle = ball_angle;
  }


  if (((0 <= ball_angle) && (ball_angle < 314 / 12)) || ((11 * 314 / 12 < ball_angle) && (ball_angle <= 314))) {
    go_angle = -157;
  }

  else if ((314 / 12 <= ball_angle) && (ball_angle < 314 / 3)) {
    go_angle = ball_angle - 314 / 2;
  }

  else if ((2 * 314 / 3 < ball_angle) && (ball_angle <= 11 * 314 / 12)) {
    go_angle = ball_angle - 3 * 314 / 2;
  }

  else if ((-314 / 2 <= ball_angle) && (ball_angle < 0)) {
    go_angle = -314 / 2 + ball_angle;
  }
  else if ((-314 <= ball_angle) && (ball_angle < -314 / 2 )) {
    go_angle = 314 / 2 + ball_angle;
  }
}