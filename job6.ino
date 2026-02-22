int digitalinput = 13;   // IR sensor output pin
int inputVal = 1;        // To store IR sensor value
int buzzer = 9;         // Buzzer pin
int led = 11;             // LED pin

void setup()
{
  Serial.begin(9600);      // Serial Communication
  pinMode(digitalinput, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
}

void loop()
{
  inputVal = digitalRead(digitalinput);  // Read IR sensor

  Serial.print("Input Value: ");
  Serial.println(inputVal);

  if(inputVal == 0)  // Object detected
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    delay(200);

    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    delay(100);
  }
  else  // No object detected
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    delay(200);
  }
}

