const int echoPin = 7; // Echo Pin of Ultrasonic Sensor
const int pingPin = 6; // Trigger Pin of Ultrasonic Sensor
                    
void setup() 
{
  Serial.begin(9600); // Starting Serial Communication
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); // initialising pin 2 as input
}
void loop()
{
  long duration, distance, inches, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method

  distance = ( duration / 2) / 29.1;
  Serial.println("cm:"); 
  Serial.println(distance);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

//--------------------desicionwaterbender-----------//

if (distance <= 111) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delay(100); // Wait for 100 millisecond(s)
    Serial.print("SAFE LEVEL: ");
  }
  if (distance > 111 && distance < 285) {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delay(100); // Wait for 100 millisecond(s)
    Serial.print("MODERATE LEVEL: ");
  }
  if (distance > 285) {
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(100); // Wait for 100 millisecond(s)
    Serial.print("RISK LEVEL: ");
  }

  
  delay(100);
}

//-------------------conversion-----------------------------//

long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}
