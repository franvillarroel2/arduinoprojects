#include <LiquidCrystal.h>

// Configura el sensor de proximidad ultrasónico HC-SR04
const int trigPin = 6;
const int echoPin = 7;

// Inicializa el objeto de pantalla LCD
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  // Inicializa la pantalla LCD
  lcd.begin(16, 2);
  
  // Inicializa el sensor de proximidad
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Dispara un pulso ultrasónico para medir la distancia
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee la duración del eco
  long duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en metros
  float distance = duration * 0.034 / 2;

  // Limpia la pantalla LCD
  lcd.clear();
  
  // Muestra la distancia en la pantalla LCD
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print(distance);
  lcd.print(" m");

  // Espera un breve periodo de tiempo antes de realizar la próxima lectura
  delay(1000);
}