/**
* @file main.cpp
* @brief Main code which fills input array with values from the recorded sound buffer, applies an fft to this data and outputs the pitch on to the LCD display
* @author Daniel Escudero Newick
* @date  5/4/19
*/

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <record/hwparam.h>
#include <thread>
#include "fftw3.h"
#include "pitchdetectclass.h"
#include "pitchassignclass.h"
#include "displayclass.h"
#include "record/hwparam.h"

/** @brief Define number of fft bins */
#define N 8192
using namespace std;


int main()
 {
  /** @brief Call the function which initialises the LCD display for use */
  displaylcd disp;
  int lcdHandle = disp.initialise();

  /** @brief Loops the entire main code */
  while(true){

  /** @brief Define the input and output array pointers */
  fftw_complex *in = NULL, *out = NULL;
  /** @brief Create a plan which allocates memory for the fft */
  fftw_plan plan;


  /** @brief Allocate memory for the array containing data to input in to the fft and the output array containing the transformed data*/
  in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
  out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);

  /** @brief Calls class for recording the audio PCM data **/
   waveRecorder recorder = waveRecorder();

  /** @brief Declare array containing the PCM data from the buffer */
   double vals[N];

    for(int k = 0; k < 1; ++k) {

  /** @brief Calls function which records audio PCM data and stores into the buffer array */
        auto res = recorder.recordWAV();

  /** @brief Read data from the buffer array in to the array which will hold the PCM data */
            for (int j = 0; j < N; j++) {
              short x = *(short *)(res + j * 2);
              vals[j] = x;
          }
    }

  /** @brief Allocate the PCM data in to the fft input array, where in[i][0] contains the real part and in[i][1] contains the complex part */
  for (int i = 0; i < N ; i ++)
  {
    in[i][0] = vals[i];
    in[i][1] = 0;
  }


  /** @brief Print PCM values into .txt file, allowing the user to plot the data to inspect the soundwave recorded */
  ofstream data;
  data.open ("/home/pi/fftwtest.txt");
   for (int i = 0; i < N; i++) {
     data << left << setw(15) << i << setw(15) << in[i][0] << setw(10) << in[i][1] << endl;
  }

  /** @brief Apply a Hann window function to the PCM data */
  for (int i = 0; i < N; i++)
  {
    double multiplier = 0.5 * (1 - cos(2 * M_PI * i/N));
    in[i][0] = multiplier * in[i][0];
  }

  /** @brief Main function which applies the complex fft */
  plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

  /** @brief Execute the fft plan */
  fftw_execute(plan);

  /** @brief Declare array which will contain the magnitude of the transformed data */
  double y[N];

  /** @brief Calculate the magnitude vector of the complex transformed data and fill array */
  for (int i = 0; i < N; i++)
  {
    double a = out[i][0];
    double b = out[i][1];
    y[i] = sqrt(a*a+b*b) / N ;
  }

  /** @brief Print transformed values into .txt file, allowing the user to plot the data to inspect the fft */
  ofstream data2;
  data2.open ("/home/pi/fftwtest2.txt");
    for (int i = 0; i < N; i++) {
      data2 << left << setw(15) << i << setw(15) << abs(y[i]) << endl;
    }

  /** @brief Calls the function which estimates the fundamental frequency value and converts it to a value in Hz */
   pitchdetect pitch;
   pitch.detect(y);

  /** @brief Calls the function which assigns the fundamental frequency to its respective musical note and prints the result on the terminal */
   pitchassign note;
   note.assign(pitch.freqhz);

  /** @brief Starts a thread which runs the function assigning the fundamental frequency to its respective musical note and prints the results on to the LCD display */
   thread lcdassign(disp.lcd, pitch.freqhz, lcdHandle);


  /** @brief Deallocate memory for the fft plan */
  fftw_destroy_plan(plan);

  /** @brief Deallocate memory for the fft input and output arrays */
  fftw_free(in);
  fftw_free(out);

  /** @brief Join lcdassign thread back in to main thread */
  lcdassign.join();

 }
  return 0;
}
