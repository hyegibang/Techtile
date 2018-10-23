char serialData ; 
int pin = 13; 
int pint = 12;
int serialInt;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(pint, OUTPUT);
}
void loop() {
  if(Serial.available() > 0){
      serialData = Serial.read();
      serialInt = serialData;

      switch(serialInt){
        case 0:
          digitalWrite(pin,LOW);
          digitalWrite(pint,HIGH);
          break;
        case 1:
          digitalWrite(pin,HIGH);
          digitalWrite(pint,LOW);
          break;
        case 10:
          digitalWrite(pin,HIGH);
          digitalWrite(pint,LOW);
          break;
        case 11:
          digitalWrite(pin,LOW);
        digitalWrite(pint,HIGH);
       }
     
      
  }
  }
  
