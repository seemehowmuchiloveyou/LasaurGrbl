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

#include <stdbool.h>
#include <stdint.h>


void stepper_isr(void);

// Initialize and start the stepper motor subsystem
void stepper_init(void);

// Block until all buffered steps are executed
void stepper_synchronize(void);
             
// Start stepper interrupt and execute the blocks in queue.
void stepper_wake_up(void);

// make the stepper subsystem fall asleep
void stepper_go_idle(void);

// stop (error) functions
void stepper_request_stop(uint8_t status);
uint8_t stepper_stop_status(void);
bool stepper_stop_requested(void);
void stepper_stop_resume(void);

// Get the actual position of the head in mm.
// This is as accurate as an open loop system can be.
double stepper_get_position_x(void);
double stepper_get_position_y(void);
double stepper_get_position_z(void);
void stepper_set_position(double x, double y, double z);

// perform the homing cycle
void stepper_homing_cycle(void);

#endif
