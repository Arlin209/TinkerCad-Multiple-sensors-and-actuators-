const int alcoholSensor = A0;

const int motorEnable = 5;
const int motorIN1 = 6;
const int motorIN2 = 7;

const int greenLED = 8;
const int redLED = 9;
const int buzzer = 10;

int threshold = 500;

void setup()
{
  pinMode(motorEnable, OUTPUT);
  pinMode(motorIN1, OUTPUT);
  pinMode(motorIN2, OUTPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int alcoholValue = analogRead(alcoholSensor);

  Serial.println(alcoholValue);

  if (alcoholValue > threshold)
  {
    // Alcohol detected - Engine locked
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    digitalWrite(buzzer, HIGH);

    digitalWrite(motorIN1, LOW);
    digitalWrite(motorIN2, LOW);
    analogWrite(motorEnable, 0);
  }
  else
  {
    // Safe - Engine runs
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    digitalWrite(buzzer, LOW);

    digitalWrite(motorIN1, HIGH);
    digitalWrite(motorIN2, LOW);
    analogWrite(motorEnable, 255);
  }

  delay(300);
}