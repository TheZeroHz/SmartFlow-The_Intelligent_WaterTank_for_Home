#ifndef WATERTANK_H
#define WATERTANK_H
//#include<Arduino.h>
#include<bits/stdc++.h>
class WaterTank{
 
 public:
 void setDFML(double sensor_to_max_height);
 void setMaxHeight(double max_height);
 void setMaxCapacity(double max_capacity);
 void setUltrasonic(int triggerPin, int echoPin);
 void setPump(int PumpMotorPin);
 void setTemp(double temperature);
 
 void test(double y);
 
 void Pump(bool a);
 bool AutoPump(char unit[],double upper_limit,double lower_limit);
  
 double measureWater(char unit[]);
 double getMaxHeight();
 double getDistance();
 
 private:
 bool pump_state=false;
 double max_height=0,sensor_to_max_height=0;
 double max_capacity=0;
 double temperature=25;
 int triggerPin,echoPin,PumpMotorPin;
 double p=0,y=0,x=0,aw=0;	
};
 
#endif
