Servo rservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
Servo lservo;

// WASD controls, no backward direction so no S defined

const int LEFT = 97;     // A
const int RIGHT = 100;   // D
const int FORWARD = 119; // W

const int HELP = 104;    // H

int pos = 0;    // variable to store the servo position 
int dir = 2;

int incomingByte = 0;

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

void help()
{
    Serial.println("Welcome to Blind Assassin!");
    Serial.println("Handler: Move your teammate using the keyboard.");
    Serial.println("Left - 'a' Forward - 'w' Right - 'd'");
    Serial.println("Assassin: Move left when left motor buzzes.");
    Serial.println("Assassin: Move right when right motor buzzes.");
    Serial.println("Assassin: Move forward when both motors buzz.");
}

void loop() 
{
    if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();
                
                // else if statements did not work here for reasons for which there was no time to debug
                if (incomingByte == FORWARD)
                {
                    double_buzz(rservo, lservo);
                }
                if (incomingByte == LEFT)
                {
                    buzz(lservo);
                } 
                if (incomingByte == RIGHT)
                {
                    buzz(rservo);
                } 
                if (incomingByte == HELP)
                {
                    help();
                }

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte, DEC);
        }
}