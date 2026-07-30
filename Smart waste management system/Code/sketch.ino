#include <Servo.h>

Servo dustbinServo;

// Sensor pins
#define IR_PIN 2
#define TRIG_PIN 7
#define ECHO_PIN 6

// Actuator pins
#define BUZZER_PIN 8
#define SERVO_PIN 9

long duration;
int distance;
int objectDetected;


void setup()
{
  pinMode(IR_PIN, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  dustbinServo.attach(SERVO_PIN);

  // Lid closed initially
  dustbinServo.write(0);

  Serial.begin(9600);
}


void loop()
{
  // Read IR sensor
  objectDetected = digitalRead(IR_PIN);


  // Ultrasonic distance measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.034 / 2;


  Serial.print("Garbage Level Distance: ");
  Serial.println(distance);


  // Open lid when hand detected
  if(objectDetected == LOW)
  {
    dustbinServo.write(90);
    delay(2000);

    dustbinServo.write(0);
  }


  // Full dustbin alert
  if(distance < 5)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("Dustbin Full!");
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
  }


  delay(500);
}