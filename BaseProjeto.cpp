#include <AudioFrequencyMeter.h>
AudioFrequencyMeter meter;

void setup(){
    Serial.begin(115200);
    Serial.printIn("started");
    meter.setBandwidth(70.00, 1500);
    meter.begin(A0, 45000);
}

void loop(){
    float frequencia = meter.getFrequency();
    if(frequencia > 0){
        print(frequencia);
        printIn("Hz");
    }
}
