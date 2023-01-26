//Sensor
const int relayPin = 12;
const int pirPin1 = 8;
const int pirPin2 = 9;
const int pirPin3 = 10;
const int pirPin4 = 11;

int val1 = 0,val2 = 0, val3 = 0, val4 = 0 ;

//countdown and buzzer
long buzzerFrequency = 1000;
float buzzerDuration = 100;
const int buzzerPin = 6;

//Independant time event
const unsigned long eventTime_PIR1 = 1000; //interval
const unsigned long eventTime_PIR2 = 1000;
const unsigned long eventTime_PIR3 = 1000;
const unsigned long eventTime_PIR4 = 1000;
const unsigned long interval = 1000;

unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;
unsigned long previousTime_3 = 0;
unsigned long previousTime_4 = 0;
unsigned long previousTime = 0;

void setup(){
  Serial.begin(115200);
  pinMode(relayPin,OUTPUT);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(pirPin3, INPUT);
  pinMode(pirPin4, INPUT);
}

void loop(){
  //digital read sensor
   val1 = digitalRead(pirPin1);
   val2 = digitalRead(pirPin2);
   val3 = digitalRead(pirPin3);
   val4 = digitalRead(pirPin4);
  
  // updates frequently
  unsigned long currentTime = millis();
  if(currentTime<=10000){
     if (currentTime-previousTime >= interval){
      tone(buzzerPin,buzzerFrequency,buzzerDuration);
     previousTime = currentTime;  
     }
  } else if (currentTime>=10000){  
      if(val1 == HIGH || val2 == HIGH || val3 == HIGH || val4 == HIGH){
       digitalWrite(relayPin, HIGH);
       Serial.println("Movement! delay 10 second");
       Serial.println("Light off");
       delay(10000);
      }else{
       digitalWrite(relayPin, LOW);
       Serial.println("No Movement");
       Serial.println("Light on");
      } 
    /*//Event 1 stuff
    if (currentTime-previousTime_1 >= eventTime_PIR1){
    Serial.print("PIR 8: ");
    Serial.println(digitalRead(pirPin1));

    //Update timing for next event
    previousTime_1 = currentTime;
    }

    //Event 2 stuff
    if (currentTime-previousTime_2 >= eventTime_PIR2){
    Serial.print("PIR 9: ");
    Serial.println(digitalRead(pirPin2));

    //Update timing for next event
    previousTime_2 = currentTime;
    }

    //Event 3 stuff
    if (currentTime-previousTime_3 >= eventTime_PIR3){
    Serial.print("PIR 10: ");
    Serial.println(digitalRead(pirPin3));

    //Update timing for next event
    previousTime_3 = currentTime;
    }

    //Event 4 stuff
    if (currentTime-previousTime_4 >= eventTime_PIR4){
    Serial.print("PIR 11: ");
    Serial.println(digitalRead(pirPin4));

    //Update timing for next event
    previousTime_4 = currentTime;
    }*/
  }
}
