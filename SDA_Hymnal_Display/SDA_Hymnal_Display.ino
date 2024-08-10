
#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Arial_Black_16.h>
#include <Keypad.h>

SoftDMD dmd(3, 1);  // DMD controls the entire display

const byte ROWS = 4;  //four rows
const byte COLS = 4;  //three columns
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { A0, A2, 12, A1 };  //connect to the row pinouts of the keypad
byte colPins[COLS] = { 4, 2, 3, 5 };      //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  dmd.setBrightness(2);
  dmd.selectFont(Arial_Black_16);
  dmd.begin();
  Serial.begin(9600);
}

String mode = "num1";
int count;
String num1, num2, num3;

void loop() {
  dmd.drawString(100, 0, "hhh");

  char key = keypad.getKey();
  if (mode == "num1") {
    if (key) {
      Serial.println(count);
      if (key != 'A' && key != 'B' && key != 'C' && key != 'D' && key != '*' && key != '#') {
        // Serial.println(key);
        if (count < 3) {
          num1 += key;
          dmd.drawString(3, 2, num1.c_str());
        } else Serial.println(num1);
        count++;
      } else if (key == 'A') {
        count = 0;
        mode = "num2";
        // return;
      }
      if (key == 'C') {
        num1 = "";
        dmd.drawString(3, 2, "      ");
        count = 0;
      }
    }
  } 
  
  if (key == 'D') {
    dmd.clearScreen();
    mode = "num1";
    count = 0;
    num1 = "";
    num2 = "";
    num3 = "";
  }
  Serial.println(count);
  if (count == 0 && mode == "num1") dmd.drawFilledBox(2, 11, 7, 13);
  else if (count == 0 && mode == "num2") dmd.drawFilledBox(34, 11, 39, 13);
  else if (count == 0 && mode == "num3") dmd.drawFilledBox(66, 11, 71, 13);
  // if (key) {
  //   Serial.println(key);
  // }
}
