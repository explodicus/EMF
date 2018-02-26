int senseLimit = 15; // the sensibility scale
int antenaPin = 5;
int val = 0;  // value of the antena
int LED1 = 2; 
int LED2 = 3;
int LED3 = 4; 
int LED4 = 5; 
int LED5 = 6; 
int LED6 = 7; 
int LED7 = 8;
int readings[15]; // get a more acurate rezult by using more data 
int index = 0; 
int total = 0; 
int average = 0;

void setup() 
{
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  for (int i = 0; i < 15; i++) 
    readings[i] = 0;

}

void loop() 
{
  val = analogRead(antenaPin);
  if(val >= 1)
  {
    val = constrain(val, 1, senseLimit); 
    val = map(val, 1, senseLimit, 1, 1023);
    total -= readings[index]; 
    readings[index] = val; 
    total += readings[index]; 
    index++;
    if (index >= 15) index = 0;
    average = total / 15;
    if (average > 100)
      digitalWrite(LED1, HIGH); 
    else 
      digitalWrite(LED1, LOW);
    if (average > 200)
      digitalWrite(LED2, HIGH); 
    else 
      digitalWrite(LED2, LOW);
    if (average > 300)
      digitalWrite(LED3, HIGH); 
    else 
      digitalWrite(LED3, LOW);
    if (average > 400)
      digitalWrite(LED4, HIGH); 
    else 
      digitalWrite(LED4, LOW);
    if (average > 500)
      digitalWrite(LED5, HIGH); 
    else 
      digitalWrite(LED5, LOW);
    if (average > 600)
      digitalWrite(LED6, HIGH); 
    else 
      digitalWrite(LED6, LOW);
    if (average > 700)
      digitalWrite(LED7, HIGH); 
    else 
      digitalWrite(LED7, LOW);
    
    Serial.println(val);
  }
}
