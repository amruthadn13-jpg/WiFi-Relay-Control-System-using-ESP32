# 💡 WiFi Relay Control System using ESP32

## 📌 Overview

This project is an **IoT-based Relay Control System** built using **ESP32** with **WiFi connectivity**.

It allows users to control a relay (e.g., light or appliance) in two ways:

* 🌐 Through a web browser
* ⌨️ Through serial input

This demonstrates how embedded systems can be controlled remotely using network communication.

---

## ⚙️ Features

* WiFi-based device control
* Built-in web server on ESP32
* Relay ON/OFF using browser
* Serial monitor control
* Real-time status monitoring

---

## 🧠 Project Description

This system turns the ESP32 into a **mini web server** that allows remote control of a relay.

---

### 🔹 WiFi Connectivity

* ESP32 connects to a WiFi network
* Once connected, it gets an IP address
* This IP is used to access the control interface from a browser

---

### 🔹 Web Server Control

* A web server runs on **port 80**

* When accessed via browser:

  * A simple webpage is displayed
  * Contains **ON** and **OFF** buttons

* When user clicks:

  * `/ON` → Relay turns ON
  * `/OFF` → Relay turns OFF

---

### 🔹 Relay Operation

* Relay is connected to a GPIO pin
* Used to control external devices like:

  * Lights
  * Fans
  * Appliances

States:

* **HIGH → Relay ON**
* **LOW → Relay OFF**

---

### 🔹 Serial Control

* User can also control relay via Serial Monitor

Commands:

* `1` → Relay ON
* `0` → Relay OFF

This provides an alternative control method for testing and debugging.

---

### 🔹 HTTP Request Handling

* ESP32 reads incoming HTTP requests
* Checks if the request contains:

  * `/ON` or `/OFF`
* Executes corresponding action

---

## 🔄 Working Flow

1. ESP32 connects to WiFi
2. Web server starts
3. User opens IP address in browser
4. Webpage with ON/OFF buttons is displayed
5. User clicks a button:

   * Relay state changes
6. Alternatively:

   * User sends `1` or `0` via Serial Monitor
   * Relay updates accordingly

---

## 🧠 Learning Outcomes

* Setting up WiFi on ESP32
* Creating a basic web server
* Handling HTTP requests
* Controlling hardware using GPIO
* Combining web + embedded systems

---

## 🚀 Future Enhancements

* Mobile app control
* Authentication (login system)
* MQTT or cloud integration
* Timer-based automation
* Voice control (Alexa / Google Assistant)

---

## 👩‍💻 Author

**Amrutha D N**
