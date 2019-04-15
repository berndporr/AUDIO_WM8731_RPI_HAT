/**
* @file pitchassignclass.h
* @brief Header file containing the class for comparing fundamental frequency to its relative pitch as a musical note and printing the result on to the terminal
* @author Daniel Escudero Newick
* @date  7/4/19
*/
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;


/**
* @brief Compares fundamental frequency to its relative pitch as a musical note and prints the result on to the terminal
* @param Takes the variable z as an input which represents the fundamental frequency
*/
class pitchassign
{
public:
  void assign(double x){
    if (162.4 <= x && x <= 167.3){
      cout << "You're on E3! (164.8Hz)\n";
    }
    else if (167.3 <= x && x <= 172.0){
      cout << "E3< >F3\n";
    }
    else if (172 <= x && x <= 177.2){
      cout << "You're on F3! (174.6Hz)\n";
    }
    else if (177.2 <= x && x <= 182.2){
      cout << "F3< >Gb3\n";
    }
    else if (182.2 <= x && x <= 187.8){
      cout << "You're on Gb3! (185Hz)\n";
    }
    else if (187.8 <= x && x <= 193.1){
      cout << "Gb3< >G3\n";
    }
    else if (193.1 <= x && x <= 198.9){
      cout << "You're on G3! (196Hz)\n";
    }
    else if (198.9 <= x && x <= 204.6){
      cout << "G3< >Ab3\n";
    }
    else if (204.6 <= x && x <= 210.7){
      cout << "You're on Ab3! (204.6Hz)\n";
    }
    else if (210.7 <= x && x <= 216.7){
      cout << "Ab3< >A3\n";
    }
    else if (216.7 <= x && x <= 223.3){
      cout << "You're on A3! (216.7Hz)\n";
    }
    else if (223.3 <= x && x <= 229.6){
      cout << "A3< >Bb3\n";
    }
    else if (229.6 <= x && x <= 236.6){
      cout << "You're on Bb3! (233.1Hz)\n";
    }
    else if (236.6 <= x && x <= 243.3){
      cout << "Bb3< >B3\n";
    }
    else if (243.3 <= x && x <= 250.6){
      cout << "You're on B3! (246.9Hz)\n";
    }
    else if (250.6 <= x && x <= 257.7){
      cout << "B3< >C4\n";
    }
    else if (257.7 <= x && x <= 265.5){
      cout << "You're on C4! (261.6Hz)\n";
    }
    else if (265.5 <= x && x <= 273.1){
      cout << "C4< >Db4\n";
    }
    else if (273.1 <= x && x <= 281.3){
      cout << "You're on Db4! (277.2Hz)\n";
    }
    else if (281.3 <= x && x <= 289.3){
      cout << "Db4< >D4\n";
    }
    else if (289.3 <= x && x <= 298){
      cout << "You're on D4! (293.7Hz)\n";
    }
    else if (298 <= x && x <= 306.5){
      cout << "D4< >Eb4\n";
    }
    else if (306.5 <= x && x <= 315.8){
      cout << "You're on Eb4! (311.1Hz)\n";
    }
    else if (315.8 <= x && x <= 324.7){
      cout << "Eb4< >E4\n";
    }
    else if (324.7 <= x && x <= 334.5){
      cout << "You're on E4! (329.6Hz)\n";
    }
    else if (334.5 <= x && x <= 344){
      cout << "E4< >F4\n";
    }
    else if (344 <= x && x <= 354.4){
      cout << "You're on F4! (349.2Hz)\n";
    }
    else if (354.4 <= x && x <= 364.5){
      cout << "F4< >Gb4\n";
    }
    else if (364.5 <= x && x <= 375.5){
      cout << "You're on Gb4! (370Hz)\n";
    }
    else if (375.5 <= x && x <= 386.2){
      cout << "Gb4< >G4\n";
    }
    else if (386.2 <= x && x <= 397.8){
      cout << "You're on G4! (392Hz)\n";
    }
    else if (397.8 <= x && x <= 409.1){
      cout << "G4< >Ab4\n";
    }
    else if (409.1 <= x && x <= 421.5){
      cout << "You're on Ab4! (415.3Hz)\n";
    }
    else if (421.5 <= x && x <= 433.5){
      cout << "Ab4< >A4\n";
    }
    else if (433.5 <= x && x <= 446.5){
      cout << "You're on A4! (440Hz)\n";
    }
    else if (446.5 <= x && x <= 459.2){
      cout << "A4< >Bb4\n";
    }
    else if (459.2 <= x && x <= 473.1){
      cout << "You're on Bb4! (466.2Hz)\n";
    }
    else if (473.1 <= x && x <= 486.5){
      cout << "Bb4< >B4\n";
    }
    else if (486.5 <= x && x <= 501.2){
      cout << "You're on B4! (493.9Hz)\n";
    }
    else if (501.2 <= x && x <= 515.5){
      cout << "B4< >C5\n";
    }
    else if (515.5 <= x && x <= 531){
      cout << "You're on C5! (523.3Hz)\n";
    }
    else if (531 <= x && x <= 546.1){
      cout << "C5< >Db5\n";
    }
    else if (546.1 <= x && x <= 562.6){
      cout << "You're on Db5! (554.4Hz)\n";
    }
    else if (562.6 <= x && x <= 578.6){
      cout << "Db5< >D5\n";
    }
    else if (578.6 <= x && x <= 596.1){
      cout << "You're on D5! (587.3Hz)\n";
    }
    else if (596.1 <= x && x <= 613){
      cout << "D5< >Eb5\n";
    }
    else if (613 <= x && x <= 631.5){
      cout << "You're on Eb5! (622.3Hz)\n";
    }
    else if (631.5 <= x && x <= 649.4){
      cout << "Eb5< >E5\n";
    }
    else if (649.4 <= x && x <= 669.1){
      cout << "You're on E5! (659.3Hz)\n";
    }
    else {
      cout << "Out of range!\n";
    }
  }
};
