/*
-------------------------------------------------------------------------

	This file is part of the BoneClamp Data Conversion and Processing System
	Copyright (C) 2013 BoneClamp

-------------------------------------------------------------------------

	Filename: boneclamp.h

	To the extent possible under law, the author(s) have dedicated all copyright
	and related and neighboring rights to this software to the public domain
	worldwide. This software is distributed without any warranty.

	You should have received a copy of the CC Public Domain Dedication along with
	this software. If not, see <http://creativecommons.org/licenses/by-sa/3.0/legalcode>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <prussdrv.h>
#include <pruss_intc_mapping.h>
#include "maps.h"
#include "boneclamp.c"

//Default acquisition properties
//(MUST FIND DEF_SAMPLING PERIOD!!!!)
#define DEF_RESOLUTION          16
#define DEF_SAMPLING_FREQ       25000
#define DEF_SAMPLING_PERIOD     42      //DUMMY VALUE!!
#define DEF_NUMBER_OF_CHANNELS  16
#define DEF_VOLTAGE_LIMIT       5

#define DEF_RB_SIZE             32

/*
typedef struct {
    unsigned short *resolution;
    unsigned short *sampling_freq;
    unsigned short *voltage_limit;
    unsigned short *number_of_channels;
    unsigned int *sampling_period;

    unsigned int *channel_1;
    unsigned int *channel_2;
    unsigned int *channel_3;
    unsigned int *channel_4;
    unsigned int *channel_5;
    unsigned int *channel_6;
    unsigned int *channel_7;
    unsigned int *channel_8;
    unsigned int *channel_9;
    unsigned int *channel_10;
    unsigned int *channel_11;
    unsigned int *channel_12;
    unsigned int *channel_13;
    unsigned int *channel_14;
    unsigned int *channel_15;
    unsigned int *channel_16;   
} bc_data;
*/

//for handling buffer output in userspace
typedef struct {
    int data;
    int channelNumber;
} data;

//ring buffer structure
typedef struct {
    int *size;
    int *start;
    int *count;
    int *end;
    int *elems;//start of elements
    int *elems_end;//end of elements
} RingBuffer;

//functionality to deal with ring buffers
void rbInit(RingBuffer *rb, int size); 
void rbFree(RingBuffer *rb); 
int rbIsFull(RingBuffer *rb);
int rbIsEmpty(RingBuffer *rb);
//void rbWrite(RingBuffer *rb, int data);
void rbRead(RingBuffer *rb, data* datapoint);


//bc_data bc_data_init();

