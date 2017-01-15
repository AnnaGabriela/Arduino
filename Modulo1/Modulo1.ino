/****** MODULO 1 ********/

const int Led = 6;
const int LDR = 0;
int ValorLido = 0;
int pwm = 0;

void setup() {
  pinMode(Led, OUTPUT);
}

void loop() {
    ValorLido = analogRead(LDR);

    if (ValorLido < 50) {
      analogWrite(Led, pwm);
      pwm++;
      delay(100);
    } else {
      digitalWrite(Led, LOW);
      pwm = 0;
    }

    if (pwm > 255) {
      pwm = 255;
    }
}
