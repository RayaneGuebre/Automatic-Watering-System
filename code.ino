
#define potentiometerPin A1
#define uS_TO_S_FACTOR 1000000ULL 
#define TIME_TO_SLEEP  43200

const int freq = 5000;   
const int pumpChannel = 0;
const int resolution = 8;
const int pumpPin = D2;

void setup() {

    pinMode(potentiometerPin, INPUT);
    pinMode(pumpPin, OUTPUT);

    ledcSetup(pumpChannel,freq,resolution);
    ledcAttachPin(pumpPin,pumpChannel);    

   

}

void loop() {
    int potVal = analogRead(potentiometerPin);
    int pwrVal = map(potVal, 0, 4095, 0, 255);



    ledcWrite(pumpChannel, pwrVal);
    delay(8000);
    ledcWrite(pumpChannel, 0);
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);  
    esp_deep_sleep_start(); 


    
}
