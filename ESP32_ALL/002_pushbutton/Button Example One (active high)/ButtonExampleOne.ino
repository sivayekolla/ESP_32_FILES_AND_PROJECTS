const int buttonPin = 8;
int oldValue = LOW; 

void setup() 
{
  Serial.begin(115200);
  Serial.println("Press the button.");
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  // Read the value of pin 8.
  int newValue = digitalRead(buttonPin);
  if(newValue != oldValue)
  {
    if(newValue == HIGH)
    {
      Serial.println("The button is pressed.");
    }
    else
    {
      Serial.println("The button is released.");
    }
    oldValue = newValue;
  }
  delay(100);
}
