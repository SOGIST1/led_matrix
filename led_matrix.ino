
#include <stdbool.h>
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
// orange #define outline_color    (matrix.Color333(0, 4, 3))
#define outline_color    (matrix.Color333(0, 0, 0))
#define number_color     (matrix.Color333(1, 0, 0))
#define background_color (matrix.Color333(1, 0, 0))

#define matrix_width 64
#define matrix_height 32

// 9 wide with 1 buffer column
#define digit_width 10
#define digit_height 11

#define position_height  (matrix_height / 2 - digit_height / 2)

#define colon_x (matrix_width / 2)
#define colon_y position_height
// 2 wide with 1 buffer column
#define colon_width 3

#define minutes_position (matrix_width / 2 - 2 * digit_width)
#define seconds_position (matrix_width / 2 + colon_width)

void draw_colon(int x, int y) {
	matrix.fillRect(x, y + digit_height / 3, 2, 2, outline_color);
	int const colon_dot_width = 5;
	matrix.fillRect(x, y + digit_height / 3 + colon_dot_width, 2, 2, outline_color);
}

void draw_1(int x, int y) {
	//draw border
	matrix.drawLine(x + 2, y + 0, x + 6, y + 0, outline_color);
	matrix.drawLine(x + 1, y + 1, x + 1, y + 4, outline_color);
	matrix.fillRect(x + 2, y + 1, 6, 10, outline_color);
	matrix.fillRect(x + 0, y + 6, 9, 4, outline_color);
	matrix.drawPixel(x + 1, y + 10, outline_color);

	//draw number onto border
	matrix.fillRect(x + 3, y + 1, 3, 6, number_color);
	matrix.drawPixel(x + 2, y + 2, number_color);
	matrix.drawPixel(x + 2, y + 3, number_color);
	matrix.fillRect(x + 1, y + 7, 6, 2, number_color);
}

void draw_2(int x, int y) {
	//draw border
	matrix.drawLine(x + 1, y + 0, x + 6, y + 0, outline_color);
	matrix.fillRect(x + 0, y + 1, 8, 9, outline_color);
	matrix.drawLine(x + 8, y + 2, x + 8, y + 10, outline_color);
	matrix.drawLine(x + 1, y + 10, x + 7, y + 10, outline_color);

	//draw number onto border
	matrix.fillRect(x + 1, y + 2, 2, 3, number_color);
	matrix.fillRect(x + 2, y + 1, 4, 2, number_color);
	matrix.fillRect(x + 5, y + 2, 2, 3, number_color);
	matrix.fillRect(x + 4, y + 4, 2, 2, number_color);
	matrix.fillRect(x + 3, y + 5, 2, 2, number_color);
	matrix.fillRect(x + 1, y + 7, 6, 2, number_color);
	matrix.drawPixel(x + 2, y + 6, number_color);
}

void draw_3(int x, int y) {
	//draw border
	matrix.fillRect(x + 0, y + 0, 9, 11, outline_color); // draw rectangle around the entire border
	matrix.drawPixel(x + 0, y + 4, background_color); // black out corners
	matrix.drawPixel(x + 0, y + 5, background_color);
	matrix.drawPixel(x + 1, y + 5, background_color);
	matrix.drawPixel(x + 0, y + 10, background_color);
	matrix.drawPixel(x + 8, y + 10, background_color);
	matrix.drawPixel(x + 7, y + 0, background_color);
	matrix.drawPixel(x + 8, y + 0, background_color);
	matrix.drawPixel(x + 8, y + 1, background_color);

	//draw number onto border
	matrix.fillRect(x + 1, y + 1, 5, 2, number_color);
	matrix.fillRect(x + 5, y + 2, 2, 6, number_color);
	matrix.drawPixel(x + 6, y + 5, outline_color);
	matrix.fillRect(x + 3, y + 4, 2, 2, number_color);
	matrix.fillRect(x + 1, y + 7, 5, 2, number_color);
}

