/*
   The circuit:
  - Groove Base shield
  - Grove - Ultrasonic Ranger attached to pin D7.
  - Grove - LED attached to pin 13, pin 8, pin 4 and 10.
// Declaring variables
const int pingPin = 7;  // pingPin (sensor) is placed in pin D7
int range = 0;

int Object1 = 1;
int Object2 = 1;
int Object3 = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  // establish variables for duration of the ping, and the distance result in inches and centimeters:
  long duration, mm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // GIVE a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);   // sets pingPin (pin D7) to output
  digitalWrite(pingPin, LOW);  // deactivate pingPin (pin D7)
  delayMicroseconds(2);       // wait 2 microsek.
  digitalWrite(pingPin, HIGH); // activate pingPin (pin D7)
  delayMicroseconds(5);       // wait 5 millisek.
  digitalWrite(pingPin, LOW); //deactivate pingPin (pin D7)

  // The same pin is used to READ the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT); // choose pingPin (pin D7) ass an input
  duration = pulseIn(pingPin, HIGH); //  The pulseIn-function reads the time for the pulse from the sending to the return.


  mm = microsecondsToMilimeters(duration);  // convert the time into a distance
  long realHeight = 128 - mm;               // Declaring the variable "realHight" which is the distance from the sensor to the closest registered object in mm



  // if-statments for the three types of objects. The range to identify the objects is based on the objects heights.
  // In the example the the objects height is: object 1: 72 mm, object 2: 40 mm, object 3: 53 mm.

  if (realHeight < 35) {
    Serial.println("Objects awaits");
    digitalWrite(10, HIGH);   // turn the white LED on (HIGH is the voltage level)
      
  }

  if (realHeight > 55 && realHeight <= 75) {
    Serial.print("Object 1: ");
    Serial.print(mm);       //To put a measure on the object
    Serial.print("mm");
    Serial.println();
    delay(50);
    digitalWrite(13, HIGH);   // turn the Green LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(13, LOW);    // turn the Green LED off by making the voltage LOW
    delay(1000);              // wait for a second
    Serial.print(Object1++);
    Serial.println(" pieces");

  }

  if (realHeight > 35 && realHeight < 45) {
    Serial.print("Object 2: ");
    Serial.print(mm);       //To put a measure on the object
    Serial.print("mm");
    Serial.println();
    delay(50);
    digitalWrite(8, HIGH);   // turn the Red LED on (HIGH is the voltage level)
    delay(500);              // wait for haf a second
    digitalWrite(8, LOW);    // turn the Red LED off by making the voltage LOW
    delay(500);              // wait for haf a second
    digitalWrite(8, HIGH);   // turn the Red LED on (HIGH is the voltage level)
    delay(500);              // wait for haf a second
    digitalWrite(8, LOW);    // turn the Red LED off by making the voltage LOW
    delay(500);              // wait for haf a second
    Serial.print(Object2++);
    Serial.println(" pieces");

  }

  if (realHeight > 45 && realHeight < 55) {
    Serial.print("Object 3: ");
    Serial.print(mm);       // To put a measure on the object
    Serial.print("mm");
    Serial.println();
    delay(100);
    digitalWrite(4, HIGH);   // turn the Yellow LED on (HIGH is the voltage level)
    delay(100);              // wait for 100  m second
    digitalWrite(4, LOW);    // turn the YellowLED off by making the voltage LOW
    delay(100);              // wait for 100 m second
    digitalWrite(4, HIGH);   // turn the YellowLED on (HIGH is the voltage level)
    delay(100);              // wait for 100 m second
    digitalWrite(4, LOW);    // turn the YellowLED off by making the voltage LOW
    delay(100);              // wait for 100 m second
    digitalWrite(4, HIGH);   // turn the YellowLED on (HIGH is the voltage level)
    delay(100);              // wait for 100 m second
    digitalWrite(4, LOW);    // turn the YellowLED off by making the voltage LOW
    delay(100);              // wait for 100 m second
    Serial.print(Object3++);
    Serial.println(" pieces");

  }


  // print out the value you read:
  delay(50);        // delay in between reads for stability

}

long microsecondsToMilimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 2.9 / 2;

}

