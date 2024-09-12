#include <Arduino.h>   // Include core Arduino library
#include <U8g2lib.h>   // Include U8g2 library for controlling OLED display
#include <Wire.h>      // Include Wire library for I2C communication

// Initialize the OLED display with specific parameters (SSD1306, 128x64, I2C communication)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// Declare and initialize the radius variable for the circle animation
int rad = 0;

void setup(void) {
  // Initialize the display
  u8g2.begin();
}

void loop(void) {
  // Clear the display buffer before drawing new elements
  u8g2.clearBuffer();

  // Set the font for text to a bold font (ncenB08_tr)
  u8g2.setFont(u8g2_font_ncenB08_tr);
  // Draw a string at position (0, 20) on the display
  u8g2.drawStr(0, 20, "ATR lab");
  // Increment the radius of the circle for the animation
  rad += 1;
  // Reset the radius when it reaches or exceeds 50 to create a looping animation
  if (rad >= 50) {
    rad = 0;
  }
  // Draw a circle at position (50, 50) with the current radius value
  u8g2.drawCircle(50, 50, rad);
  
  // Send the updated buffer to the display to show the changes
  u8g2.sendBuffer();
}
