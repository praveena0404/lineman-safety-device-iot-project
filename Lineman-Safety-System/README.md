# Lineman Safety System with Password-Protected Circuit Breaker Using GSM Alerts

## Project Overview
This project is designed to improve electrical line worker safety using:
- Password-protected circuit breaker control
- Relay-based circuit control
- GSM SMS alerts
- LCD status display
- Authorized and unauthorized access handling

The project is based on the system description and sample Arduino code provided in the project report.

## Hardware Components
- Arduino
- 16x2 LCD
- SIM800L GSM module
- 5V Relay Module
- Electromechanical Circuit Breaker
- ACS712 current sensor (for fault-monitoring extension)
- 5V DC power supply

## Software
- Arduino IDE
- Embedded C / Arduino C++

## Basic Working
1. The system asks for a password.
2. The entered password is compared with the predefined password.
3. Correct password -> access is granted and the relay is activated.
4. Wrong password -> access is denied and an SMS alert is sent.
5. GSM is used to notify the configured supervisor number.

## Arduino Pin Connections
| Component | Arduino Pin |
|---|---|
| GSM TX/RX | 9 / 10 |
| LCD RS | 8 |
| LCD E | 13 |
| LCD D4 | 12 |
| LCD D5 | 11 |
| LCD D6 | A4 |
| LCD D7 | A5 |
| Relay | A3 |

## Default Password
`1234`

Change the password in `lineman_safety_system.ino` before deployment.

## Important Safety Note
This repository is intended for educational/prototype use. Do not connect an Arduino/relay prototype directly to live high-voltage electrical lines. Real electrical installations require appropriate isolation, protection devices, certified components, and qualified electrical professionals.

## Project Structure
```text
Lineman-Safety-System/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   └── lineman_safety_system.ino
├── docs/
│   ├── project_summary.md
│   └── test_cases.md
└── hardware/
    └── connections.md
```
