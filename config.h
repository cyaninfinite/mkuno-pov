#define DEBUG 0         //Enable to show serial log

#define INT_PIN 2       //Interrupt pin 2 for Hall sensor
#define S_PIN 8         //Buzzer pin hardwired to pin 8

//Display Settings
#define UPDATE_LED 0.0001  //Duration of LED "ON" per column
#define CH_WIDTH 5        //Num of columns in a single character
#define CH_SPACE 2        //Num of empty columns after single char
#define MAXCHAR 35        //Max num of char display
#define LEDOFFSET 3       //How many LED to offset from D0

//Test string
#define T_NM "0123456789 "                  //Numbers
#define T_AP "ABCDEFGHIJKLMNOPQRSTUVWXYZ"   //Alphabet (Upper)
#define T_SM "!\"#$%'+,-./"                 //Symbols
#define T_HW "Hello world!"                 //Hello world

//tone track
uint16_t jc = 0; //Tempo counter
uint16_t tk = 0; //Tone counter
uint8_t snd = 0;  //Boolean to turn on sound

//Hall sensor var
volatile byte state = LOW;

//Timing var
unsigned long lastUpdate = 0;     //Time since last trigger
unsigned long pd = 1;             //Update Period (Duration for 1 revolution, ms)

//Display/font var
uint16_t ch = 0;  //char index
uint16_t i = 0;  //index i, step through width
uint8_t done = 0; //Is true when all char is displayed
uint8_t blank = 0; //Blank column would be shown if true


//Next msg counter
uint16_t nmsg = 0;