void draw_4(int x, int y) {
	// draw border
	matrix.fillRect(x + 0, y + 0, 7, 7, outline_color);
	matrix.fillRect(x + 1, y + 4, 8, 4, outline_color);
	matrix.drawPixel(x + 7, y + 3, outline_color);
	matrix.fillRect(x + 2, y + 8, 5, 2, outline_color);
	matrix.drawLine(x + 4, y + 10, x + 6, y + 10, outline_color);

	// draw number onto border
	matrix.fillRect(x + 1, y + 1, 2, 5, number_color);
	matrix.fillRect(x + 4, y + 1, 2, 8, number_color);
	matrix.fillRect(x + 1, y + 4, 6, 2, number_color);
}

void draw_5(int x, int y) {
	// draw border
	matrix.fillRect(x + 0, y + 0, 9, 11, outline_color);
	matrix.drawPixel(x + 8, y + 0, background_color);
	matrix.drawPixel(x + 8, y + 10, background_color);
	matrix.drawPixel(x + 0, y + 10, background_color);

	// draw number onto border
	matrix.fillRect(x + 3, y + 1, 4, 2, number_color);
	matrix.fillRect(x + 1, y + 1, 2, 5, number_color);
	matrix.fillRect(x + 3, y + 4, 3, 2, number_color);
	matrix.fillRect(x + 5, y + 5, 2, 3, number_color);
	matrix.fillRect(x + 1, y + 7, 5, 2, number_color);
}

void draw_6(int x, int y) {
	// draw border
	matrix.drawLine(x + 0, y + 0, x + 3, y + 0, outline_color);
	matrix.fillRect(x + 0, y + 1, 5, 8, outline_color);
	matrix.fillRect(x + 0, y + 1, 5, 8, outline_color);
	matrix.fillRect(x + 1, y + 5, 8, 5, outline_color);
	matrix.fillRect(x + 5, y + 3, 2, 2, outline_color);
	matrix.drawLine(x + 2, y + 10, x + 7, y + 10, outline_color);
	matrix.drawPixel(x + 7, y + 4, outline_color);

	// draw number onto border
	matrix.fillRect(x + 1, y + 1, 2, 7, number_color);
	matrix.fillRect(x + 3, y + 4, 3, 2, number_color);
	matrix.fillRect(x + 5, y + 5, 2, 4, number_color);
	matrix.fillRect(x + 2, y + 7, 5, 2, number_color);
}

void draw_7(int x, int y) {
	// draw border
	matrix.fillRect(x + 0, y + 0, 8, 4, outline_color);
	matrix.fillRect(x + 6, y + 1, 3, 10, outline_color);
	matrix.drawPixel(x + 1, y + 4, outline_color);
	matrix.drawLine(x + 2, y + 4, x + 2, y + 6, outline_color);
	matrix.drawLine(x + 3, y + 6, x + 3, y + 7, outline_color);
	matrix.fillRect(x + 4, y + 6, 2, 4, outline_color);

	// draw number onto border
	matrix.fillRect(x + 1, y + 1, 6, 2, number_color);
	matrix.fillRect(x + 5, y + 3, 2, 6, number_color);
	matrix.fillRect(x + 3, y + 4, 2, 2, number_color);
}

void draw_8(int x, int y) {
	// draw border
	matrix.fillRect(x + 0, y + 1, 8, 8, outline_color);
	matrix.drawLine(x + 1, y + 0, x + 6, y + 0, outline_color);
	matrix.drawLine(x + 1, y + 9, x + 7, y + 9, outline_color);
	matrix.drawLine(x + 8, y + 2, x + 8, y + 8, outline_color);
	matrix.drawLine(x + 2, y + 10, x + 7, y + 10, outline_color);

	// draw number onto border
	matrix.fillRect(x + 2, y + 1, 4, 2, number_color);
	matrix.fillRect(x + 3, y + 4, 2, 2, number_color);
	matrix.drawPixel(x + 1, y + 2, number_color);
	matrix.drawPixel(x + 1, y + 3, number_color);
	matrix.drawLine(x + 2, y + 3, x + 2, y + 8, number_color);
	matrix.drawLine(x + 1, y + 5, x + 1, y + 7, number_color);
	matrix.fillRect(x + 3, y + 7, 2, 2, number_color);
	matrix.drawLine(x + 5, y + 3, x + 5, y + 8, number_color);
	matrix.drawLine(x + 6, y + 2, x + 6, y + 7, number_color);
	matrix.drawPixel(x + 6, y + 4, outline_color);
	// ^ this can be optimized by drawing a big blue box and then redrawing the black inside of it.
}

