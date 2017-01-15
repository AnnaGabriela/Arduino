#include <LiquidCrystal.h>

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);
String caracter;

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
}

void digite() {
  lcd.print("Digite a senha:");
  lcd.setCursor(0,0);
}

void loop() {
  digite();
  if (Serial.available() > 0) {
    caracter = Serial.readString();
    if (caracter == "anna") {
      lcd.print(" Bem vinda, Anna ");
      lcd.print("Acesso Liberado");
      delay(4000);
      lcd.clear();
      digite();
    } else {
      lcd.print("  Acesso Negado  ");
      delay(4000);
      digite();
    }
  }

}
