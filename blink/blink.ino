
int m;
int pwm = 9;
int stby = 8;
int ain1 = 7;
int ain2 = 6;



void move(int valor){
  pinMode(pwm, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  
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

void setup(){
  Serial.begin(9600); //baudrate
}


void loop() {
  Serial.println("a");

  if (Serial.available() > 0){
    m = Serial.read();
    }
   
  if (m<0){
    m=0;
  }
  if (m>255){
    m=255;
  }
  
  Serial.println(m);
  move(m);

}
 

