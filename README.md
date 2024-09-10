# Arduino LED Traffic Light

## Description
This repository contains two versions of a basic traffic light project that simulates a traffic light using red, yellow, and green LEDs connected to an Arduino:
- **Arduino IDE version**: Uses the Arduino framework and libraries for easy development.
- **Embedded C version**: Written in pure C, using AVR registers and timers directly for precise timing and control of the LEDs.

## Hardware Requirements
- Arduino Uno or compatible board
- Red, Yellow, and Green LEDs
- Resistors (220Ω)
- Breadboard and Jumper Wires

## Files in the Repository

### Arduino Version
- **Path**: `arduino/traffic_light/traffic_light.ino`
- **Description**: This is the original Arduino IDE project that simulates a traffic light. It controls the red, yellow, and green LEDs connected to pins 9, 10, and 11, using Arduino libraries.

### Embedded C Version
- **Path**: `src/`
- **Description**: This version uses AVR libraries and timers in pure C for the same traffic light functionality. No Arduino-specific libraries are used.
  - `src/main.c`: Main logic file for the traffic light system.
  - `src/traffic_light/traffic_light.c` and `traffic_light.h`: Contains the traffic light control logic.
  - `src/timer.h`: Provides delay functionality using the `_delay_ms` function from AVR libraries.

## How to Use

### Arduino IDE Version
1. Connect the red, yellow, and green LEDs to digital pins 9, 10, and 11 on the Arduino, with each LED connected in series with a resistor to ground.
2. Open the `arduino/traffic_light/traffic_light.ino` file in the Arduino IDE.
3. Select the correct board and port from the **Tools** menu.
4. Upload the code to your Arduino board.
5. Observe the LEDs cycling through red, yellow, and green to simulate a traffic light.

### Embedded C Version (Pure C)

#### Prerequisites
- **GNU AVR Toolchain**: Ensure `avr-gcc`, `avr-libc`, and `avrdude` are installed.
- **Make**: For building the project using the `Makefile`.

#### Compilation and Upload Steps
1. Connect the red, yellow, and green LEDs to digital pins 9, 10, and 11 on the Arduino, with each LED connected in series with a resistor to ground.
2. Clone or download the repository and navigate to the root directory.
3. **Modify the Makefile**: Open the `Makefile` and update the `AVRDUDE_PORT` line to use the correct port for your system.
   - For **macOS**, the port may look like `/dev/cu.usbserial-xxxx`.
   - For **Linux**, it could be `/dev/ttyUSB0` or `/dev/ttyACM0`.
   - For **Windows**, it might be `COMx` (where `x` is the COM port number).

   Example:
   ```makefile
   AVRDUDE_PORT = /dev/ttyUSB0  # Update this to match your system
   ```

4. Run the following commands to compile and upload the program:

   ```bash
   make clean        # Clean any previous build files
   make              # Compile the project and generate the .hex file
   make upload       # Upload the compiled .hex file to your Arduino board
   ```

5. Once uploaded, the traffic light simulation will run on your Arduino, with the LEDs cycling through red, yellow, and green automatically.

---

## Project Demo
[![Project Demo Video](https://img.youtube.com/vi/UNM5KqTr1hk/0.jpg)](https://youtu.be/UNM5KqTr1hk)

Click the image above to watch the project demo video on YouTube.
