Servo rservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo lservo;

const int LEFT = 0;
const int RIGHT = 1;
const int FORWARD = 2;
const int BACKWARD = 3;

int pos = 0;    // variable to store the servo position 
int dir = 2;

void setup() 
{ 
    rservo.attach(D0);  // attaches the servo on pin 0 to the servo object 
    lservo.attach(D1);
} 

void buzz(Servo svo)
{
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    svo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    svo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  }
}

void double_buzz(Servo svo1, Servo svo2)
{
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    svo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
    svo2.write(pos);
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    svo1.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position
    svo2.write(pos);
  }
}

void loop() 
{
    if (dir == RIGHT)
    {
        buzz(rservo);
    } else if (dir == LEFT)
    {
        buzz(lservo);
    } else if (dir == FORWARD)
    {
        double_buzz(rservo, lservo);
    }
}