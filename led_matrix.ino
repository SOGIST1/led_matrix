
#include <RGBmatrixPanel.h>

// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

//#define CLK  8   // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
	matrix.begin();

	matrix.setCursor(0,0);
	matrix.setTextColor(matrix.Color333(0,1,1));
	matrix.print("hello");
	//matrix.fillRect(0, 0, 64, 32, matrix.Color333(1,0,0));
	//matrix.fillRect(0, 32 - 10, 64, 32, matrix.Color333(0,0,1));


}

void loop() {
/*
	for(int r = 0; r <= 5; r++) {
		for(int g = 0; g <= 5; g++) {
			for(int b = 0; b <= 5; b++) {
			  matrix.setCursor(3,0);
			  matrix.setTextColor(matrix.Color333(g,r,b));
			  delay(100);
			  matrix.print("Woah, this is cool!  colors!");
			  delay(500);
		  }
	  }
  }
*/
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
