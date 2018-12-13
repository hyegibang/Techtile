char select; 
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    select = Serial.read();
    Serial.end(); 
  }
  Serial.print(select); 
}
