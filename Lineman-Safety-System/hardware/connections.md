# Hardware Connections

## LCD
The project uses a 16x2 LCD.

| LCD Pin/Signal | Arduino |
|---|---|
| RS | 8 |
| E | 13 |
| D4 | 12 |
| D5 | 11 |
| D6 | A4 |
| D7 | A5 |

## GSM
SoftwareSerial is configured as:
- Arduino pin 9
- Arduino pin 10

## Relay
- Relay control pin: A3
- HIGH at startup is treated as relay OFF in this prototype.
- LOW is used to activate the relay.

## Password Input
The current sample implementation reads characters through Serial input:
- `#` submits the password
- `*` clears the password

A keypad or web/mobile interface can be added as a future enhancement.

## Safety
Do not connect this educational prototype directly to live high-voltage lines. Use proper isolation and certified protection equipment.
