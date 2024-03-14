#include "WaterTank.h"
using namespace std;
#define ON true
#define OFF false
void WaterTank::setMaxHeight(double max_height){
this->max_height=max_height;	
}

void WaterTank::setDFML(double sensor_to_max_height){
this->sensor_to_max_height=sensor_to_max_height;	
}

void WaterTank::setMaxCapacity(double max_capacity){
this->max_capacity=max_capacity;	
}

void WaterTank::setUltrasonic(int triggerPin, int echoPin){
this->echoPin=echoPin;
this->triggerPin=triggerPin;
}

void WaterTank::setPump(int PumpMotorPin){
this->PumpMotorPin=PumpMotorPin;
}

void WaterTank::setTemp(double temperature){
	this->temperature=temperature;
}

double WaterTank::getDistance(){
  /*
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    unsigned long durationMicroSec = pulseIn(echoPin, HIGH);
    double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * temperature;
    double distanceCm = durationMicroSec / 2.0 * speedOfSoundInCmPerMs;
    if (distanceCm == 0 || distanceCm > 400) {
        return -1.0 ;
    } else {
        return distanceCm;
    }
 */
 return 170.5;
}

void WaterTank::test(double y){
 this->y=y; 	
 }

double WaterTank::measureWater(char unit[]){ 

//y=getDistance();
if(y>sensor_to_max_height+max_height)
y=sensor_to_max_height+max_height;
x=sensor_to_max_height+max_height-y;
if(x>max_height)
x=max_height;
p=(100*x)/max_height;
aw= (max_capacity*x)/max_height;

if(unit[0]=='%'){
return p;
}

else if(unit[0]=='L'){
return aw;
}
else if(unit[0]=='m'&&unit[1]=='l'){
return aw*1000;
}
else if(unit[0]=='c'&&unit[1]=='m'){
return x;	
}
else return -1;
}
 


double WaterTank::getMaxHeight(){
 return max_height;
}

void WaterTank::Pump(bool a){
	if(a==ON){pump_state=ON;}
	else if(a==OFF) {pump_state=OFF; }
}


bool WaterTank::AutoPump(char unit[],double upper_limit,double lower_limit){
bool x=measureWater(unit);
cout<<"P:"<<p<<"  Upper:"<<upper_limit<<"  Lower:"<<lower_limit<<endl;
if(unit[0]=='%'){if(p>=upper_limit)Pump(OFF);if(p<=lower_limit)Pump(ON);}	

return pump_state;
}

using namespace std;



int main(){
WaterTank t;
double y;
while(true){
cout<<endl<<endl<<"sensor reading:";
cin>>y;
t.test(y);
t.setDFML(80.0);
t.setMaxHeight(180.0);
t.setMaxCapacity(5);
cout<<t.measureWater("%")<<"%"<<endl<<t.measureWater("ml")<<"ml"<<endl<<t.measureWater("L")<<"L"<<endl<<t.measureWater("cm")<<"cm"<<endl;	
cout<<"PUMP: "<<t.AutoPump("%",98.0,73.0)<<endl;
}
}
