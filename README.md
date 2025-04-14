### 🔐 Arduino Smart Lock with Keypad, Servo, RGB LED, Temperature & Gas Sensor
This project is a multi-functional security system using Arduino. It includes:

A keypad-based smart lock

RGB LED indicators

A servo-controlled safe lock

Temperature monitoring (simulated AC trigger)

Gas detection system with buzzer alarm

# 🔐 Arduino Smart Lock with Keypad, Servo, RGB LED, Temperature & Gas Sensor

This project is a **multi-functional security system** using Arduino. It includes:
- A **keypad-based smart lock**
- **RGB LED indicators**
- A **servo-controlled safe lock**
- **Temperature monitoring** (simulated AC trigger)
- **Gas detection system** with buzzer alarm

---

## 🛠️ Hardware Components

| Component         | Description                         |
|------------------|-------------------------------------|
| Arduino Uno       | Microcontroller                     |
| 4x4 Keypad        | For password input                  |
| Servo Motor       | Controls safe lock (open/close)     |
| RGB LED           | Visual feedback (Red, Green, Blue)  |
| TMP36 Sensor      | Temperature sensor (Analog)         |
| Gas Sensor (MQ-2) | Detects harmful gases               |
| Buzzer            | Alerts for gas detection            |
| Wires/Breadboard  | Connections and prototyping         |

---

## 🔌 Pin Configuration

| Component         | Arduino Pin     |
|------------------|------------------|
| Keypad Rows       | 9, 8, 7, 6        |
| Keypad Columns    | 5, 4, 3, 2        |
| Servo Motor       | 10               |
| RGB LED           | Red - 11, Green - 12, Blue - 13 |
| TMP36 Sensor      | A1               |
| Gas Sensor        | A2               |
| Buzzer            | 13               |

---

## 🧠 Features

- **Password Protection**: Enter a 4-digit code via the keypad.
  - Default password: `1234`
  - Press `#` to submit, `*` to reset input.
- **Servo Lock Mechanism**:
  - Unlocks for 5 seconds if password is correct.
  - Otherwise, LED turns red and stays locked.
- **RGB LED Feedback**:
  - 🔵 Blue – Locked state
  - ✅ Green – Correct password
  - ❌ Red – Wrong password
- **Temperature Monitoring**:
  - Reads from TMP36 sensor
  - If temperature exceeds **30°C**, triggers simulated AC logic
- **Gas Detection**:
  - If gas level > **150** (analog reading), a buzzer alert is triggered

---

## 💻 How to Use

1. Upload the code to your Arduino Uno.
2. Power on the setup.
3. Use the keypad to enter the password:
   - Press `#` to validate
   - Press `*` to clear
4. Observe LED color feedback and servo lock response.
5. Monitor the serial monitor for:
   - Password attempts
   - Temperature and gas level messages

---

## ⚙️ Customization

- Change the default password:
  ```cpp
  String password = "1234";
## 📸 Project Preview
![Alt text](https://github.com/vik802207/Home-Automation/blob/main/img/Home%20Automation.png?raw=true)
