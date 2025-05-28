# auto_irrigation_sys
Automatic Irrigation System for Smart Home

A smart irrigation system using ESP32, soil moisture sensors, and a single water pump controlled via a web dashboard.

---

## Features

- Supports **16 soil moisture sensors** connected to ESP32 ADC pins  
- Automatically waters plants based on configurable moisture threshold  
- Manual override to turn pump ON/OFF via web dashboard  
- Web dashboard hosted on ESP32 for monitoring and control  
- Stores settings (threshold, auto/manual mode) persistently in NVS  
- Always plugged in, uses water inlet (no water tank sensor)  
- Simple, modular, and easy-to-expand codebase  

---

## Hardware Requirements

- ESP32 Dev Board  
- 16 Soil Moisture Sensors (capacitive or resistive)  
- Relay Module (to control water pump)  
- Water Pump (12V or compatible with your relay)  
- Power supply for ESP32 and pump relay (5V for relay logic, 12V for pump)  
- Jumper wires and breadboard or PCB  

---

## Wiring Overview

- Each soil sensor connects to ESP32 ADC pins: GPIO 32, 33, 34, 35, 36, 39, 25, 26, 27, 14, 12, 13, 4, 15, 2, 0  
- Relay control pin connected to GPIO 5  
- Relay controls the pump’s power line (ensure proper power isolation)  
- Common grounds between ESP32, relay, and pump power supply  


---

## Software Setup

1. Clone this repository:

    ```bash
    git clone https://github.com/yourusername/esp32-smart-irrigation.git
    cd esp32-smart-irrigation
    ```

2. Install ESP32 board support in Arduino IDE or use PlatformIO.

3. Upload SPIFFS data (web files) to ESP32:

    - Place `index.html` inside the `data/` folder  
    - Use **ESP32 Sketch Data Upload** tool in Arduino IDE

4. Update Wi-Fi credentials in `wifi_manager.cpp`.

5. Build and upload firmware to ESP32.

---

## Usage

- Access the web dashboard at `http://<ESP32_IP>/` after Wi-Fi connection.  
- View real-time moisture levels and pump status.  
- Toggle automatic/manual mode and set moisture threshold.  
- Use manual override button to start/stop the pump immediately.  

---

## Code Structure

- `/data/` - Web dashboard files served via SPIFFS  
- `/include/` - Header files for all modules  
- `/src/` - Source files including main.cpp  
- `README.md` - This file  

---

## Troubleshooting

- Make sure SPIFFS is properly uploaded (web files missing will cause 404).  
- Verify GPIO pins correspond to your hardware setup.  
- Serial output logs useful debug info; monitor via Serial Monitor.  
- Ensure power supply for pump is adequate and relay wiring is correct.  

---

## Acknowledgments

- ESP32 Arduino Core and libraries  
- ESPAsyncWebServer for web handling  
- Soil moisture sensor calibration guides  

---

Happy gardening! 🌿  
