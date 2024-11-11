#include <DHT.h>

#define pinoDHT 23     // Pino DHT22
#define modelo DHT22
#define trigPin 5      // Pino Trig do HC-SR04
#define echoPin 18     // Pino Echo do HC-SR04
#define pinLED_HC 16   // Pino LED do HC-SR04
#define pinPIR 17     // Pino PIR
#define pinLED_PIR 22 // Pino LED PIR
#define ldrPin 34     // Pino LDR
#define pin_Irrig 21 // Pino de controle da bomba de irrigação


DHT dht(pinoDHT, modelo);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinLED_HC, OUTPUT);
  pinMode(pinPIR, INPUT);
  pinMode(pinLED_PIR, OUTPUT);
}

void loop() {
   int time_irrig;     // Variável para o tempo de irrigação em milissegundos

  // Leitura do DHT22
  float ti_ideal = 24.00; // temperatura inicial ideal
  float tf_ideal = 30.00; // temperatura final ideal
  float h = dht.readHumidity();
  //float t = dht.readTemperature();
  float t = 35.00; //teste 02
 
  

  if (isnan(h) || isnan(t)) {
    Serial.println("Falha no DHT!");
  } else {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print("%  Temperatura: ");
    Serial.print(t);
    Serial.println("*C");
  }

  // Controle de irrigação com base na temperatura
  if (t < ti_ideal) {
    Serial.println("Temperatura abaixo do ideal.");
    time_irrig = 1000; // Tempo de irrigação reduzido (1 segundo)
    Serial.println("Tempo de irrigação reduzido 1s");
  } else if (t > tf_ideal) {
    Serial.println("Temperatura acima do ideal.");
    time_irrig = 3000; // Tempo de irrigação mais longo (3 segundos)
    Serial.println("Tempo de irrigação mais longo 3s");
  } else {
    Serial.println("Temperatura ideal. Mantendo irrigação estável.");
    time_irrig = 2000; // Tempo de irrigação moderado (2 segundos)
  }

  // Acionamento da bomba de irrigação
  digitalWrite(pin_Irrig, HIGH); // Liga a bomba
  delay(time_irrig);        // Mantém a bomba ligada pelo tempo determinado
  digitalWrite(pin_Irrig, LOW);  // Desliga a bomba


  // Leitura do HC-SR04
  long duration;
  int distance;
  float reservatorio = 800.00; // nivel do reservatorio em cm
   

  // Envia um pulso de 10us para o Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Calcula o tempo de duração do pulso de retorno no Echo
  duration = pulseIn(echoPin, HIGH);
  
  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2;

  // Calculo o nivel do reservatorio preenchido
  //float nivel = reservatorio - distance;
  float nivel = 95.00; // teste 03
 
  // Calcula a porcentagem do reservatório preenchido
  float porcentagem = nivel / reservatorio * 100;
  

   // Imprime o nivel do reservatorio
  Serial.print("Reservatório Nível: ");
  Serial.print(nivel);
  Serial.print("cm");
  Serial.print("  Capacidade:  ");
  Serial.print(porcentagem);
  Serial.println("% ");
  
 // Verifica se o nível está abaixo de 25% e emite alerta
 // e desliga o sistema de irrigação
  if (porcentagem < 25) {
    Serial.println("Alerta: Nível de risco! ");
    Serial.println("Alerta: Sistema de Irrigação DESLIGADO!!! ");
    digitalWrite(pinLED_HC, HIGH);// Liga o LED
    digitalWrite(pin_Irrig, LOW);  // Desliga a bomba de irrigacao

  } else {
    Serial.println("Sistema de Irrigação LIGADO.");
    digitalWrite(pinLED_HC, LOW); // Desliga o LED
    digitalWrite(pin_Irrig, HIGH); // Liga a bomba de irrigacao

  }

 

  // Leitura do PIR
  //int pirState = digitalRead(pinPIR); // Lê o estado do sensor PIR
  int pirState = HIGH; // teste 04
    if (pirState == HIGH) {  // Movimento detectado
        digitalWrite(pinLED_PIR, HIGH);  // Liga o LED
        Serial.println(" ALERTA: Movimento detectado!!!");
    } else {  // Nenhum movimento detectado
        digitalWrite(pinLED_PIR, LOW);   // Desliga o LED
    }

  // Leitura do LDR
  //int ldrValue = analogRead(ldrPin);
  int ldrValue = 350; //teste 05
  Serial.println("");
  Serial.print("Nível de Luz: ");
  Serial.println(ldrValue);

  // Ajuste do tempo de irrigação baseado no nível de luz
  if (ldrValue > 800) {         // Dia ensolarado
    time_irrig = 3000;      // Tempo de irrigação mais longo (3 segundos)
    Serial.print("Ensolarado. Irrigação mais longa = ");
  } else if (ldrValue > 400) {  // Dia nublado
    time_irrig = 2000;      // Tempo de irrigação moderado (2 segundos)
    Serial.print("Nublado. Irrigação moderada = ");
  } else {                      // Pouca luz (amanhecer, entardecer ou noite)
    time_irrig = 1000;      // Tempo de irrigação reduzido (1 segundo)
    Serial.print("Pouca Luz. Irrigação reduzida = ");
  }
  int tempo = time_irrig/1000; // tempo de irrigacao em segundos
  Serial.print(tempo);
  Serial.print("s");


// Acionamento da bomba de irrigação
  digitalWrite(pin_Irrig, HIGH); // Liga a bomba
  delay(time_irrig);        // Mantém a bomba ligada pelo tempo determinado
  digitalWrite(pin_Irrig, LOW);  // Desliga a bomba

 

  delay(3000); // Ajuste o tempo de leitura conforme necessário
}

