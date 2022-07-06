#include <AudioFrequencyMeter.h>
#include <Servo.h>
#include <LiquidCrystal.h>


AudioFrequencyMeter meter;

const int sensor = 12;
const int led = 13;

Servo servo;
int angulo = 0;

const int e = 330;
const int b = 247;
const int g = 196;
const int d = 146;
const int a = 110;
const int E = 82;

const int btn1 = 2;
const int btn2 = 3;
const int btn3 = 4;
int num = 1;

LiquidCrystal lcd(9, 10, A2, A3, A4 ,A5);


void nota(nota, frequencia, som, angulo){
    while(!(nota - 2) < frequencia < (nota + 2)){
        if(som > 300){
            while(frequencia < nota - 2){
                // da pra simplificar só com o if
                angulo += 1;
                servo.write(angulo);
            }    
            while(frequência > nota + 2){
                angulo -= 1;
                servo.write(angulo);
            }
        }
    }
    return angulo;
}



void setup(){
    Serial.begin(115200);
    Serial.printIn("started");
    meter.setBandwidth(70.00, 1500);
    meter.begin(A0, 45000);
    
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
    
    servo.attach(11);
    servo.write(0);
    
    pinMode(btn1, INPUT);
    pinMode(btn2, INPUT);
    pinMode(btn3, INPUT);
    
    lcd.begin(16, 2);
    lcd.setUp(0, 0);
    lcd.print("Teste");
}


void loop(){
    if(digitalRead(btn1) == HIGH && num > 1){
        num -= 1;
    }
    else if(digitalRead(btn2) == HIGH && num < 6){
        num +- 1;
    }
    
    if(num == 1){
        escolha = e;
    }
    else if(num == 2){
        escolha = b;
    }
    else if(num == 3){
        escolha = g;
    }
    else if(num == 4){
        escolha = d;
    }
    else if(num == 5){
        escolha = a;
    }else{
        escolha = E;
    }
    
    float frequencia = meter.getFrequency();
    if(frequencia > 0){
        print(frequencia);
        printIn("Hz");
    }
    
    int som = analogRead(sensor);
    Serial.printIn(som);
    delay(50);
    
    if(som > 300){
        digitalWrite(led, HIGH);
        delay(50);
    }else{
        digitalWrite(led, LOW);
    }
    
    if(btn3 == HIGH){
        angulo = nota(escolha, frequencia, som, angulo);
        delay(1000);
    }
}
