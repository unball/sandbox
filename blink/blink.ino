int pwm = 9;
int stby = 8;
int ain1 = 7;
int ain2 = 6;

void setup(){
  Serial.begin(9600); //baudrate
  
  pinMode(pwm, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
}

int m=0;

void move(int valor){
  
  if(valor>255){
    valor = 255;
  }
  
  else if(valor<0){
    valor = 0;
  } 

  analogWrite(pwm, valor);
  digitalWrite(stby, HIGH);
  digitalWrite(ain1, HIGH);
  digitalWrite(ain2, LOW);
  
}

void loop() {
  
  if(Serial.available()>0){
   m=Serial.parseInt();
   Serial.println(m);
  }

  move(m);
}
