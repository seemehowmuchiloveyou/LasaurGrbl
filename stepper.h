/*
  stepper.c - stepper motor pulse generation
  Processes block from the queue generated by the planer and pulses
  steppers accordingly via a dynamically adapted timer interrupt.
  Part of LasaurGrbl

  Copyright (c) 2011 Stefan Hechenberger
  Copyright (c) 2009-2011 Simen Svale Skogsrud
  Copyright (c) 2011 Sungeun K. Jeon
  
  Inspired by the 'RepRap cartesian firmware' by Zack Smith and 
  Philipp Tiefenbacher.

  LasaurGrbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  LasaurGrbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/

#ifndef stepper_h
#define stepper_h 

#include <avr/io.h>
#include <avr/sleep.h>
#include <stdbool.h>


// Initialize and start the stepper motor subsystem
void stepper_init();

// Block until all buffered steps are executed
void stepper_synchronize();
             
// Start stepper interrupt and execute the blocks in queue.
void stepper_wake_up();

// make the stepper subsystem fall asleep
void stepper_go_idle();

// stop (error) functions
void stepper_request_stop(uint8_t status);
uint8_t stepper_stop_status();
bool stepper_stop_requested();
void stepper_stop_resume();

// warning function
void stepper_request_warning(uint8_t status);
uint8_t stepper_warning_status();
bool stepper_warning_requested();
void stepper_warning_handled();

// Get the actual position of the head in mm.
// This is as accurate as an open loop system can be.
double stepper_get_position_x();
double stepper_get_position_y();
double stepper_get_position_z();
void stepper_set_position(double x, double y, double z);

// perform the homing cycle
void stepper_homing_cycle();

#endif
