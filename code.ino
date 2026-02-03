int trig_pin = 11;
int echo_pin = 10;
int led1 = 6, led2 = 5, led3 = 4;
int pulse_signal;
int buzzer = 12;
float flood_raise=0;
float flood_depth;

void setup() 
{
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  pulse_signal = pulseIn(echo_pin, HIGH);
  flood_raise = pulse_signal * 0.017;
  flood_depth = 24.3 - flood_raise;
  Serial.print("flood raise from the ground is ");
  Serial.print(flood_raise);
  Serial.println(" cm");
  Serial.print("flood depth is ");
  Serial.print(flood_depth);
  Serial.println(" cm");
  Serial.println("");
  delay(2000);
  
  if(flood_depth <= 6)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
    else if(flood_depth > 6 && flood_depth <= 12)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
    else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(buzzer, HIGH);
  }
}
