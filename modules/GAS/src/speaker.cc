/**
 * \file      speaker.cc
 * \brief     The definitions of the speaker functionality of GAS-02
 * \author    Robbie valkenburg
 * \author    Mike Hilhorst
 * \copyright Copyright (c) 2017, The R2D2 Team
 * \license   See LICENSE
 */

#include "speaker.hh"


/// Code inspired by Wouter van Ooijen.
void Speaker::playNote( int note){
    const int duration = 166666;
    if( note == 0 ){
        hwlib::wait_us( duration );
    } else {
        auto end = hwlib::now_us() + duration;
        auto half_period = 1000000 / ( 2 * note );
        while( end > hwlib::now_us() ){
            speakerPin.set( true );
            hwlib::wait_us( half_period );
            speakerPin.set( false );
            hwlib::wait_us( half_period );
        }
    }
}

