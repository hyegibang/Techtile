char serialData; 
int pin = 13; 
int pint = 12;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  pinMode(pint, OUTPUT);
}
void loop() {
  if(Serial.available() > 0){ 
    serialData = Serial.read();
    
      if(serialData == '1'){
        digitalWrite(pin,LOW);
        digitalWrite(pint,HIGH);
        }
      else if(serialData == '0'){
        digitalWrite(pin,HIGH);
        digitalWrite(pint,LOW);
        }
  
}
}
