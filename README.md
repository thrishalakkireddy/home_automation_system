# ESP32 Smart Home Automation and Environmental Monitoring System

A real-time Smart Home Automation and Environmental Monitoring System developed using ESP32, MQTT protocol, Ubidots Cloud, DHT11 temperature sensor, and LDR-based light sensing.

This project demonstrates IoT-based automation where environmental conditions are monitored continuously and appliances such as fans and lights are automatically controlled using predefined threshold conditions.

---

# Project Overview

The system uses an ESP32 microcontroller to collect real-time environmental data from sensors and transmit it to the Ubidots IoT cloud platform using MQTT protocol.

Based on sensor readings:

- Fan control is automated using temperature thresholds.
- Lighting control is automated using ambient light intensity.
- Real-time data is visualized on cloud dashboards.

The project demonstrates practical implementation of:

- Industrial IoT concepts
- Real-time embedded systems
- Sensor interfacing
- Wireless communication
- Home automation logic
- Cloud-based monitoring systems

---

# Features

- Real-time temperature monitoring
- Ambient light intensity detection
- Automatic fan control
- Automatic lighting control
- MQTT-based cloud communication
- Ubidots dashboard integration
- WiFi-enabled IoT architecture
- Real-time serial monitoring and debugging

---

# Hardware Components

- ESP32 Development Board
- DHT11 Temperature Sensor
- LDR (Light Dependent Resistor)
- Relay Module
- Fan / DC Load
- LED / Light Load
- Breadboard and Jumper Wires
- Power Supply

---

# Software and Technologies

- Embedded C / Arduino Framework
- MQTT Protocol
- Ubidots IoT Cloud
- ESP32 WiFi Communication
- Sensor Interfacing
- Real-Time Embedded Systems

---

# Working Principle

## Temperature-Based Automation

- DHT11 sensor continuously measures room temperature.
- If temperature exceeds threshold value:
  - Fan relay turns ON
- Otherwise:
  - Fan relay turns OFF

## Light-Based Automation

- LDR sensor measures ambient light intensity.
- If environment becomes dark:
  - Light relay turns ON
- Otherwise:
  - Light relay turns OFF

## Cloud Monitoring

- Sensor data is sent to Ubidots cloud using MQTT protocol.
- Real-time dashboard displays:
  - Temperature
  - Light intensity
  - Fan status
  - Light status

---

# Folder Structure

```text
Smart-Home-Automation-ESP32/
│
├── src/
│   └── smart_home_automation.ino
│
├── images/
│   ├── setup.jpg
│   ├── dashboard.png
│   └── circuit_diagram.png
│
└── README.md
```

---

# Functionalities Implemented

- WiFi connectivity using ESP32
- MQTT client communication
- Sensor data acquisition
- JSON payload generation
- Cloud dashboard integration
- Relay-based appliance automation
- Threshold-based control logic
- Real-time serial debugging

---

# MQTT Data Published

The ESP32 publishes:

- Temperature
- Light Intensity
- Fan Status
- Light Status

using JSON formatted payloads to Ubidots cloud platform.

---

# Applications

- Smart Home Systems
- Industrial Environmental Monitoring
- IoT-Based Automation
- Energy-Efficient Control Systems
- Remote Monitoring Applications
- Embedded IoT Learning Projects

---

# Future Improvements

- Mobile application integration
- Voice assistant support
- Remote appliance control
- Multiple room monitoring
- Smart energy analytics
- Mobile push notifications
- AI-based predictive automation

---

# Author

**LakkiReddy Thrisha**

Electronics and Communication Engineering  
Embedded Systems | Industrial IoT | Firmware Development | PCB Design
