#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

// =======================
// CONFIGURAÇÕES DO SISTEMA
// =======================

// UUIDs personalizados para o serviço BLE
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

// Pinos dos LEDs de controle
const int LED_PINS[3] = {23, 5, 33};  // LED vermelho, verde e amarelo
#define LED_STATUS 2                   // LED onboard (pisca quando conectado)

BLECharacteristic *pCharacteristic;
bool deviceConnected = false;

// =======================
// CALLBACKS BLE
// =======================

// Gerencia conexões BLE
class ServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) override {
    deviceConnected = true;
    Serial.println("✅ Cliente conectado!");
  }

  void onDisconnect(BLEServer* pServer) override {
    deviceConnected = false;
    Serial.println("⚠️ Cliente desconectado!");
    BLEDevice::startAdvertising();  // volta a anunciar
    Serial.println("📡 Advertising reiniciado...");
  }
};

// Recebe comandos BLE
class CharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) override {
    std::string valor = pCharacteristic->getValue();

    if (valor.empty()) return;

    Serial.print("📥 Comando recebido: ");
    Serial.println(valor.c_str());

    // Formato esperado: "L1", "D2", etc
    if (valor.length() >= 2) {
      char comando = valor[0];
      int ledNum = valor[1] - '0';  // Converte o segundo caractere em número

      if (ledNum >= 1 && ledNum <= 3) {
        int pino = LED_PINS[ledNum - 1];
        if (comando == 'L' || comando == 'l') {
          digitalWrite(pino, HIGH);
          Serial.printf("💡 LED %d LIGADO\n", ledNum);
        } else if (comando == 'D' || comando == 'd') {
          digitalWrite(pino, LOW);
          Serial.printf("💤 LED %d DESLIGADO\n", ledNum);
        }
      }
    }

    // Comandos especiais
    if (valor == "ALL_ON") {
      for (int i = 0; i < 3; i++) digitalWrite(LED_PINS[i], HIGH);
      Serial.println("💡 Todos os LEDs LIGADOS");
    }
    else if (valor == "ALL_OFF") {
      for (int i = 0; i < 3; i++) digitalWrite(LED_PINS[i], LOW);
      Serial.println("💤 Todos os LEDs DESLIGADOS");
    }
  }
};

// =======================
// CONFIGURAÇÃO INICIAL
// =======================
void setup() {
  Serial.begin(115200);
  Serial.println("\n🚀 Iniciando sistema de controle industrial BLE...");

  // Configura LEDs
  for (int i = 0; i < 3; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
  pinMode(LED_STATUS, OUTPUT);
  digitalWrite(LED_STATUS, LOW);

  // Inicializa BLE
  BLEDevice::init("Industria_LEDs");

  // Cria servidor e callbacks
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  // Cria serviço e característica
  BLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
    CHARACTERISTIC_UUID,
    BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_WRITE
  );

  pCharacteristic->setCallbacks(new CharacteristicCallbacks());
  pCharacteristic->setValue("Sistema pronto");

  // Inicia serviço e advertising
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();

  Serial.println("=================================");
  Serial.println("✅ Sistema BLE pronto!");
  Serial.println("📡 Nome do dispositivo: Industria_LEDs");
  Serial.println("💬 Aguardando conexão...");
  Serial.println("=================================");
}

// =======================
// LOOP PRINCIPAL
// =======================
void loop() {
  // Pisca o LED onboard enquanto conectado
  if (deviceConnected) {
    digitalWrite(LED_STATUS, HIGH);
    delay(150);
    digitalWrite(LED_STATUS, LOW);
    delay(850);
  } else {
    digitalWrite(LED_STATUS, LOW);
    delay(100);
  }
}
