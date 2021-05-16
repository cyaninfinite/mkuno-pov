/*
  ==================================
            7x5 FONT FILE
           By: 1487Quantum
  ==================================
  > Font description file for Maker Uno POV display, replaces "7x7.h".
  > Consists of numbers (0-9), and letters (Capitalized, A-Z)
  > Characters would be rotated 90 degrees clockwise.

  ==================================
            CHANGELOG
  ==================================
  v0.3.0
  - Reduced font dimensions: 7x7 -> 7x5
  - Removed last 2 rows of empty column
    (Will be adding it dynamically via main fx)
  - Shortened column data
  v0.2.2
  - Added symbols: ! " # $ % ' + , - . /
  v0.2.1
  - Changed numbers style (0-9)
  v0.2.0
  - Added alphabet (A-Z, Uppercase)
  - Replaced "num6x5.h" with "f7x7.h"

  v0.1.1
  - Extended character space by 2 clumns instead of one
  - Changed '4' style
  - Added dscription

  v0.1.0
  - Initial Release
  - Contains only blank & number characters (0-9)

  ==================================
         CHARACTER FORMATING
  ==================================
  > Characters will be arranged in a "height X width" format.
  > Each character will take up 7 columns:
    - First 5 columns: The character
    - Last 2 columns:  (Empty)
  > For example, for character '8':

       Percieved                       Arduino (OUT)           LEGEND
                               Col                             1 - ON
       1 1 1 1 1                 1     1 1 1 1 1 1 1           X - BLANK COLUMN
       1       1                 2     1     1     1       (Will be added dynamically)       
       1       1                 3     1     1     1        
       1 1 1 1 1        ---->    4     1     1     1
       1       1                 5     1 1 1 1 1 1 1
       1       1                 6     X
       1 1 1 1 1 X X             7     X

  Col   1 2 3 4 5 6 7

*/

//Symbols: ! " # $ % ' + , - . /


const uint16_t nnil[] PROGMEM{
  0b000000000,
  0b000000000,
  0b000000000,
  0b000000000,
  0b000000000
};

const uint16_t s0[] PROGMEM{
  0b000000000,
  0b101111100,
  0b101111100,
  0b000000000,
  0b000000000
};

const uint16_t s1[] PROGMEM{
  0b000000000,
  0b000011100,
  0b000000000,
  0b000011100,
  0b000000000
};

const uint16_t s2[] PROGMEM{
  0b001010000,
  0b111111100,
  0b001010000,
  0b111111100,
  0b001010000,
  0b000000000
};

const uint16_t s3[] PROGMEM{
  0b010010000,
  0b010101000,
  0b111111100,
  0b010101000,
  0b001001000
};

const uint16_t s4[] PROGMEM{
  0b001000100,
  0b000100000,
  0b000010000,
  0b000001000,
  0b001000100
};

const uint16_t s5[] PROGMEM{
  0b000000000,
  0b000000000,
  0b000011100,
  0b000000000,
  0b000000000
};

const uint16_t s6[] PROGMEM{
  0b000100000,
  0b000100000,
  0b011111000,
  0b000100000,
  0b000100000
};

const uint16_t s7[] PROGMEM{
  0b000000000,   // 0x1FC
  0b100110000,
  0b100110000,
  0b011110000,
  0b000000000
};

const uint16_t s8[] PROGMEM{
  0b000100000,
  0b000100000,
  0b000100000,
  0b000100000,
  0b000100000
};

const uint16_t s9[] PROGMEM{
  0b000000000,
  0b000000000,
  0b100000000,
  0b000000000,
  0b000000000
};

const uint16_t s10[] PROGMEM{
  0b000000000,
  0b110000000,
  0b001100000,
  0b000011000,
  0b000000100
};
//Numbers
const uint16_t n0[] PROGMEM{
  0b111111100, //0x3f
  0b100010100, //0x21
  0b100100100,
  0b101000100,
  0b111111100
};

const uint16_t n1[] PROGMEM{
  0b000000000,
  0b100001000,
  0b111111100, //0x1FC
  0b100000000,
  0b000000000
};

const uint16_t n2[] PROGMEM{
  0b100001000,
  0b110000100,
  0b101000100,
  0b100100100,
  0b100011000
};

const uint16_t n3[] PROGMEM{
  0b010001000,
  0b100000100,
  0b100100100,
  0b100100100,
  0b011011000
};

const uint16_t n4[] PROGMEM{
  0b001100000,
  0b001010000,
  0b001001000,
  0b111111100,
  0b001000000
};

const uint16_t n5[] PROGMEM{
  0b010111100,
  0b100100100,
  0b100100100,
  0b100100100,
  0b011000100
};

const uint16_t n6[] PROGMEM{
  0b011111000,   // 0x1FC
  0b100100100,
  0b100100100,
  0b100100100,
  0b011001000
};

const uint16_t n7[] PROGMEM{
  0b000000100,   // 0x1FC
  0b000000100,
  0b111000100,
  0b000110100,
  0b000001100
};

