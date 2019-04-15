#ifndef WAV_H
#define WAV_H

/** @brief Use the newer ALSA API */
#define ALSA_PCM_NEW_HW_PARAMS_API //!<Updated ALSA hw API
#include <alsa/asoundlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string>
#include <utility>

/** @brief Class to define static variables, for samplePCM */
class waveRecorder {

public:
 
    static uint32_t file_size;
    static char format_marker[4];
    static uint16_t format_type;
    static uint16_t number_of_channels;
    static uint32_t sample_rate;
    static uint32_t bytes_per_second;
    static uint16_t bytes_per_frame;
    static uint16_t bits_per_sample;

    char * recordWAV(); 
    char *buffer;

    //constructor
    waveRecorder();
    ~waveRecorder(){ delete[] buffer; }
};

#endif
