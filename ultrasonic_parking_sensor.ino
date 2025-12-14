const int green = 2;
const int yellow = 3;
const int red = 4;
const int buzzer = 5;
const int trigPin = 9;
const int echoPin = 10;
const int buttonPin = 7;

bool systemOn = false;
int distance;
long duration;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  if(digitalRead(buttonPin) == LOW){
    delay(50);
    if (digitalRead(buttonPin) == LOW){
      systemOn = !systemOn;
      while(digitalRead(buttonPin) == LOW){}
    }
  }

  if(systemOn == true){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print("Distancia: ");
    Serial.println(distance);

    if (distance > 100){
      digitalWrite(green, HIGH);
      digitalWrite(yellow, LOW);
      digitalWrite(red, LOW);
      noTone(buzzer);
    }
    else if (distance > 30){
      digitalWrite(green, LOW);
      digitalWrite(yellow, HIGH);
      digitalWrite(red, LOW);
      tone(buzzer, 3000);
    }
    else{
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(red, HIGH);
      tone(buzzer, 5000);
    }
  }
  else{
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    noTone(buzzer);
  }
}