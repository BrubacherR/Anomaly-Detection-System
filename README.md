# Anomaly Detection System

## Description
The Anomaly Detection System is a project that implements an outlier detection mechanism using a **MSP432E401Y SimpleLink Microcontroller** and a **VL53L1X Time-of-Flight (ToF) sensor**. The system continuously takes distance measurements and applies a **Local Outlier Factor (LoF)** algorithm to detect anomalies based on a defined threshold.

## Features
- Utilizes the VL53L1X ToF sensor for accurate distance measurements.
- Implements the Local Outlier Factor (LoF) machine learning algorithm in C.
- Stores a dataset of 100 measurements in an array on the microcontroller.
- Constantly monitors distance readings and calculates LoF to identify outliers.
- Sends outlier and distance readings to a PC via UART when they exceed the defined threshold.
- Alerts the user on the PC with printed messages for detected anomalies.

## Technologies Used
- **Microcontroller**: MSP432E401Y SimpleLink
- **Sensor**: VL53L1X Time-of-Flight (ToF) Sensor
- **Communication**: I2C for sensor communication, UART for PC communication
- **Programming Language**: C

## Installation Instructions
1. **Build the Project**: 
   - Open the provided Keil project in your Keil IDE.
   - Build the project to compile the code.

2. **Flash the Microcontroller**: 
   - Flash the compiled code to the MSP432E401Y microcontroller.

3. **Run the Python Script**: 
   - Ensure you have Python installed on your PC.
   - Run the provided Python script to start receiving data from the microcontroller.

## Usage
1. The system initializes the distance sensor and begins measuring.
2. The LoF algorithm runs continuously, comparing current readings to the stored dataset.
3. If the LoF value exceeds the threshold of 2.0, the microcontroller sends an alert with the distance reading to the connected PC.
4. The Python script on the PC receives the data and prints an alert for the detected anomaly.

