#include<cvzone.h>

SerialData serialData(1,1); 
int valsRec[2];

#define alert 4
#define flag 2 
#define doorLock 5


void setup() {
  // put your setup code here, to run once:

  //Serial.begin(9600); 
  serialData.begin(9600); 
  pinMode(alert, OUTPUT);
  pinMode(doorLock, OUTPUT); 
  pinMode(flag, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

  serialData.Get(valsRec);

  if (valsRec[0]==1) 
   {

    digitalWrite(doorLock, HIGH);
    delay(3000);
    digitalWrite(doorLock, LOW);
    valsRec[0]=0;
   }
    
  else if(valsRec[0]==2) {
    
        digitalWrite(alert,HIGH);
        delay(300);
        digitalWrite(alert,LOW);
        delay(300);
        digitalWrite(alert,HIGH);
        delay(300);
        digitalWrite(alert,LOW);
        valsRec[0]=0;
    
    }  
  
    
  if (digitalRead(flag)){

        digitalWrite(doorLock, HIGH);
        delay(3000);
        digitalWrite(doorLock, LOW);
  }

}
