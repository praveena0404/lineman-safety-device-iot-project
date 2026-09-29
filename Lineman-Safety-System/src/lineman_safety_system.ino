#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial gsm(9, 10);  // Arduino RX, TX

LiquidCrystal lcd(8, 13, 12, 11, A4, A5);

const int relayPin = A3;

const String PASSWORD = "1234";
String inputPassword = "";

const char PHONE_NUMBER[] = "+91XXXXXXXXXX";

void sendSMS(String message) {
  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.print("AT+CMGS=\"");
  gsm.print(PHONE_NUMBER);
  gsm.println("\"");
  delay(1000);

  gsm.print(message);
  delay(500);

  gsm.write(26);   // Ctrl+Z
  delay(3000);
}

void showPasswordScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

void setup() {
  pinMode(relayPin, OUTPUT);

  // Relay OFF at startup
  digitalWrite(relayPin, HIGH);

  lcd.begin(16, 2);
  Serial.begin(9600);
  gsm.begin(9600);

  showPasswordScreen();
}

void loop() {
  if (!Serial.available()) {
    return;
  }

  char received = Serial.read();

  // # = Enter / submit password
  if (received == '#') {
    lcd.clear();

    if (inputPassword == PASSWORD) {
      lcd.print("Access Granted!");
      digitalWrite(relayPin, LOW);

      sendSMS("Lineman Safety: Circuit ON - Authorized access.");
      delay(2000);
    } 
    else {
      lcd.print("Wrong Password!");

      sendSMS("Lineman Safety Alert: Unauthorized access attempt.");
      delay(2000);
    }

    inputPassword = "";
    showPasswordScreen();
  }

  // * = Clear password
  else if (received == '*') {
    inputPassword = "";
    showPasswordScreen();
  }

  // Add entered digit/character
  else {
    inputPassword += received;

    lcd.setCursor(0, 1);

    for (unsigned int i = 0; i < inputPassword.length(); i++) {
      lcd.print('*');
    }
  }
}
