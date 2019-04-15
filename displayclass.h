/**
* @file displayclass.h
* @brief Header file containing the class for initialising the LCD display, comparing the fundamental frequency to its relative pitch as a musical note and printing the result on to the LCD display
* @author Daniel Escudero Newick
* @date  10/4/19
*/
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "/home/pi/wiringPi/wiringPi/wiringPi.h"
#include "/home/pi/wiringPi/devLib/lcd.h"


/** @brief Define GPIO pins used by the LCD display when connected to the Raspberry Pi */
#define LCD_RS  25               //Register select pin
#define LCD_E   6                //Enable Pin
#define LCD_D4  23               //Data pin 4
#define LCD_D5  22               //Data pin 5
#define LCD_D6  21               //Data pin 6
#define LCD_D7  14               //Data pin 7

/**
* @brief Contains the functions which: initialise the LCD display, compare the fundamental frequency to its relative pitch as a musical note and print the result on to the LCD display
*/
class displaylcd
{
public:
  /**
  * @brief Initialises the LCD display with the Raspberry Pi's GPIO pins
  */
   static int initialise (void){

    int lcdHandle;
    wiringPiSetup();
    lcdHandle = lcdInit (2, 16, 4, LCD_RS, LCD_E, LCD_D4, LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0);
    return lcdHandle;
  }
  /**
  * @brief Compares fundamental frequency to its relative pitch as a musical note and prints the result on to the LCD display
  * @param Takes the variable z as an input which represents the fundamental frequency
  * @param Takes the variable lcdHandle as an input which initialises the GPIO pins used for the LCD display
  */
  static void lcd(double z, int lcdHandle){

    lcdClear(lcdHandle);

    if (162.4 <= z && z <= 167.3){
      lcdPrintf(lcdHandle, "You're on E3!   (164.8Hz)");
    }
    else if (167.3 <= z && z <= 172.0){
      lcdPrintf(lcdHandle, "E3< >F3");
    }
    else if (172 <= z && z <= 177.2){
      lcdPrintf(lcdHandle, "You're on F3!   (174.6Hz)");
    }
    else if (177.2 <= z && z <= 182.2){
      lcdPrintf(lcdHandle, "F3< >Gb3");
    }
    else if (182.2 <= z && z <= 187.8){
      lcdPrintf(lcdHandle, "You're on Gb3!   (185Hz)");
    }
    else if (187.8 <= z && z <= 193.1){
      lcdPrintf(lcdHandle, "Gb3< >G3");
    }
    else if (193.1 <= z && z <= 198.9){
      lcdPrintf(lcdHandle, "You're on G3!   (196Hz)");
    }
    else if (198.9 <= z && z <= 204.6){
      lcdPrintf(lcdHandle, "G3< >Ab3");
    }
    else if (204.6 <= z && z <= 210.7){
      lcdPrintf(lcdHandle, "You're on Ab3!   (204.6Hz)");
    }
    else if (210.7 <= z && z <= 216.7){
      lcdPrintf(lcdHandle, "Ab3< >A3");
    }
    else if (216.7 <= z && z <= 223.3){
      lcdPrintf(lcdHandle, "You're on A3!   (216.7Hz)");
    }
    else if (223.3 <= z && z <= 229.6){
      lcdPrintf(lcdHandle, "A3< >Bb3");
    }
    else if (229.6 <= z && z <= 236.6){
      lcdPrintf(lcdHandle, "You're on Bb3!   (233.1Hz)");
    }
    else if (236.6 <= z && z <= 243.3){
      lcdPrintf(lcdHandle, "Bb3< >B3");
    }
    else if (243.3 <= z && z <= 250.6){
      lcdPrintf(lcdHandle, "You're on B3!   (246.9Hz)");
    }
    else if (250.6 <= z && z <= 257.7){
      lcdPrintf(lcdHandle, "B3< >C4");
    }
    else if (257.7 <= z && z <= 265.5){
      lcdPrintf(lcdHandle, "You're on C4!   (261.6Hz)");
    }
    else if (265.5 <= z && z <= 273.1){
      lcdPrintf(lcdHandle, "C4< >Db4");
    }
    else if (273.1 <= z && z <= 281.3){
      lcdPrintf(lcdHandle, "You're on Db4!   (277.2Hz)");
    }
    else if (281.3 <= z && z <= 289.3){
      lcdPrintf(lcdHandle, "Db4< >D4");
    }
    else if (289.3 <= z && z <= 298){
      lcdPrintf(lcdHandle, "You're on D4!   (293.7Hz)");
    }
    else if (298 <= z && z <= 306.5){
      lcdPrintf(lcdHandle, "D4< >Eb4");
    }
    else if (306.5 <= z && z <= 315.8){
      lcdPrintf(lcdHandle, "You're on Eb4!   (311.1Hz)");
    }
    else if (315.8 <= z && z <= 324.7){
      lcdPrintf(lcdHandle, "Eb4< >E4");
    }
    else if (324.7 <= z && z <= 334.5){
      lcdPrintf(lcdHandle, "You're on E4!   (329.6Hz)");
    }
    else if (334.5 <= z && z <= 344){
      lcdPrintf(lcdHandle, "E4< >F4");
    }
    else if (344 <= z && z <= 354.4){
      lcdPrintf(lcdHandle, "You're on F4!   (349.2Hz)");
    }
    else if (354.4 <= z && z <= 364.5){
      lcdPrintf(lcdHandle, "F4< >Gb4");
    }
    else if (364.5 <= z && z <= 375.5){
      lcdPrintf(lcdHandle, "You're on Gb4!   (370Hz)");
    }
    else if (375.5 <= z && z <= 386.2){
      lcdPrintf(lcdHandle, "Gb4< >G4");
    }
    else if (386.2 <= z && z <= 397.8){
      lcdPrintf(lcdHandle, "You're on G4!   (392Hz)");
    }
    else if (397.8 <= z && z <= 409.1){
      lcdPrintf(lcdHandle, "G4< >Ab4");
    }
    else if (409.1 <= z && z <= 421.5){
      lcdPrintf(lcdHandle, "You're on Ab4!   (415.3Hz)");
    }
    else if (421.5 <= z && z <= 433.5){
      lcdPrintf(lcdHandle, "Ab4< >A4");
    }
    else if (433.5 <= z && z <= 446.5){
      lcdPrintf(lcdHandle, "You're on A4!   (440Hz {or 432Hz})");
    }
    else if (446.5 <= z && z <= 459.2){
      lcdPrintf(lcdHandle, "A4< >Bb4");
    }
    else if (459.2 <= z && z <= 473.1){
      lcdPrintf(lcdHandle, "You're on Bb4!   (466.2Hz)");
    }
    else if (473.1 <= z && z <= 486.5){
      lcdPrintf(lcdHandle, "Bb4< >B4");
    }
    else if (486.5 <= z && z <= 501.2){
      lcdPrintf(lcdHandle, "You're on B4!   (493.9Hz)");
    }
    else if (501.2 <= z && z <= 515.5){
      lcdPrintf(lcdHandle, "B4< >C5");
    }
    else if (515.5 <= z && z <= 531){
      lcdPrintf(lcdHandle, "You're on C5!   (523.3Hz)");
    }
    else if (531 <= z && z <= 546.1){
      lcdPrintf(lcdHandle, "C5< >Db5");
    }
    else if (546.1 <= z && z <= 562.6){
      lcdPrintf(lcdHandle, "You're on Db5!   (554.4Hz)");
    }
    else if (562.6 <= z && z <= 578.6){
      lcdPrintf(lcdHandle, "Db5< >D5");
    }
    else if (578.6 <= z && z <= 596.1){
      lcdPrintf(lcdHandle, "You're on D5!   (587.3Hz)");
    }
    else if (596.1 <= z && z <= 613){
      lcdPrintf(lcdHandle, "D5< >Eb5");
    }
    else if (613 <= z && z <= 631.5){
      lcdPrintf(lcdHandle, "You're on Eb5!   (622.3Hz)");
    }
    else if (631.5 <= z && z <= 649.4){
      lcdPrintf(lcdHandle, "Eb5< >E5");
    }
    else if (649.4 <= z && z <= 669.1){
      lcdPrintf(lcdHandle, "You're on E5!   (659.3Hz)");
    }
    else {
      lcdPrintf(lcdHandle, "Out of range!");
    }
  }

};
