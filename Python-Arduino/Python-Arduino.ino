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
      Serial.println(serialData);
      Serial.print(serialInt);
    
      if(serialInt == 0){
        digitalWrite(pin,LOW);
        digitalWrite(pint,HIGH);
        }
        
      else if(serialInt == 1){
        digitalWrite(pin,HIGH);
        digitalWrite(pint,LOW);
        }
        
      else if(serialInt == 10){
        digitalWrite(pin,HIGH);
        digitalWrite(pint,HIGH);
        }

      else if(serialInt == 11){
        digitalWrite(pin,LOW);
        digitalWrite(pint,HIGH);
        }
        
      
  }
  }
  
