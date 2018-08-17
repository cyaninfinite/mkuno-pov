## v0.4.4
- Display 2 different lines of text
## v0.4.3
- Removed moving average
- Fixed LED update duration to 0.0001ms
## v0.4.2
- Shifted var to config.h
- 'f7x5.h' replaces 'f7x7.h' as font table header
- Updated parsing fx to dynamically add the "blank" columns
  instead of hardcoding it int0 the font table.
- Removed update timer fx: Keeping refresh rate constant at 0.001
## v0.4.1
- Added few more test constants
- Updated to parse some symbols: : ! " # $ % ' + , - . /
## v0.4.0
- Updated f7x7.h, includes uppercase character & new number style
- Updated message parsing fx
- Added alphabet parsing functions (Characters must be CAPITALISED!)
- Added constants to display text numbers & characters
- Added display test function for the font table
## v0.3.3
- Set limit of number of characters that can be displayed at once: 35
## v0.3.2
- Expanded font file to 7x7, includes uppercase character
- 'f7x7.h' replaces 'num6x5.h' as font table header
- Added integer parsing function by getting ASCII
  (Able to display numbers ONLY (for now) using Strings Var)
- Changed MA Period: 10 -> 5
## v0.3.1
- Added moving average (period: 10) for LED active (ON) duration
- Uses interrupt to refresh POV display (active high) instead of setting a fixed refresh rate
  (MsTimer2 delay in setup)
- Reorganised code
## v0.3.0
- Added Hall Sensor to POV Display Setup for display synchronisation
## v0.2.1
- Added "num6x5.h" as font reference, consists of only numbers (0-9)
## v0.2.0
- Uses MsTimer2 library instead of 'default' delay function to refresh
- Update function to utilize bitwise operation to display the chracters
## v0.1.1
- Use PROGMEM to store the display characters 0-4
- Added functions to parse the display characters
## v0.1.0
- Initial Release
- Able to display the following characters: 0 - 4
