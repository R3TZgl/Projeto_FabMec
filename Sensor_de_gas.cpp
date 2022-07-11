int sensorGas = A5;
int valorSensor = 0;
int ledAzul = 3;
int ledVermelho = 2;
int buzzer = 4;
int nota1 = 300;
int nota2 = 600;
int transistor = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorGas, INPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(transistor, OUTPUT);
  }

void loop()
{
  valorSensor = analogRead(sensorGas);
  digitalWrite(ledAzul, HIGH);
  
  if(valorSensor >= 150){
    while(valorSensor >= 150){
      	valorSensor = analogRead(sensorGas);
      	
      	digitalWrite(transistor, HIGH);
      	digitalWrite(ledVermelho, HIGH);
    	tone(buzzer, nota1);
      	delay(200);
      	
      	digitalWrite(ledVermelho, LOW);
      	tone(buzzer, nota2);
      	delay(200);
      
    }
  }
  
  noTone(buzzer);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(transistor, LOW);
  
  delay(1000);
  digitalWrite(ledAzul, LOW);
  delay(1000);
}