const uint16_t n8[] PROGMEM{
  0b011011000,   // 0x1FC
  0b100100100,
  0b100100100,
  0b100100100,
  0b011011000
};

const uint16_t n9[] PROGMEM{
  0b000011000,   // 0x1FC
  0b100100100,
  0b100100100,
  0b010100100,
  0b001111000
};

//ALPHABETS (UPPERCASE)

const uint16_t fa[] PROGMEM{
  0b111111000,
  0b000100100,
  0b000100100,
  0b000100100,
  0b111111000
};

const uint16_t fb[] PROGMEM{
  0b111111100,
  0b100100100,
  0b100100100,
  0b100100100,
  0b011011000
};

const uint16_t fc[] PROGMEM{
  0b011111000,
  0b100000100,
  0b100000100,
  0b100000100,
  0b010001000
};

const uint16_t fd[] PROGMEM{
  0b111111100,
  0b100000100,
  0b100000100,
  0b100000100,
  0b011111000
};

const uint16_t fe[] PROGMEM{
  0b111111100,
  0b100100100,
  0b100100100,
  0b100100100,
  0b100100100
};

const uint16_t ff[] PROGMEM{
  0b111111100,
  0b000100100,
  0b000100100,
  0b000100100,
  0b000100100
};

const uint16_t fg[] PROGMEM{
  0b011111000,
  0b100000100,
  0b101000100,
  0b101000100,
  0b011001000
};

const uint16_t fh[] PROGMEM{
  0b111111100,
  0b000100000,
  0b000100000,
  0b000100000,
  0b111111100
};

const uint16_t fi[] PROGMEM{
  0b100000100,
  0b100000100,
  0b111111100,
  0b100000100,
  0b100000100
};

const uint16_t fj[] PROGMEM{
  0b011000100,
  0b100000100,
  0b100000100,
  0b100000100,
  0b011111100
};

const uint16_t fk[] PROGMEM{
  0b111111100,
  0b000100000,
  0b001010000,
  0b010001000,
  0b100000100
};

const uint16_t fl[] PROGMEM{
  0b111111100,
  0b100000000,
  0b100000000,
  0b100000000,
  0b100000000
};
const uint16_t fm[] PROGMEM{
  0b111111100,
  0b000001000,
  0b000110000,
  0b000001000,
  0b111111100
};
const uint16_t fn[] PROGMEM{
  0b111111100,
  0b000001000,
  0b001110000,
  0b010000100,
  0b111111100
};
const uint16_t fo[] PROGMEM{
  0b011111000,
  0b100000100,
  0b100000100,
  0b100000100,
  0b011111000
};
const uint16_t fp[] PROGMEM{
  0b111111100,
  0b000100100,
  0b000100100,
  0b000100100,
  0b000011000
};
const uint16_t fq[] PROGMEM{
  0b001111000,
  0b010000100,
  0b010000100,
  0b010000100,
  0b101111000
};
const uint16_t fr[] PROGMEM{
  0b111111100,
  0b000100100,
  0b000100100,
  0b000100100,
  0b111011000
};
const uint16_t fs[] PROGMEM{
  0b010011000,
  0b100100100,
  0b100100100,
  0b100100100,
  0b011001000
};
const uint16_t ft[] PROGMEM{
  0b000000100,
  0b000000100,
  0b111111100,
  0b000000100,
  0b000000100
};
const uint16_t fu[] PROGMEM{
  0b011111100,
  0b100000000,
  0b100000000,
  0b100000000,
  0b011111100
};
const uint16_t fv[] PROGMEM{
  0b000111100,
  0b011000000,
  0b100000000,
  0b011000000,
  0b000111100
};
const uint16_t fw[] PROGMEM{
  0b001111100,
  0b110000000,
  0b001110000,
  0b110000000,
  0b001111100
};
const uint16_t fx[] PROGMEM{
  0b110001100,
  0b001010000,
  0b000100000,
  0b001010000,
  0b110001100
};
const uint16_t fy[] PROGMEM{
  0b000001100,
  0b000010000,
  0b111100000,
  0b000010000,
  0b000001100
};
const uint16_t fz[] PROGMEM{
  0b110000100,
  0b101000100,
  0b100100100,
  0b100010100,
  0b100001100
};

// Font table - Symbols
const uint16_t *f_sym[] {
  s0, s1, s2, s3, s4,
  nnil, s5, nnil, nnil, nnil, s6,
  s7, s8, s9, s10
};

// Font table - Num
const uint16_t *f_num[] {
  n0, n1, n2, n3, n4,
  n5, n6, n7, n8, n9
};

// Font table - Alphabets (Uppercase)
const uint16_t *f_alp[] {
  fa, fb, fc, fd, fe, ff, fg, fh, fi,
  fj, fk, fl, fm, fn, fo, fp, fq, fr,
  fs, ft, fu, fv, fw, fx, fy, fz
};

