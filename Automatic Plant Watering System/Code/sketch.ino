// Automatic Plant Watering System

int soilSensor = A0;
int setting = A1;

int pump = 9;
int led = 8;

void setup()
{
  pinMode(pump, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int soilValue = analogRead(soilSensor);

  int moistureLimit = analogRead(setting);

  Serial.print("Soil: ");
  Serial.print(soilValue);

  Serial.print("  Limit: ");
  Serial.println(moistureLimit);


  if(soilValue < moistureLimit)
  {
    // Soil is dry
    digitalWrite(pump, HIGH);
    digitalWrite(led, HIGH);
  }
  else
  {
    // Soil has enough moisture
    digitalWrite(pump, LOW);
    digitalWrite(led, LOW);
  }

  delay(500);
}