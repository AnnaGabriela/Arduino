/***** MODULO 2 *****/

const int Buzzer = 12;
const int LM35 = 0;
const int LED[] = {2,3,4,5,6,7,8,9,10,11};
float temperatura = 0;
int ADClido = 0;


void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(Buzzer, OUTPUT);
  for (int x=0; x<10; x++) {
    pinMode(LED[x], OUTPUT);
  }
  

}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  Serial.println(temperatura);
  delay(3000);
  if (temperatura > 23.00) {
    digitalWrite(LED[0], HIGH);
  } else {
    digitalWrite(LED[0], LOW);
  }
  
  if (temperatura > 24.00) {
    digitalWrite(LED[1], HIGH);
  } else {
    digitalWrite(LED[1], LOW);
  }
  
  if (temperatura > 24.50) {
    digitalWrite(LED[2], HIGH);
  } else {
    digitalWrite(LED[2], LOW);
  }
  
  if (temperatura > 25.00) {
    digitalWrite(LED[3], HIGH);
  } else {
    digitalWrite(LED[3], LOW);
  }
 
  if (temperatura > 25.50) {
    digitalWrite(LED[4], HIGH);
  } else {
    digitalWrite(LED[4], LOW);
  }

   if (temperatura > 26.00) {
    digitalWrite(LED[5], HIGH);
  } else {
    digitalWrite(LED[5], LOW);
  }

  if (temperatura > 26.50) {
    digitalWrite(LED[6], HIGH);
  } else {
    digitalWrite(LED[6], LOW);
  }

  if (temperatura > 27.00) {
    digitalWrite(LED[7], HIGH);
  } else {
    digitalWrite(LED[7], LOW);
  }

  if (temperatura > 27.50) {
    digitalWrite(LED[8], HIGH);
  } else {
    digitalWrite(LED[8], LOW);
  }

  if (temperatura > 28.00) {
    digitalWrite(LED[9], HIGH);
    digitalWrite(Buzzer,HIGH);
  } else {
    digitalWrite(LED[9], LOW);
    digitalWrite(Buzzer,LOW);
  }
  
}
