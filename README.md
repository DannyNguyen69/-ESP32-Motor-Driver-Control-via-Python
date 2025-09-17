# ESP32 Motor Driver Control via Python

## Description

This project allows you to control two DC motors connected to an ESP32 through a web server interface. The computer sends motor control commands to the ESP32 using Python (with the `requests` library). The ESP32 receives the commands and controls the motors to move forward, backward, or stop.

## Requirements

- **Hardware:**
  - ESP32
  - 2 DC motors
  - Motor driver (L298N, L9110, etc.)
  - Suitable power supply

- **Software:**
  - ESP32 Arduino code (WebServer)
  - Python 3.x
  - Python library: `requests`

## Usage Instructions

### 1. Upload code to ESP32

- Use Arduino IDE or PlatformIO.
- Configure the correct motor control pins and WiFi information.
- Upload the code to the ESP32.

### 2. Install Python library

```bash
pip install requests
```

### 3. Edit the IP address

- Change the `ESP_IP` variable in `test.py` to the IP address of your ESP32 (check Serial Monitor after WiFi connection).

### 4. Run the Python program

```bash
python test.py
```

- Enter a number as instructed:
    - `1`: Move both motors forward
    - `2`: Move both motors backward
    - `3`: Stop both motors

## Folder Structure

```
:\
│
├── test.py         # Python code to control the motors
```

## Notes

- Make sure the ESP32 and your computer are on the same LAN.
- If the ESP32 resets when receiving commands, check the ESP32 code (input parameter handling).
- Ensure the power supply for the motors and ESP32 is sufficient.

---

**Extensions**
- Apply image processing for control...

**Author:**  
- Nguyễn Khánh Duy - DannyNguyen69
