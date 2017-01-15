/****** MODULO 1 ********/

const int ledVerm = 13;
const int ledAma = 12;
const int ledVerd = 11;
const int BtnVerm = 3;
const int BtnAma = 2;
const int BtnVerd = 4;
const int Buzzer = 10;
int EstadoBtnVerm = 0;
int EstadoBtnAma = 0;
int EstadoBtnVerd = 0;
int Tom = 0;

void setup() {
  pinMode(ledVerm, OUTPUT);
  pinMode(BtnVerm, INPUT);
  pinMode(ledAma, OUTPUT);
  pinMode(BtnAma, INPUT);
  pinMode(ledVerd, OUTPUT);
  pinMode(BtnVerd, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  EstadoBtnVerm = digitalRead(BtnVerm);
  EstadoBtnAma = digitalRead(BtnAma);
  EstadoBtnVerd = digitalRead(BtnVerd);
  
  // BOTAO VERMELHO
  if (EstadoBtnVerm && !EstadoBtnAma && !EstadoBtnVerd) {
    Tom = 100;
    digitalWrite(ledVerm, HIGH);
  }
  // BOTAO AMARELO
  if (EstadoBtnAma && !EstadoBtnVerm && !EstadoBtnVerd) {
    Tom = 200;
    digitalWrite(ledAma, HIGH);
  }
  // BOTAO VERDE
  if (EstadoBtnVerd && !EstadoBtnAma && !EstadoBtnVerm) {
    Tom = 300;
    digitalWrite(ledVerd, HIGH);
  }
  // BUZZER
  if (Tom > 0) {
    digitalWrite(Buzzer, HIGH);
    delayMicroseconds(Tom);
    digitalWrite(Buzzer, LOW);
    delayMicroseconds(Tom);
    Tom = 0;
    digitalWrite(ledVerm, LOW);
    digitalWrite(ledVerd, LOW);
    digitalWrite(ledAma, LOW);
  }
}
