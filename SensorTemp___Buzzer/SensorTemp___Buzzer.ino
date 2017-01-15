/***** MODULO 2 *****/

const int Buzzer = 12;
const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;


void setup() {
  analogReference(INTERNAL);
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  if (temperatura > 25) {
    digitalWrite(Buzzer, HIGH);
  } else {
    digitalWrite(Buzzer, LOW);
  }
}
