# mkuno-pov
A Persistence Of Vision (POV) display that utilizes a Hall sensor &amp; the onboard LEDs of the Maker Uno.

## Components
- Hall Sensor
- Maker Uno
- Jumper Wires
- A beam (to mount the Maker Uno & Hall Sensor)
- Support stand with a mahnet & motor to rotate the beam.

## Requirements
As the *MsTimer2* library will be utillized, ensure that it is installed before running the sketch. <br/> 
More details can be found here: https://playground.arduino.cc/Main/MsTimer2

## Usage
- Change the string variable in the _printMsg_ accordingly to what you want the POV to display. 
- There are a few preset constant string to test the fonts available: 
  - *T_NM*: Displays the available number set
  - *T_AP*: Displays the available alphabet set
  - *T_SM*: Displays the available symbol set
  - *T_HW*: The classic *Hello World* to get things started!
- The character limit that can be _displayed_ is set via the _MAXCHAR_ constant, which is set to 35 by default.
- For debugging, enable the *DEBUG* constant.

## Characters
Below are the set of characters that are available for the POV Display:
<br/><br/>
![](f7x7.png)
<br/>
- Spaces ( )
- Numbers (0-9)
- Alphabets (Uppercase, A-Z)
- Some symbols: ! " # $ % ' + , - . /

If there are characters that are not recognised in the string passed to the *printMsg* function, it would be replaced with a empty character (or put simply, nothing).





