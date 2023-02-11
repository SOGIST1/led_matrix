
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

// numbers are allowed to be 14x32 with column 15 being reserved for spacing between numbers
#define m_white (matrix.Color333(1, 1, 1))
#define m_blue (matrix.Color333(1, 0, 0))
#define m_black (matrix.Color333(0, 0, 0))

void draw_1() {
	//draw border
	matrix.drawLine(2, 0, 6, 0, m_white);
	matrix.drawLine(1, 1, 1, 4, m_white);
	matrix.fillRect(2, 1, 6, 10, m_white);
	matrix.fillRect(0, 6, 9, 4, m_white);
	matrix.drawPixel(1, 10, m_white);

	//draw number onto border
	matrix.fillRect(3, 1, 3, 6, m_blue);
	matrix.drawPixel(2, 2, m_blue);
	matrix.drawPixel(2, 3, m_blue);
	matrix.fillRect(1, 7, 6, 2, m_blue);
}

void draw_2() {
	//draw border
	matrix.drawLine(1, 0, 6, 0, m_white);
	matrix.fillRect(0, 1, 8, 9, m_white);
	matrix.drawLine(8, 2, 8, 10, m_white);
	matrix.drawLine(1, 10, 7, 10, m_white);

	//draw number onto border
	matrix.fillRect(1, 2, 2, 3, m_blue);
	matrix.fillRect(2, 1, 4, 2, m_blue);
	matrix.fillRect(5, 2, 2, 3, m_blue);
	matrix.fillRect(4, 4, 2, 2, m_blue);
	matrix.fillRect(3, 5, 2, 2, m_blue);
	matrix.fillRect(1, 7, 6, 2, m_blue);
	matrix.drawPixel(2, 6, m_blue);
}

void draw_3() {
	//draw border
	matrix.fillRect(0, 0, 9, 11, m_white); // draw rectangle around the entire border
	matrix.drawPixel(0, 4, m_black); // black out corners
	matrix.drawPixel(0, 5, m_black);
	matrix.drawPixel(1, 5, m_black);
	matrix.drawPixel(0, 10, m_black);
	matrix.drawPixel(8, 10, m_black);
	matrix.drawPixel(7, 0, m_black);
	matrix.drawPixel(8, 0, m_black);
	matrix.drawPixel(8, 1, m_black);

	//draw number onto border
	matrix.fillRect(1, 1, 5, 2, m_blue);
	matrix.fillRect(5, 2, 2, 6, m_blue);
	matrix.drawPixel(6, 5, m_white);
	matrix.fillRect(3, 4, 2, 2, m_blue);
	matrix.fillRect(1, 7, 5, 2, m_blue);
}

void draw_4() {
	// draw border
	matrix.fillRect(0, 0, 7, 7, m_white);
	matrix.fillRect(1, 4, 8, 4, m_white);
	matrix.drawPixel(7, 3, m_white);
	matrix.fillRect(2, 8, 5, 2, m_white);
	matrix.drawLine(4, 10, 6, 10, m_white);

	// draw number onto border
	matrix.fillRect(1, 1, 2, 5, m_blue);
	matrix.fillRect(4, 1, 2, 8, m_blue);
	matrix.fillRect(1, 4, 6, 2, m_blue);
}

void draw_5() {
	// draw border
	matrix.fillRect(0, 0, 9, 11, m_white);
	matrix.drawPixel(8, 0, m_black);
	matrix.drawPixel(8, 10, m_black);
	matrix.drawPixel(0, 10, m_black);

	// draw number onto border
	matrix.fillRect(3, 1, 4, 2, m_blue);
	matrix.fillRect(1, 1, 2, 5, m_blue);
	matrix.fillRect(3, 4, 3, 2, m_blue);
	matrix.fillRect(5, 5, 2, 3, m_blue);
	matrix.fillRect(1, 7, 5, 2, m_blue);
}

