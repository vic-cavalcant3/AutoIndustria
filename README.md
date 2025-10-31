# 🚀 Controle Industrial BLE com ESP32

Projeto desenvolvido com **ESP32** e **Arduino Framework**, utilizando **Bluetooth Low Energy (BLE)** para o **controle remoto de LEDs industriais**.  
A comunicação BLE permite que o sistema receba comandos via smartphone ou outro dispositivo BLE, ligando e desligando LEDs de forma individual ou em grupo.

---

## ⚙️ Funcionalidades

- 📡 Conexão Bluetooth Low Energy (BLE)
- 💡 Controle de 3 LEDs (vermelho, verde e amarelo)
- 🧠 Comandos individuais (`L1`, `D2`, etc.)
- 🔁 Comandos gerais (`ALL_ON`, `ALL_OFF`)
- 🔔 Feedback visual via LED onboard
- 🔄 Reconexão automática após desconexão BLE


---

## 🖥️ Como Usar

### 1. Abra o projeto no VS Code + PlatformIO
### 2. Conecte o ESP32 via USB
### 3. Configure a porta no `platformio.ini`
```ini
upload_port = COM9
```
### 4. Faça o upload para a placa
```bash
pio run --target upload
```
### 5. Conecte-se ao dispositivo BLE
- Nome do dispositivo: **Industria_LEDs**
- Use um web como o index.html na raiz.

### 6. Envie comandos pelo app BLE

| Comando    | Ação                          |
|------------|-------------------------------|
| `L1`       | Liga o LED 1 (vermelho)       |
| `D1`       | Desliga o LED 1 (vermelho)    |
| `L2`       | Liga o LED 2 (verde)          |
| `D2`       | Desliga o LED 2 (verde)       |
| `L3`       | Liga o LED 3 (amarelo)        |
| `D3`       | Desliga o LED 3 (amarelo)     |
| `ALL_ON`   | Liga todos os LEDs            |
| `ALL_OFF`  | Desliga todos os LEDs         |

---

## 🔌 Diagrama de Conexão

| Componente      | Pino ESP32 |
|-----------------|------------|
| LED Vermelho    | GPIO 13    |
| LED Verde       | GPIO 12    |
| LED Amarelo     | GPIO 14    |
| LED Onboard     | GPIO 2     |

---

## 🧠 Tecnologias Utilizadas

- **ESP32 DevKit**
- **Arduino Framework**
- **Bluetooth Low Energy (BLE)**
- **PlatformIO**

---

## 📸 Demonstração

![WhatsApp Image 2025-10-31 at 16 26 30](https://github.com/user-attachments/assets/c47609f8-3253-401b-b6aa-843b46b00008)



## 🧑‍💻 Autor

**Victor Cavalcante**
Desenvolvimento de Sistemas – SENAI

💬 *"Tecnologia não é só código — é criatividade em ação."*

---
