#include <Servo.h>
Servo ESC;
int val;
int globalval;
void setup() 
{
  Serial.begin(9600);
  ESC.attach(9,1000,2000); //PWM Pin Connection Port on Arduino
}

void loop() 
{
  while(Serial.available())
  {
    val = Serial.parseInt(); //reads integer vals from serial monitor input
    Serial.println(val);         //Print throttle value
    ESC.write(val);         //Write throttle value to ESC
    if (val > 0){
      globalval = val;
      //Store throttle value
    }
  }
  
    if(!Serial.available())
  {
    Serial.println(globalval);
 //Print stored throttle value
    ESC.write(globalval);
     //Assign previously stored throttle value to ESC
  }

}
