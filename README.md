# Smoke Detection System 🚨

> ESP32-based smoke detection system with LCD, buzzer, and LED indicators – tested on Wokwi

This project is a **Smoke Detection and Alert System** built using an **ESP32 microcontroller**, **MQ-2 gas sensor**, **16x2 I2C LCD display**, **buzzer**, and **LED indicators**.  
It continuously monitors the air quality and provides real-time alerts when smoke or harmful gases are detected.

---

## 🛠 Components Used
- ESP32 Development Board  
- MQ-2 Smoke/Gas Sensor  
- 16x2 I2C LCD Display  
- Passive Buzzer  
- Red LED (Alert Indicator)  
- Green LED (Safe Indicator)  
- Resistors and jumper wires  
- Breadboard / simulation on Wokwi  

---

## ⚙️ How It Works
1. The **MQ-2 sensor** measures smoke concentration in the air.  
2. The ESP32 reads the analog value and compares it with a **threshold**.  
   - If the value is **above the threshold**:
     - The **buzzer** sounds an alarm.  
     - The **red LED** turns ON.  
     - The LCD displays: **“ALERT: SMOKE!!”** with the reading.  
   - If the value is **below the threshold**:
     - The **green LED** turns ON.  
     - The buzzer is OFF.  
     - The LCD shows: **“Air is Clean”** with the reading.  
3. Sensor values are also printed to the **Serial Monitor** for easy debugging and calibration.

---

## ✨ Features
- Real-time smoke detection  
- LCD display for clear feedback  
- Buzzer for audio alerts  
- Red/green LEDs for quick visual indication  
- Simple, low-cost, and beginner-friendly project  
- Easy to expand with IoT notifications (Wi-Fi/Mobile app)  

---

## 📌 Applications
- Home safety systems  
- Offices and laboratories  
- Industrial safety monitoring  
- Educational projects on sensors and IoT  

---

## ▶️ Simulation
This project was designed and tested on **Wokwi**.  
👉 [Open the Simulation Here](https://wokwi.com/projects/440814903295993857)

---

## 📂 Project Files
- `smoke_detection.ino` → Arduino code for ESP32  
- `diagram.json` → Circuit diagram (Wokwi)  
- `wokwi-project.txt` → Direct link to Wokwi simulation  

---

## 🔧 Future Improvements
- Connect with **Blynk / MQTT / Firebase** to send alerts remotely  
- Add temperature sensor for fire detection  
- Improve calibration for different environments  

---

## 👩‍💻 Author
Developed by **[Divya]** as part of an IoT/Embedded Systems project.
