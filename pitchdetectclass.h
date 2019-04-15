/*!
* @file pitchdetectclass.h
* @brief Header file containing the class for detects the fundamental frequency of the sound being recorded
* @author Daniel Escudero Newick
* @date  3/4/19
*/
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;


/*!
* @brief Contains the function which detects the fundamental frequency of the sound being recorded
*/
class pitchdetect
{
public:
    double maxval;
    double freq;
    double freqhz;

    /*!
    * @brief Function which detects the fundamental frequency of the sound being recorded and converts this value in to Hz
    * @param Takes the variable array a[] as an input which contains the transformed PCM data
    */
  tuple<double, double> detect (double a[]) {

    /* Define number of fft bins */
    int N = 8192;
    int i;

  
    for(i = N/2; i < N; i++) /* Set mirror of the fft plot to zero as this is not needed */
    {
      a[i] = 0;
    }

    /* Set all values before 50Hz to zero as these may be detected as a maximum peak for the fft and wrongly assigned to be the fundamental frequency */
    for(i = 0; i < 21; i++)
    {
      a[i] = 0;
    }

    /* Basic pitch detection algorithm which detects the highest peak of the fft and assumes that this is the fundamental frequency of the sound being recorded */
    for (i = 0; i < N; i++)
    {
      if( a[i] > maxval && i > 0 )   // Detect highest peak and therefore approximate fundamental frequency
      {
        maxval = a[i];
        freq = i;
      }
    }
    /* Converts the fundamental frequency to Hz **/
     freqhz = freq * 44100 / N;

    /* Return the maximum value of the fft and the fundamental frequency in Hz */
    return make_tuple(maxval, freqhz);
  }
};
