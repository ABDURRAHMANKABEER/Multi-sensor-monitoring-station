# Multi-Sensor Monitoring Station

An Arduino-based environmental and analog sensor monitoring system that reads real-time temperature, humidity, ambient light, and potentiometer voltage levels, displaying all metrics on a 20x4 I2C LCD screen. Built and tested in the **Wokwi** simulator.

---

## Features

* **Environmental Monitoring:** Measures ambient temperature (°C) and relative humidity (%) using a DHT22 sensor.
* **Analog Signal Reading:** Converts raw 10-bit ADC readings (`0–1023`) into voltage (`0.00V–5.00V`) for both a light sensor (LDR) and a potentiometer.
* **Flicker-Free 20x4 Display:** Updates each parameter on its own dedicated row without clearing the entire screen, preventing display flicker.
* **Error Handling:** Detects failed DHT22 readings and alerts the user directly on the LCD without crashing the loop.

---

## Hardware & Wokwi Components

| Component | Quantity | Description / Wokwi Part Name |
| :--- | :---: | :--- |
| **Microcontroller** | 1 | Arduino Uno (`wokwi-arduino-uno`) |
| **Display** | 1 | 20x4 I2C Character LCD (`wokwi-lcd2004` with I2C) |
| **Temp & Humidity Sensor** | 1 | DHT22 (`wokwi-dht22`) |
| **Light Sensor** | 1 | Photoresistor / LDR Module (`wokwi-photoresistor-sensor`) |
| **Potentiometer** | 1 | Slide or Rotary Potentiometer (`wokwi-potentiometer`) |

---

## Wiring & Pinout

### 1. 20x4 I2C LCD (`0x27`)

| LCD Pin | Arduino Uno Pin |
| :--- | :--- |
| **GND** | `GND` |
| **VCC** | `5V` |
| **SDA** | `A4` |
| **SCL** | `A5` |

### 2. Sensors

| Component | Pin | Arduino Uno Pin |
| :--- | :--- | :--- |
| **DHT22** | `VCC` / `GND` | `5V` / `GND` |
| **DHT22** | `SDA` (Data) | `D2` |
| **Light Sensor** | `VCC` / `GND` | `5V` / `GND` |
| **Light Sensor** | `AO` (Analog Out) | `A0` |
| **Potentiometer** | `VCC` / `GND` | `5V` / `GND` |
| **Potentiometer** | `SIG` (Wiper) | `A1` |

---

## Required Libraries

Before compiling or running the simulation, install the following libraries via the **Arduino IDE Library Manager** or the **Wokwi Library Manager** tab:

1. **LiquidCrystal I2C** by Frank de Brabander
2. **DHT sensor library** by Adafruit
3. **Adafruit Unified Sensor** *(dependency for the DHT library)*

---

## Display Layout

The 20x4 screen is structured to show one metric per row, refreshing every **2 seconds**:

```text
+--------------------+

|Light:    2.45 V    |
|Pot:      3.80 V    |
|Humidity: 54.2%     |
|Temp:     26.5 C    |
+--------------------+
```

---

## Getting Started

1. **Wire the Circuit:** Connect the LCD and sensors according to the pinout table above (or open your project in Wokwi).
2. **Install Libraries:** Add `LiquidCrystal I2C` and `DHT sensor library` to your environment.
3. **Upload / Simulate:** Flash the sketch to your Arduino Uno or click **Start Simulation** in Wokwi.
4. **Troubleshooting:** 
   * If the LCD remains blank on physical hardware, adjust the blue contrast potentiometer on the back of the I2C module or verify if your LCD address is `0x3F` instead of `0x27`.
   * If `DHT Sensor Error!` appears, verify that the DHT22 data pin is connected to Digital Pin `2`.