void draw_9(int x, int y) {
	// draw border
	matrix.fillRect(x + 1, y + 0, 6, 7, outline_color);
	matrix.drawLine(x + 0, y + 1, x + 0, y + 5, outline_color);
	matrix.drawLine(x + 0, y + 1, x + 0, y + 5, outline_color);
	matrix.fillRect(x + 1, y + 0, 6, 7, outline_color);
	matrix.drawPixel(x + 7, y + 1, outline_color);
	matrix.fillRect(x + 7, y + 2, 2, 9, outline_color);
	matrix.drawLine(x + 2, y + 7, x + 3, y + 7, outline_color);
	matrix.fillRect(x + 4, y + 7, 3, 4, outline_color);
	matrix.drawPixel(x + 4, y + 10, background_color);

	// draw number onto border
	matrix.drawLine(x + 1, y + 2, x + 1, y + 4, number_color);
	matrix.drawLine(x + 2, y + 1, x + 2, y + 5, number_color);
	matrix.fillRect(x + 3, y + 1, 3, 2, number_color);
	matrix.fillRect(x + 5, y + 2, 2, 7, number_color);
	matrix.fillRect(x + 3, y + 4, 2, 2, number_color);
}

void draw_0(int x, int y) {
	matrix.fillRect(x + 1, y + 0, 6, 10, outline_color); 
	matrix.drawLine(x + 0, y + 1, x + 0, y + 8, outline_color); 
	matrix.drawLine(x + 2, y + 10, x + 7, y + 10, outline_color); 
	matrix.fillRect(x + 7, y + 2, 2, 8, outline_color); 
	matrix.drawPixel(x + 7, y + 1, outline_color);

	matrix.drawLine(x + 1, y + 2, x + 1, y + 7, number_color);
	matrix.drawLine(x + 6, y + 2, x + 6, y + 7, number_color);
	matrix.drawLine(x + 2, y + 1, x + 2, y + 8, number_color);
	matrix.drawLine(x + 5, y + 1, x + 5, y + 8, number_color);
	matrix.fillRect(x + 3, y + 1, 2, 2, number_color);
	matrix.fillRect(x + 3, y + 7, 2, 2, number_color);
}

void draw_over_number(int x_position, int y_position, int number) {
	matrix.fillRect(x_position, y_position, digit_width, digit_height, background_color);
	switch(number) {
		case 0: draw_0(x_position, y_position);
				break;
		case 1: draw_1(x_position, y_position);
				break;
		case 2: draw_2(x_position, y_position);
				break;
		case 3: draw_3(x_position, y_position);
				break;
		case 4: draw_4(x_position, y_position);
				break;
		case 5: draw_5(x_position, y_position);
				break;
		case 6: draw_6(x_position, y_position);
				break;
		case 7: draw_7(x_position, y_position);
				break;
		case 8: draw_8(x_position, y_position);
				break;
		case 9: draw_9(x_position, y_position);
				break;
	}
}

void update_number(int x_position_of_leftmost_number, int y_position, int number) {
	// update most significant number, if needed
	if(number % 10 == 0) {
		draw_over_number(x_position_of_leftmost_number, y_position, number / 10);
	}

	// update the least significant number
	draw_over_number(x_position_of_leftmost_number + digit_width, y_position, number % 10);
}

void setup() {
	matrix.begin();
	matrix.fillRect(0, 0, 64, 32, background_color);
	draw_colon(colon_x, colon_y);
}

void loop() {
	for(int minutes = 0; minutes < 60; minutes++) {
		update_number(minutes_position, position_height, minutes);
		for(int seconds = 0; seconds < 60; seconds++) {
			update_number(seconds_position, position_height, seconds);
			delay(1000);
		}
	}
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