void draw_6() {
	// draw border
	matrix.drawLine(0, 0, 3, 0, m_white);
	matrix.fillRect(0, 1, 5, 8, m_white);
	matrix.fillRect(0, 1, 5, 8, m_white);
	matrix.fillRect(1, 5, 8, 5, m_white);
	matrix.fillRect(5, 3, 2, 2, m_white);
	matrix.drawLine(2, 10, 7, 10, m_white);
	matrix.drawPixel(7, 4, m_white);

	// draw number onto border
	matrix.fillRect(1, 1, 2, 7, m_blue);
	matrix.fillRect(3, 4, 3, 2, m_blue);
	matrix.fillRect(5, 5, 2, 4, m_blue);
	matrix.fillRect(2, 7, 5, 2, m_blue);
}

void draw_7() {
	// draw border
	matrix.fillRect(0, 0, 8, 4, m_white);
	matrix.fillRect(6, 1, 3, 10, m_white);
	matrix.drawPixel(1, 4, m_white);
	matrix.drawLine(2, 4, 2, 6, m_white);
	matrix.drawLine(3, 6, 3, 7, m_white);
	matrix.fillRect(4, 6, 2, 4, m_white);

	// draw number onto border
	matrix.fillRect(1, 1, 6, 2, m_blue);
	matrix.fillRect(5, 3, 2, 6, m_blue);
	matrix.fillRect(3, 4, 2, 2, m_blue);
}

void draw_8() {
	// draw border
	matrix.fillRect(0, 1, 8, 8, m_white);
	matrix.drawLine(1, 0, 6, 0, m_white);
	matrix.drawLine(1, 9, 7, 9, m_white);
	matrix.drawLine(8, 2, 8, 8, m_white);

	// draw number onto border
	matrix.fillRect(2, 1, 4, 2, m_blue);
	matrix.fillRect(3, 4, 2, 2, m_blue);
	matrix.drawPixel(1, 2, m_blue);
	matrix.drawPixel(1, 3, m_blue);
	matrix.drawLine(2, 3, 2, 8, m_blue);
	matrix.drawLine(1, 5, 1, 7, m_blue);
	matrix.fillRect(3, 7, 2, 2, m_blue);
	matrix.drawLine(5, 3, 5, 8, m_blue);
	matrix.drawLine(6, 2, 6, 7, m_blue);
	matrix.drawPixel(6,4, m_white);
	// ^ this can be optimized by drawing a big blue box and then redrawing the black inside of it.
}

void draw_9() {
	// draw border
	matrix.fillRect(1, 0, 6, 7, m_white);
	matrix.drawLine(0, 1, 0, 5, m_white);
	matrix.drawLine(0, 1, 0, 5, m_white);
	matrix.fillRect(1, 0, 6, 7, m_white);
	matrix.drawPixel(7, 1, m_white);
	matrix.fillRect(7, 2, 2, 9, m_white);
	matrix.drawLine(2, 7, 3, 7, m_white);
	matrix.fillRect(4, 7, 3, 4, m_white);
	matrix.drawPixel(4, 10, m_black);

	// draw number onto border
	matrix.drawLine(1, 2, 1, 4, m_blue);
	matrix.drawLine(2, 1, 2, 5, m_blue);
	matrix.fillRect(3, 1, 3, 2, m_blue);
	matrix.fillRect(5, 2, 2, 7, m_blue);
	matrix.fillRect(3, 4, 2, 2, m_blue);
}

void draw_0() {
	// draw border
	matrix.fillRect(1, 0, 6, 10, m_white);
	matrix.drawLine(0, 1, 0, 8, m_white);
	matrix.drawLine(2, 10, 7, 10, m_white);
	matrix.fillRect(7, 2, 2, 8, m_white);
	matrix.drawPixel(7, 1, m_white);

	// draw number onto border
	matrix.drawLine(1, 2, 1, 7, m_blue);
	matrix.drawLine(6, 2, 6, 7, m_blue);
	matrix.drawLine(2, 1, 2, 8, m_blue);
	matrix.drawLine(5, 1, 5, 8, m_blue);
	matrix.fillRect(3, 1, 2, 2, m_blue);
	matrix.fillRect(3, 7, 2, 2, m_blue);
}

void setup() {
	matrix.begin();
	draw_9();
}

// 5 wide with 1 buffer
void loop() {
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
