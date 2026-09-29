# Project Summary

## Title
Lineman Safety System with Password-Protected Circuit Breaker Using GSM Alerts

## Objective
To improve the safety of electrical line workers by providing authorized circuit-breaker control and GSM-based notification.

## Main Modules
1. Password Management
2. Circuit Breaker / Relay Control
3. GSM Communication
4. LCD Status Display
5. Fault Detection Extension

## Working Flow
```text
User enters password
        |
        v
Password verification
   /            \
Correct        Wrong
  |              |
  v              v
Relay ON      Access Denied
  |              |
  v              v
GSM SMS       GSM Alert
```

## Expected Features
- Authorized access using password
- Relay-based circuit control
- Unauthorized access notification
- GSM SMS notification
- LCD status messages
- Extendable sensor-based fault monitoring

The project report also describes continuous monitoring of electrical parameters and automatic power disconnection during hazardous conditions.
