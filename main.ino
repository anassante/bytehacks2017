Servo rservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo lservo;

const int LEFT = 0;
const int RIGHT = 1;
const int FORWARD = 2;
const int BACKWARD = 3;

int pos = 0;    // variable to store the servo position 
int dir = FORWARD;
int count = 0;
int step = 0;  // index for route

int route[] = {FORWARD, RIGHT, FORWARD, LEFT, LEFT, FORWARD};

// static char inData[51]; // Allocate some space for the string
// static char inChar=-1; // Where to store the character read
// static int charpos= 0; // Index into array; where to store the character

// int incoming = 0;

void setup() 
{ 
    Serial.begin(9600);
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
  Serial.println("buzz");
}

void double_buzz(Servo svo1, Servo svo2)
{
    for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
        svo1.write(pos);              // tell servo to go to position in variable 'pos' 
        svo2.write(pos);
        delay(500);                    
    } 
    for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
    {                                
        svo1.write(pos);              // tell servo to go to position in variable 'pos' 
        svo2.write(pos);
        delay(500);   
    }
    Serial.println("double buzz");
}

//// Different vibration pattern inserted in between different direction calls
//// to make it clearer that direction has changed
//void transition_alert(Servo svo1, Servo svo2)

void loop() 
{
    Serial.println("test");

    if (count = 200)
    {
        dir = route[step];
        step++;
        count = 0;
    }
    count++;
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