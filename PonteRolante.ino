

int potpin1 = A0;  // entrada analógico 1 // analog inputs
int potpin2 = A1;  // entrada analógico 2
int potpin3 = A2;  //entrada analógico 3

int val, val2, val3, valA, valB, valC, amp1, amp2;    // variáveis a serem lidas os valores nas entradas analógicas // variables to be readen 
float converte;
int conte=0;
int in1A = 7;     //comando sentido do motorA entrada in1 // commands to turn in the both senses 
int enA = 6;      //habilita motor-A e B
int in2A = 8;     //comando sentido do motorA entrada in2


int in1B = 4;     //comando sentido do motorB in1B
int enB = 3;      //habilita motor-C
int in2B = 2;     //comando sentido do motorB in2B

int in1C = 9;     //comando motorD in1D
int enC = 11;     //habilita motorD
int in2C = 10;    //comando motorD

int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(in1C, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(in2C, OUTPUT);
}

void loop() {

  conte = conte + 1;

  val = analogRead(potpin1);            //lê o valor do potenciômetro 1 (valor entre 0 e 1023) // reads the value of potentiometer 1, 2 and 3
 delay(3);  
  val2 = analogRead(potpin2);            //lê o valor do potenciômetro 2
delay(3);
  val3 = analogRead(potpin3);           //lê o valor do potenciômetro 3
delay(3);

    //*****************MOTOR A e B************************************// engines A and B
 if(val <=470)
  {
    
 
  valA = map(val, 1023, 0, 0, 255);  //the rest is pretty self-explanatory
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
    analogWrite(enA,valA);
    
  }
 
if(val >=530)
  {
  valA = map(val, 0, 1023, 0, 255);  
  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);
  analogWrite(enA,valA);
  
  }
  
 if(val>=480 && val<=520)
  {
   digitalWrite(in1A, LOW);
   digitalWrite(in2A, LOW);
   digitalWrite(enA, HIGH);  
  }

    //*****************MOTOR-C************************************
 if(val2 <=470)
  {

  valB = map(val2, 1023, 0, 0, 255);
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
    analogWrite(enB,valB);
    
  }
 if(val2 >=530)
  {
  valB = map(val2, 0, 1023, 0, 255);
  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);
  analogWrite(enB,valB);
  
  }
 if(val2>=480 && val2<=520)
  {
   digitalWrite(in1B, LOW);
   digitalWrite(in2B, LOW);
   digitalWrite(enB, HIGH);  
  }

    //**********Motor-D************
 if(val3 <=470)
  {

  valC = map(val3, 1023, 0, 0, 255);
    digitalWrite(in1C, HIGH);
    digitalWrite(in2C, LOW);
    analogWrite(enC,valC);
  
  }
if(val3 >=530)
  {
  valC = map(val3, 0, 1023, 0, 255);
  digitalWrite(in1C, LOW);
  digitalWrite(in2C, HIGH);
  analogWrite(enC,valC);
  
  }
 if(val3>=480 && val3<=520)
  {
   digitalWrite(in1C, LOW);
   digitalWrite(in2C, LOW);
   digitalWrite(enC, HIGH);  
  }
  
  delay(10);                           
}
