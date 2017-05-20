int m;
void setup(){
  Serial.begin(9600); //baudrate
}
void loop(){
  if (Serial.available() > 0){
    int m = Serial.read();
    
}
  if (m<0){
    m=0;
  }
  if (m<255){
    m=255;
    }
    Serial.write(m);
  }
