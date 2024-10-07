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
- 📊 We implemented a **Kalman filter** to process inputs from the various sensors (BMP280, MPU6050, and ATMG366H). This smart filtering technique reduces noise and improves accuracy, ensuring reliable flight control. Given the limited memory resources of the **ATmega8**, we optimized the Kalman filter to fit within its constraints. 🚀

### 3. **Landing**
- 🪂 The parachute deployment is controlled by the software, triggered at a specific altitude for a safe and gentle descent!

### 📚 Key Libraries Used
- **GY6050**: To interface with the MPU6050 accelerometer.
- **Adafruit MPU6050**: For reading data from the MPU6050.
- **Adafruit Sensor**: A common interface for various sensors.
- **Wire**: I2C library for sensor communication.
- **SPI**: For high-speed communication.
- **TinyGPS++**: For parsing GPS data from the ATMG366H module.

## 🔄 Design Process

Our design journey was an epic adventure, including:
1. 🧐 Information gathering
2. 💡 Ideation
3. 🧪 Experimentation
4. ✅ Concept selection (using Pugh charts)
5. 🛠️ Prototyping
6. 🖨️ 3D modeling and printing
7. 🔧 Assembly and integration
8. 🚀 Testing

## 🧪 Testing and Results

- 🌤️ GPS functionality tested in open air
- 🔓 Hatch release mechanism tested successfully
- 🎉 Drop test conducted from two stories high with a successful parachute deployment!
  

## 🔮 Future Applications

While originally designed for ISS lab module transport, the AUPS could potentially be adapted for:
- 🛰️ Satellite launches
- 🚀 Astronaut transport (with life support modifications)

## 🤝 Contributing

This project was developed as part of a university course. While it's not actively maintained, we welcome suggestions and ideas for improvement. Please open an issue to discuss any proposed changes!

## 🙌 Acknowledgments

A big shoutout to the **Department of Engineering** at Ashesi University and all the amazing team members who contributed to this project! 🎓💖

## ⚠️ Disclaimer

This is a prototype design created for educational purposes and has not been tested for actual space flight. Any use of this design for real-world applications would require extensive further development and testing. 🚧
