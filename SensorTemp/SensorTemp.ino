/***** MODULO 2 *****/

const int LM35 = 0;
float temperatura = 0;
int ADClido = 0;

void setup() {
  Serial.begin(9600);
  analogReference(INTERNAL);

}

void loop() {
  ADClido = analogRead(LM35);
  temperatura = ADClido * 0.1075268817;
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  delay(1000);
}
