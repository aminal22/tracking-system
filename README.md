### Project Title: Tracking System with ESP32 and GPS Module

#### Overview:
The Tracking System project integrates an ESP32 microcontroller with a GPS module to track the location of a system. To minimize internet usage, the project utilizes the SPIFFS (SPI Flash File System) on the ESP32 board. SPIFFS allows access to flash memory like a normal filesystem, enabling the storage of configuration files, permanent data, HTML/CSS files for building a web server, images, and more.

#### Libraries Used:
- ESPAsyncWebServer: A library for creating asynchronous web servers on ESP32.
- SPIFFS: Allows access to the ESP32 flash memory filesystem.

#### Installation Instructions:
1. Download and install the ESP32FS tool for Arduino IDE from [this link](https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/).
2. Create a folder named `ESP32FS` or `tools` in your Arduino sketchbook directory.
3. Extract the downloaded ESP32FS tool into the `ESP32FS` or `tools` folder.

#### Project Structure:
- `tracking_system.ino`: Arduino sketch file containing the code for the Tracking System project.
- `data`: Folder containing the web server files.
  - `index.html`: HTML file for the web interface.
  - `script.js`: JavaScript file for client-side scripting.
  - `w3.css`: CSS file for styling the web interface.

#### Usage:
1. Connect the ESP32 board with the GPS module.
2. Upload the `tracking_system.ino` sketch to the ESP32 board using the Arduino IDE.
3. Open the Arduino IDE and navigate to `Tools > ESP32 Sketch Data Upload` to upload the contents of the `data` folder to the ESP32 SPIFFS filesystem.
4. Access the web interface hosted on the ESP32 board by entering its IP address in a web browser.

#### Additional Notes:
- The web interface allows users to track the location of the system using GPS data.
- This project demonstrates how to create a web server using ESP32 and serve HTML/CSS files stored in SPIFFS.

#### License:
This project is licensed under the [MIT License](https://opensource.org/licenses/MIT).


#### Acknowledgments:
- Special thanks to the creators of ESPAsyncWebServer and SPIFFS libraries.
- Inspiration and guidance from online tutorials and community forums.
