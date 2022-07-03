#include <AudioFrequencyMeter.h>
#include <Servo.h>


AudioFrequencyMeter meter;

const int sensor = 10;
const int led = 11;

Servo servo;
int angulo = 0;

const int e = 330;
const int b = 247;
const int g = 196;
const int d = 146;
const int a = 110;
const int E = 82;

void nota(nota, frequencia, som, angulo){
    while(!(nota - 2) < frequencia < (nota + 2){
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
    
    servo.attach(12);
}


void loop(){
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
        delay(200);
    }else{
        digitalWrite(led, LOW);
    }
    
    angulo = nota(e, frequencia, som, angulo);
}
