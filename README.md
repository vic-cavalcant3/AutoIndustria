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

## 🧩 Estrutura do Projeto
```
📂 ControleBLE_ESP32
 ┣ 📜 main.cpp              → Lógica principal do sistema BLE
 ┗ ⚙️ platformio.ini        → Configuração do ambiente PlatformIO
```

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
- Use um app BLE como [nRF Connect](https://www.nordicsemi.com/Products/Development-tools/nrf-connect-for-mobile)

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

> 📌 *Adicione aqui uma foto ou vídeo do projeto em funcionamento!*

<!-- Exemplo de como adicionar imagem:
![Demonstração do Projeto](./images/demo.gif)
-->

---

## 🧑‍💻 Autor

**Victor Cavalcante** *(morzinho)*  
Desenvolvimento de Sistemas – SENAI

💬 *"Tecnologia não é só código — é criatividade em ação."*

---

## 📝 Licença

Este projeto está sob a licença MIT. Sinta-se livre para usar, modificar e distribuir.

---

## 🤝 Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

1. Fork o projeto
2. Crie uma branch para sua feature (`git checkout -b feature/NovaFuncionalidade`)
3. Commit suas mudanças (`git commit -m 'Adiciona nova funcionalidade'`)
4. Push para a branch (`git push origin feature/NovaFuncionalidade`)
5. Abra um Pull Request

---

⭐ **Se este projeto foi útil, deixe uma estrela no repositório!**