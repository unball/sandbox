int pwm = 9;
int stby = 8;
int ain1 = 7;
int ain2 = 6;
int ChA_enc=14;
int ChB_enc=16;

void setup(){
  Serial.begin(9600); //baudrate
  
  pinMode(pwm, OUTPUT);
  pinMode(stby, OUTPUT);
  pinMode(ain1, OUTPUT);
  pinMode(ain2, OUTPUT);
  pinMode(ChA_enc, INPUT);
  pinMode(ChB_enc, INPUT);
}

int m=0,a=0,aux_a=0;
int previousA, previousB;
int nextA, nextB;
int contador;

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

  //Serial.println(digitalRead(ChA_enc));
  
  if(Serial.available()>0){
   m=Serial.parseInt();

   m;

   Serial.println(m);
  }
    
    nextA=digitalRead(ChA_enc);
    nextB=digitalRead(ChB_enc);

    /*Serial.print(previousA);
    Serial.println(nextA);
    Serial.print(previousA);
    Serial.println(nextB);*/

  if ((previousA!=nextA)||(previousB!=nextB)){
    if((nextA-previousA>0)&&(previousB==0)){
      contador++;
      Serial.println(contador);
    }

    if((previousA==1)&&(nextB-previousB>0)){
      contador++;
      Serial.println(contador);
    }

    if((nextA-previousA<0)&&(previousB==1)){
      contador++;
      Serial.println(contador);
    }

    if((nextA==0)&&(nextB-previousB>0)){
      contador++;
      Serial.println(contador);
    }
//-------------------------------------------------
    if((previousA==0)&&(nextB-previousB>0)){
      contador--;
      Serial.println(contador);
    }

    if((nextA-previousA>0)&&(previousB==1)){
      contador--;
      Serial.println(contador);
    }

    if((previousA==1)&&(nextB-previousB<0)){
      contador--;
      Serial.println(contador);
    }

    if((nextA-previousA<0)&&(previousB==0)){
      contador--;
      Serial.println(contador);
    }
    
  }
    
  previousA=nextA;
  previousB=nextB;
 
  
  move(m);
}
