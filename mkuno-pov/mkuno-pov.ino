/*
  ===========================================================
  Maker Uno POV Display, Sync with Hall Sensor
  Version 0.4.0
  By: 1487Quantum (https://github.com/1487quantum)
  ===========================================================
  > Uses moving average, with a period of 8
  > Reorganised code
  > Able to display alphanumeric chracters & some symbols (0-9, A-Z)

  Ref: https://blog.blinkenlight.net/experiments/basic-effects/pov-reloaded/

  ===========================================================
  CHANGELOG
  ===========================================================
  v0.4.1
  - Added few more test constants
  - Updated to parse some symbols: : ! " # $ % ' + , - . /

  v0.4.0
  - Updated f7x7.h, includes uppercase character & new number style
  - Updated message parsing fx
  - Added alphabet parsing functions (Characters must be CAPITALISED!)
  - Added constants to display text numbers & characters
  - Added display test function for the font table

  v0.3.3
  - Set limit of number of characters that can be displayed at once: 35

  v0.3.2
  - Expanded font file to 7x7, includes uppercase character
  - 'f7x7.h' replaces 'num6x5.h' as font table header
  - Added integer parsing function by getting ASCII
    (Able to display numbers ONLY (for now) using Strings Var)
  - Changed MA Period: 10 -> 5

  v0.3.1
  - Added moving average (period: 10) for LED active (ON) duration
  - Uses interrupt to refresh POV display (active high) instead of setting a fixed refresh rate
    (MsTimer2 delay in setup)
  - Reorganised code

  v0.3.0
  - Added Hall Sensor to POV Display Setup for display synchronisation

  v0.2.1
  - Added "num6x5.h" as font reference, consists of only numbers (0-9)

  v0.2.0
  - Uses MsTimer2 library instead of 'default' delay function to refresh
  - Update function to utilize bitwise operation to display the chracters

  v0.1.1
  - Use PROGMEM to store the display characters 0-4
  - Added functions to parse the display characters

  v0.1.0
  - Initial Release
  - Able to display the following characters: 0 - 4
*/

#include "f7x7.h"
#include "MsTimer2.h"

#define DEBUG 0         //Enable to show serial log
#define INT_PIN 2       //Interrupt pin 2 for Hall sensor
#define MA_PERIOD 8    //Moving Average period

//Display Settings
#define CH_WIDTH 7      //Num of columns in a single character
#define MAXCHAR 35      //Max num of char display
#define LEDOFFSET 3     //How many LED to offset from D0
//Test strings
#define T_NM "0123456789 "                  //Numbers
#define T_AP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"   //Alphabet (Upper)
#define T_SM "!\"#$%'+,-./"                 //Symbols
#define T_HW "Hello world!"                  //Hello world

//Hall sensor var
volatile byte state = LOW;

//MA var
int readings[MA_PERIOD];      // the readings from the analog input
int readIndex = 0;            // the index of the current reading
int total = 0;                // the running total

//Timing var
uint16_t lastUpdate;       //Time since last trigger
float pd = 2;                //LED on update duration, ms
int avgP = 0;              // the average update period

//Display/font var
uint16_t ch = 0;  //char index
uint16_t i = 0;  //index i, step through width
uint8_t done = 0; //Is true when msg is done

//Format pattern
// If upper true, upper value would be returned
uint8_t fmt_pattern(bool upper, uint16_t p) {
  uint8_t q;
  if (upper) {
    q = (p << LEDOFFSET) >> 8; //Shift by LEDOFFSET to left as LED starts from D2, not D0. After that, Shift right by 8 to remove lower bits.
  } else {
    //Lower half
    q = (p << LEDOFFSET) & 0xff; //Shift by LEDOFFSET to left as LED starts from D2, not D0
  }
  return q;
}

//Display string on POV
void dispMsg() {
  printMsg(T_AP);
}

