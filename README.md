# Smoke & Fire Detection System 🚨

> ESP32-based smoke detection system with LCD, buzzer, and LED indicators – tested on Wokwi

This project is a **Smoke and Fire Detection System** built using an **ESP32**, an **MQ-2 gas sensor**, a **16x2 I2C LCD display**, LEDs, and a buzzer. The system continuously monitors air quality and provides **visual and audible alerts** in case of **smoke** or **fire-level smoke concentration**.

---

## 🔧 Components Used
- ESP32 Development Board
- MQ-2 Gas Sensor (Smoke/Flammable Gas Sensor)
- 16x2 LCD Display with I2C module
- Red LED (Alert indicator)
- Green LED (Safe indicator)
- Passive Buzzer (for different tones)
- Jumper wires & breadboard

---

## ⚙️ Working Principle
1. The **MQ-2 sensor** measures gas/smoke concentration.
2. The **ESP32** reads the sensor’s analog values and compares them against **two thresholds**:
   - **Smoke Threshold (~1000)** → Indicates early smoke presence.
   - **Fire Threshold (~2000)** → Indicates fire-level smoke concentration.
3. Based on the sensor readings:
   - ✅ **Air is Clean** → Green LED ON, buzzer OFF, LCD shows safe message.
   - ⚠️ **Smoke Alert** → Red LED blinks slowly, buzzer beeps slowly, LCD shows "SMOKE ALERT".
   - 🔥 **Fire Alert** → Red LED blinks rapidly, buzzer beeps rapidly, LCD flashes "FIRE ALERT".

---

## 🛠️ Features
- Dual-level detection: **Smoke Warning** and **Fire Emergency**
- Distinct **buzzer sounds** and **LED patterns** for easy identification
- Real-time feedback on **LCD display**
- Serial Monitor output for debugging and calibration

---

## 📊 Threshold Values
- **Smoke Detection** → ~1500 (adjustable after calibration)
- **Fire Detection** → ~2300 (for dense smoke/fire-level gas)

⚠️ *Note: These values may vary depending on the sensor and environment. Calibration is recommended for accurate results.*

---

## 📌 Applications
- Home safety systems  
- Offices and laboratories  
- Industrial safety monitoring  
- Educational projects on sensors and IoT  

---

## ▶️ Simulation
Test the project online using Wokwi:  
👉 [Wokwi Simulation Link](https://wokwi.com/projects/440814903295993857)

---

## 📂 Project Files
- `smoke_detection.ino` → Arduino code for ESP32  
- `diagram.json` → Circuit diagram (Wokwi)  
- `wokwi-project.txt` → Direct link to Wokwi simulation  

---

## 🚀 Future Improvements
- IoT integration (send alerts via WiFi/Mobile app)
- Data logging for smoke/fire trends
- Battery-powered standalone design

---

## 👩‍💻 Author
Developed by **[Divya]** as part of an IoT/Embedded Systems project.

✨ This project is ideal for learning **IoT-based safety systems** and demonstrates how sensors, microcontrollers, and output devices can work together for **real-world safety applications**.
