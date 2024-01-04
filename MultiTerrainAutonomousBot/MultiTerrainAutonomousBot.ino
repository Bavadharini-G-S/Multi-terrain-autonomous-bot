int distance;
int duration;
const int trigPin = 11;
const int echoPin = 10;

int enA = 4;
int in1 = 5;
int in2 = 6;
int in3 = 7;
int in4 = 8;
int enB = 9;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  Serial.begin(9600);
}

void loop() {
  //Ultrasonic Sensor
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  forward();
  if(distance<35){
    left();
    }

  else if(distance<20){
    right();
    }
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}


void forward(){
  
  analogWrite(enA, 255);
  analogWrite(enB,255);

  Serial.print("forward");

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  }


void backward()
{
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);

  analogWrite(enA, 255);
  analogWrite(enB,255);
}

void right()
{
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
     digitalWrite(in3, HIGH);
     digitalWrite(in4, LOW);

  analogWrite(enA, 255);
  analogWrite(enB,255);
}

void left()
{
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
     digitalWrite(in3, LOW);
     digitalWrite(in4, HIGH);

  analogWrite(enA, 255);
  analogWrite(enB,255);
}