# 🌱 SmartPot – IoT Plant Monitoring System  

This project is a **Smart Plant Monitoring System** built using **ESP32**, **DHT22**, **Soil Moisture Sensor**, **LCD Display (I2C)**, and a **Buzzer**.  
It monitors **temperature, humidity, and soil moisture** in real-time, alerts the user via buzzer + LCD when conditions are abnormal, and ensures your plant stays healthy!  

🔗 [Live Wokwi Simulation](https://wokwi.com/projects/439905054035220481)  

---

## 📌 Features  
- 🌡️ **Temperature Monitoring** (via DHT22 sensor)  
- 💧 **Soil Moisture Detection** (custom ADC simulation in Wokwi)  
- 💨 **Humidity Monitoring**  
- 🔔 **Alerts with Buzzer** when conditions go critical  
- 📟 **16x2 LCD Display** with I2C interface for live updates  
- 🖥️ **Serial Monitor Debugging** for sensor values  

---

## 🛠️ Components Used  
- **ESP32 Devkit V4**  
- **DHT22 Temperature & Humidity Sensor**  
- **Soil Moisture Sensor** (custom Wokwi simulation chip)  
- **16x2 LCD with I2C Module**  
- **Active Buzzer**  

---

## 🔌 Circuit Connections  

| Component | Pin (ESP32) | Notes |
|-----------|-------------|-------|
| LCD VCC   | 5V          | Power supply |
| LCD GND   | GND         | Ground |
| LCD SDA   | GPIO 32     | I2C Data |
| LCD SCL   | GPIO 33     | I2C Clock |
| DHT22 VCC | 3.3V        | Power supply |
| DHT22 GND | GND         | Ground |
| DHT22 Data| GPIO 4      | Data pin |
| Soil Sensor VCC | 3.3V | Power supply |
| Soil Sensor GND | GND | Ground |
| Soil Sensor SIG | GPIO 35 | ADC input |
| Buzzer (+) | GPIO 5 | Signal control |
| Buzzer (–) | GND | Ground |

---

## 📷 Wokwi Setup Screenshot  
<p align="center">
  <img width="634" height="717" alt="image" src="https://github.com/user-attachments/assets/2c804661-e4b6-4ef5-bf70-297aa0ff94a7" />
</p>




---

## 💻 Code Explanation  
- Reads **temperature & humidity** from DHT22.  
- Reads **soil moisture** (ADC, mapped to 0–100%).  
- Displays values and status messages on **LCD**.  
- **Conditions checked:**  
  - Normal: `20–35°C`, `40–70% humidity`, `44–68% soil moisture`.  
  - Otherwise, buzzer alerts and LCD shows warning.  
- Handles multiple **critical condition combinations** (e.g., *High Temp + Low Moisture*).  

---

## 🚀 Getting Started  

### 1. Clone this repo  
```bash
git clone https://github.com/your-username/SmartPot.git
cd SmartPot
```

### 2. Open in [Wokwi](https://wokwi.com)  
Upload the JSON project file to simulate the circuit online.  

### 3. Run Locally (ESP32 + Arduino IDE)  
- Install Arduino IDE  
- Add ESP32 board support via Boards Manager  
- Install required libraries:  
  - `LiquidCrystal_I2C`  
  - `DHT sensor library`  
- Upload the code to ESP32  

---

## 📊 Sample Output (Serial Monitor)  
```
Temp: 28.50 *C
Humidity: 55.20 %
Soil Moisture: 61 %
---------------------
```

LCD Output (Normal Conditions):  
```
All Good!
Plant is Happy :)
```

LCD Output (Critical Example):  
```
Low Moisture!
Water Needed
```

---

## 📝 Custom Soil Moisture Sensor (Wokwi)  
This project uses a **custom chip** in Wokwi to simulate soil moisture (0–4095 ADC).  
It converts ADC to percentage and outputs voltage accordingly.  

Control Slider: **0 → 4095** (Dry → Wet).  

---

## 📌 Author  
👨‍💻 **Sanskar Tiwari (SanTiwari07)**  
- 🎓 ENTC Engineering Student  
- ⚡ Enthusiast in IoT, Robotics, and Automation  

---

## 📜 License  
This project is open-source under the **MIT License**.  
