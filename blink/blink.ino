int led=17;

void setup() {
  pinMode(led,OUTPUT);

}

void loop() {
  
  digitalWrite(led,HIGH);
  delay(5000);
  digitalWrite(led,LOW);
  delay(5000);

}
