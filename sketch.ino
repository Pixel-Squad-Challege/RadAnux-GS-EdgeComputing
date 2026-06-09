#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o Display LCD no endereço 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Definição dos Pinos
const int potPin = A0;
const int buttonPin = 2;
const int ledGreen = 8;
const int ledRed = 9;

// Variáveis de Controle
bool isTesting = false;
int k_factor_percentage = 0; // Vai de 1 a 10
float k_factor = 0.0;        // Vai de 0.01 a 0.10 (Nivel de Radiação)

void setup() {
  // Configuração dos pinos
  pinMode(buttonPin, INPUT_PULLUP); // Resistor interno ativado
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  // Inicialização do LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Rad Anux System");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  if (!isTesting) {
    // 1. Leitura do Potenciômetro (História de Usuário 01)
    int potValue = analogRead(potPin);
    
    // Mapeia o valor do potenciômetro (0-1023) para a porcentagem de radiação (1-10%)
    k_factor_percentage = map(potValue, 0, 1023, 1, 10);
    k_factor = k_factor_percentage / 100.0;

    // Exibe o Fator de Radiação no LCD
    lcd.setCursor(0, 0);
    lcd.print("Set Radiation:");
    lcd.setCursor(0, 1);
    lcd.print("k = ");
    lcd.print(k_factor);
    lcd.print("   "); // Limpa caracteres fantasmas

    // 2. Aguarda o botão ser pressionado
    if (digitalRead(buttonPin) == LOW) {
      isTesting = true;
      runSimulation();
    }
    delay(100);
  }
}

void runSimulation() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Orbita Iniciada");
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  delay(2000);

  // Variável vital do satélite (Ex: Altitude em km) e seu backup de segurança
  uint16_t flightAltitude = 4500;
  uint16_t backupAltitude = 4500;

  // 3. Simulação de Injeção de Falha (História de Usuário 02)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Radiação em ");
  lcd.print(k_factor_percentage);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Injetando SEU...");
  delay(2000);

  // Causando o BIT-FLIP forçado (Usando operação XOR para inverter bits)
  flightAltitude = flightAltitude ^ 256; 

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ALERTA DE FALHA!");
  lcd.setCursor(0, 1);
  lcd.print("Alt Errada:");
  lcd.print(flightAltitude);
  delay(2500);

  // 4. Mecanismo de Recuperação (História de Usuário 03 e 04)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Auto-Recuperacao");
  delay(1500);

  int score = 100;

  // Se o fator k for maior que 0.07, o sistema simula um colapso que não pode ser recuperado
  if (k_factor > 0.07) {
    digitalWrite(ledRed, HIGH); // Falha Crítica
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CRASH DE SISTEMA");
    lcd.setCursor(0, 1);
    score = 100 - (k_factor_percentage * 10); 
    lcd.print("Score: ");
    lcd.print(score);
    lcd.print("%   ");
  } 
  // Se a radiação for tolerável, o software aciona o redundância
  else {
    flightAltitude = backupAltitude; // Restaura o valor original
    digitalWrite(ledGreen, HIGH);    // Sucesso
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Recuperacao OK");
    lcd.setCursor(0, 1);
    score = 100 - k_factor_percentage;
    lcd.print("Score: ");
    lcd.print(score);
    lcd.print("%   ");
  }

  // Mantém o resultado na tela por 6 segundos antes de reiniciar o painel
  delay(6000); 
  isTesting = false;
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  lcd.clear();
}