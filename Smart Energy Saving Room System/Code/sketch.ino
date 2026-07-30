#include <Servo.h>

Servo curtainServo;

#define PIR_PIN 2
#define LDR_PIN A0

#define LED_PIN 8
#define SERVO_PIN 9

void setup()
{
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  curtainServo.attach(SERVO_PIN);
  curtainServo.write(0);

  Serial.begin(9600);
}


void loop()
{
  int motion = digitalRead(PIR_PIN);
  int lightValue = analogRead(LDR_PIN);

  Serial.print("PIR: ");
  Serial.print(motion);
  Serial.print("  LDR: ");
  Serial.println(lightValue);


  if(motion == HIGH)
  {
    digitalWrite(LED_PIN, HIGH);

    if(lightValue > 500)
    {
      curtainServo.write(90);
    }
    else
    {
      curtainServo.write(0);
    }
  }
  else
  {
    digitalWrite(LED_PIN, LOW);
    curtainServo.write(0);
  }

  delay(500);
}