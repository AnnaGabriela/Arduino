#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal lcd (7, 6, 5, 4, 3, 2);
int ledGreen = A0;
int ledRed = A1;
int Buzzer = A2;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode (ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  inicio();
}

void loop() {
  // Procura novos cartões
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Seleciona um dos cartoes
  if (mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID da tag :");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem: ");
  conteudo.toUpperCase();
  if (conteudo.substring(1) == "27 7C F9 55")
  {
    Serial.println("Ola Anna");
    Serial.println();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Ola, Anna!   ");
    lcd.setCursor(0, 1);
    lcd.print("Acesso liberado!");
    digitalWrite(ledGreen, HIGH);
    tone(Buzzer,1500);   
    delay(500);
    noTone(Buzzer);
    delay(2000);
    inicio();
  } else {
    Serial.println("Acesso Negado!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Acesso Negado! ");
    digitalWrite(ledRed, HIGH);
    tone(Buzzer,2000);   
    delay(500);
    noTone(Buzzer);
    delay(2000);
    inicio();
  }

}

void inicio() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Aproxime o seu");
  lcd.setCursor(0, 1);
  lcd.print("cartao do leitor");
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
}

