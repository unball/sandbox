
int m;
char incomingByte;
int pwm = 9;
int stby = 8;
int ain1 = 7;
int ain2 = 6;
int leitorB = 16;
int leitorA = 14;
int pulseB;
int pulseA;
int i = 0;
int Est_PA = 0;
int Est_PB = 0;


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
  pinMode (leitorB, INPUT);
}


void loop() {
  

  if (Serial.available() > 0){
    m = 0;
    while (1){
      incomingByte = Serial.read ();
      if (incomingByte == '\n') break;
      if (incomingByte == -1) continue;
      m *= 10;
      m = ((incomingByte - 48) + m);
    }
     if (m > 255){
        m = 255;
     }
     if (m < 0){
      m = 0;
     }
      /*Serial.println(m);*/   
   }
   
    move(m);
    
    pulseB = digitalRead (leitorB);
    pulseA = digitalRead (leitorA);
    
      if (pulseB > Est_PB){
        if (pulseA){
          i++;
          }
         else{
          i--;
          }
      }
      Est_PB = pulseB;
      Serial.println (i);  
}
 

