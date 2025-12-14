# Arduino Parking Assistant System

## Project Overview
This project implements a distance monitoring system designed to assist in vehicle parking scenarios. Developed in **C++** for the Arduino Uno platform, the firmware utilizes a **Finite State Machine (FSM)** architecture to ensure robust control and efficient resource management.

The system provides real-time audiovisual feedback based on the proximity of obstacles, simulating the behavior of commercial automotive parking sensors.

## Features
- **Finite State Machine:** Implements a dedicated ON/OFF state logic with button debouncing.
- **Graded Feedback:** Three-stage warning system (Green/Yellow/Red) based on distance thresholds.
- **Audio Alert:** Variable tone frequency generation using a Murata Piezo Buzzer (Passive).
- **Optimization:** Sensor polling only occurs during the active state to conserve processing power.

## Hardware Requirements
- **Microcontroller:** Arduino Uno (ATmega328P)
- **Sensor:** HC-SR04 Ultrasonic Sensor
- **Actuators:**
  - 3x LEDs (Green, Yellow, Red)
  - 1x Murata PKM22EPP-40 Piezo Buzzer (Passive)
- **Input:** Push Button (configured with Internal Pull-up)

## Pinout Configuration
| Component | Arduino Pin | Mode |
|-----------|-------------|------|
| LED Green | D2 | OUTPUT |
| LED Yellow| D3 | OUTPUT |
| LED Red | D4 | OUTPUT |
| Buzzer | D5 | OUTPUT |
| Button | D7 | INPUT_PULLUP |
| Trig (HC-SR04)| D9 | OUTPUT |
| Echo (HC-SR04)| D10 | INPUT |

## How to Run
1. Clone this repository.
2. Open the `.ino` file in the Arduino IDE.
3. Connect the components according to the Pinout table.
4. Upload the firmware to the board.