void printMsg(char cmsg[]) {
  int char_k = 0;
  if (ch == strlen(cmsg) || ch >= MAXCHAR) {
    //If msg end reach or char limit reach -> Blank the rest
    ch = 0;
    i = 0;
    done = 1;
  } else {
    char_k = cmsg[ch]; //Individual char ASCII
  }
  if (DEBUG) {
    Serial.print("Char: ");
    Serial.println(cmsg[ch]);
  }
  if (!done) {
    // make sure the character is within the alphabet bounds (defined by the font.h file)
    // if it's not, make it a blank character ('z'->122)
    if (char_k < 32 || char_k > 122) {
      char_k = 32;
    }
    //Convert lower to upper case if necessary
    // ASCII for a-z: 97-122
    if (char_k > 96 && char_k <= 122) {
      char_k -= 32;
    }
    // Converts ASCII num to the font index number
    if (char_k == 32) {
      pushCol(f_sym, 5, i); //Display nothing
    } else {
      //Check for symbols
      if (char_k > 32 && char_k <= 47) {
        char_k -= 33;
        pushCol(f_sym, char_k, i);
      } else {
        char_k -= 48;   //Since ascii for '1' is 49
        if (char_k > -1 && char_k < 10) {
          //Numbers 0 - 9
          pushCol(f_num, char_k, i);
        } else if (char_k > 15 && char_k <= 42) {
          //Alphabet A-Z, subtract 17 for alphabet font table
          pushCol(f_alp - 17, char_k, i);
        } else {
          pushCol(f_sym, 5, i); //Display nothing
        }
      }
    }

    if (i >= CH_WIDTH - 1) { //Reset
      i = 0;
      ch++;
    } else {
      i++;
    }
  }
}

//Push the columns
//Font table, font element, column index
void pushCol(uint16_t *fnt[], uint16_t ch, uint16_t i) {
  if (DEBUG) {
    Serial.print(ch);
    Serial.print(F(","));
    Serial.print(i);
    Serial.print(F(","));
    Serial.println(pgm_read_word(fnt[ch] + i), HEX);
  }
  if (ch == -1) {
    PORTD = fmt_pattern(false, 0); //D2-D7, shift by 2 as LED starts on D2,not D0
    PORTB = fmt_pattern(true, 0); //D8-D13
  } else {
    PORTD = fmt_pattern(false, pgm_read_word(fnt[ch] + i)); //D2-D7, shift by 2 as LED starts on D2,not D0
    PORTB = fmt_pattern(true, pgm_read_word(fnt[ch] + i)); //D8-D13
  }
}

void setup() {
  if (DEBUG) {
    Serial.begin(115200);
  }
  // Leave pin 0 (serial receive) as input, otherwise serial port will stop working!) ...
  DDRD = 0b11111010; // set digital  1,3- 7 to output, 2 as input (interrupt)
  DDRB = 0b00111111; // set digital  8-13 to output
  //Attach interrupt for hall sensor
  attachInterrupt(digitalPinToInterrupt(INT_PIN), updatePd, CHANGE);

  // initialize all MA readings to 0:
  for (int thisReading = 0; thisReading < MA_PERIOD; thisReading++) {
    readings[thisReading] = 0;
  }

  MsTimer2::set(2, dispMsg);    //Start timer with default val
  MsTimer2::start();
}

void updatePd() {
  uint16_t tmp;
  state = !state;
  if (state) {
    tmp = micros();
    //Rising edge would be time marker/trigger
    //long r_duration = tmp - lastUpdate; //raw duration
    float s = int((tmp - lastUpdate) % 1000);   //milliseconds
    pd = 1 / pd;   // Rotation, ms/degree
    if (DEBUG) {
      Serial.println(pd); //get degree in 1s instead
    }

    //Moving Average (MA), to filter noise
    total -= readings[readIndex];    // subtract the last reading
    readings[readIndex] = pd;        // get the latest readings
    total += readings[readIndex];    // add the reading to the total
    readIndex++;                     // advance to the next position in the array:

    // if we're at the end of the array...
    if (readIndex >= MA_PERIOD) {
      // ...wrap around to the beginning:
      readIndex = 0;
    }
    avgP = total / MA_PERIOD;         // calculate the average

    //Restart timer with new timing
    MsTimer2::stop();
    MsTimer2::set(avgP, dispMsg); //update the display duration when "homed" with magnet
    MsTimer2::start();
    ch = 0; i = 0; done = 0;
    lastUpdate = tmp;
  }
}

void loop() {

}
