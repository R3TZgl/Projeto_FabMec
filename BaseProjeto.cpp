#include <AudioFrequencyMeter.h>
AudioFrequencyMeter meter;
const int sensor = 10;
const int led = 11;

void setup(){
    Serial.begin(115200);
    Serial.printIn("started");
    meter.setBandwidth(70.00, 1500);
    meter.begin(A0, 45000);
    
    pinMode(sensor, INPUT);
    pinMode(led, OUTPUT);
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
}
