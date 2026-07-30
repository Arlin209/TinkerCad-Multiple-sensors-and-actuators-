#include <Servo.h>

Servo gate;

// Ultrasonic Sensor
int trigPin = 9;
int echoPin = 10;

// Pushbutton
int parkingButton = 2;

// Servo
int servoPin = 3;

// LEDs
int greenLED = 5;
int redLED = 6;

// Buzzer
int buzzer = 8;


long duration;
int distance;


void setup() {

  gate.attach(servoPin);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Pushbutton with internal pull-up resistor
  pinMode(parkingButton, INPUT_PULLUP);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);


  gate.write(0);   // Gate closed


  Serial.begin(9600);
}



void loop() {


  // -------- Ultrasonic Distance --------

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;



  // Car near entrance
  bool carDetected = (distance < 15);



  // Button pressed = parking full
  bool parkingFull = (digitalRead(parkingButton) == LOW);



  // Check button value
  Serial.print("Button: ");
  Serial.println(digitalRead(parkingButton));

  Serial.print("Distance: ");
  Serial.println(distance);



  // -------- PARKING EMPTY --------

  if (parkingFull == false) {


    digitalWrite(greenLED, HIGH);

    digitalWrite(redLED, LOW);

    noTone(buzzer);



    // Open gate when car arrives

    if (carDetected) {

      gate.write(90);

      delay(3000);

      gate.write(0);

    }

  }



  // -------- PARKING FULL --------

  else {


    digitalWrite(greenLED, LOW);

    digitalWrite(redLED, HIGH);


    tone(buzzer, 1000);


    gate.write(0);

  }



  delay(200);

}