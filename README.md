# LitTime

## Description

LitTime is a simple time tracking device that tells the time in a fun way. It uses an LED matrix display to emit a colorful 
light show that represents the current time. The device is controlled by an Arduino Mega 2560. 

## Goal

There are lots of devices that tell the time, but none are as fun as LitTime. The goal of this project is to create something that
can tell the time in both light and dark areas, in a fun way. It's a fun project and makes a good conversation piece!

## Quick Start

### Clone this repository

```bash
git clone https://github.com/chigges/LitTime.git
```

### Get your Arduino Mega 2560 ready!

- Upload the code to your Arduino Mega 2560
- Wire up the [LED matrix display](https://www.adafruit.com/product/2279) as specified in the code
```c
//      Sig Pin
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
```
- Enjoy your clock!

## Usage (Customize!)

Feel free to modify the code to suit your needs!

One way to do this is to change the colors of the LEDs. To do this, change this section of the code to hold the RGB values (0-4) of the colors you want:
```c
#define outline_color    (matrix.Color333(0, 0, 0))
#define number_color     (matrix.Color333(1, 0, 0))
#define background_color (matrix.Color333(1, 0, 0))
```

Have fun! And happy hacking!
