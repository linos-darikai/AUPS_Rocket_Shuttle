# 🚀 African Union Panther Shuttle (AUPS)

Welcome to the world of innovation! The **African Union Panther Shuttle (AUPS)** is a prototype space shuttle designed by the brilliant minds of first-year engineering students at Ashesi University. This project was launched in response to the African Union's exciting proposal to send a lab module to the **International Space Station (ISS)**, enabling groundbreaking space-based research for Africa's development. 🌍✨

## 🎯 Project Objectives

The AUPS is on a mission to:
- 🚀 Reach a height of **250 ft (76.2 m)**
- 📏 Measure altitude, pressure, and GPS location
- 🪂 Deploy a parachute for a controlled descent
- 🔄 Be reusable after its first test
- ⚖️ Balance itself mid-air with the help of fins
- 🤖 Operate autonomously during flight
- 📡 Communicate wirelessly with the ground station

## 🔧 Key Components

### 🖥️ Printed Circuit Board (PCB)
A custom-designed **2-inch diameter PCB** featuring:
- **BMP280**: Pressure and altitude sensor
- **MPU6050**: Accelerometer for stabilization
- **ATMG366H**: GPS module for navigation
- **ATmega8**: The brain of the shuttle!

### 🛠️ 3D Printed Parts
- 🛩️ Nosecone with a servo-controlled hatch mechanism
- 🌊 Fins for stabilization
- 🔥 De Laval nozzle for thrust

### 🪂 Parachute
Custom-made from nylon fabric for a safe landing!

## 💻 Software

The flight control software is where the magic happens! It's divided into three thrilling stages:

### 1. **Takeoff**
- 🌟 The software initializes the sensors and gets the shuttle ready for launch!

### 2. **Flight**
- ✈️ Stabilization algorithms keep our shuttle balanced in the sky using data from the **MPU6050**.
- 📊 We implemented a **Kalman filter** to process inputs from the various sensors (BMP280, MPU6050, and ATMG366H). This smart filtering technique reduces noise and improves accuracy, ensuring smooth flight.

### 3. **Landing**
- 🛬 The software deploys the parachute for a controlled descent, ensuring a safe landing.

## 📚 Required Libraries
To run the code, ensure you have the following libraries installed:
- **GY6050**
- **Adafruit MPU6050**
- **Adafruit Sensor**
- **Wire**
- **SPI**
- **TinyGPS++**

## ⚠️ Known Issues
There is a clash between the **MPU6050** and **GPS** modules on the **ATmega8**. Both components use the same **ISP** pin, which means they cannot operate simultaneously with the current design. As a result, only one can work at a time. This issue has not yet been resolved.

## 🔍 Design Process
The project followed an iterative design cycle:
- Information gathering
- Ideation
- Experimentation
- Concept selection (using Pugh charts)
- Prototyping
- 3D modeling and printing
- Assembly and integration
- Testing

## ⚙️ Testing and Results
- GPS functionality tested in open air
- Hatch release mechanism tested successfully
- Drop test conducted from two stories high with successful parachute deployment

## 🚀 Future Applications
While originally designed for ISS lab module transport, the AUPS could potentially be adapted for:
- 🚀 Satellite launches
- 👨‍🚀 Astronaut transport (with life support modifications)

## 🤝 Contributing
This project was developed as part of a university course. While it's not actively maintained, we welcome suggestions and ideas for improvement. Please open an issue to discuss any proposed changes.

## 🙏 Acknowledgments
Special thanks to the Department of Engineering at Ashesi University and all the team members who contributed to this project.

## ⚠️ Disclaimer
This is a prototype design created for educational purposes and has not been tested for actual space flight. Any use of this design for real-world applications would require extensive further development and testing.
