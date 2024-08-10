/*
  Quick demo of major drawing operations on a single DMD
 */

#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h> 
#include <fonts/Arial_Black_16.h>

SoftDMD dmd(3,1);  // DMD controls the entire display

// the setup routine runs once when you press reset:
void setup() {
  dmd.setBrightness(2);
  dmd.selectFont(Arial_Black_16);
  dmd.begin();

  // Circle with a line at a tangent to it
  dmd.drawCircle(24,8,5);
  dmd.drawLine(14,9,28,15);

  // Outline box containing a filled box
  dmd.drawBox(6,10,11,15);
  dmd.drawFilledBox(8,12,9,13);
}

int n = 123;

// the loop routine runs over and over again forever:
void loop() {
  dmd.drawString(0,0,"hhh");

}
