/*
  AeroQuad v3.0.1 - February 2012
  www.AeroQuad.com
  Copyright (c) 2012 Ted Carancho.  All rights reserved.
  An Open Source Arduino based multicopter.
 
  This program is free software: you can redistribute it and/or modify 
  it under the terms of the GNU General Public License as published by 
  the Free Software Foundation, either version 3 of the License, or 
  (at your option) any later version. 
 
  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  GNU General Public License for more details. 
 
  You should have received a copy of the GNU General Public License 
  along with this program. If not, see <http://www.gnu.org/licenses/>. 
*/

#ifndef _AQ_PROCESS_FLIGHT_CONTROL_HEX_X_MODE_H_
#define _AQ_PROCESS_FLIGHT_CONTROL_HEX_X_MODE_H_

/*  
            CW       CCW
            
           0....Front....0  
           ......***......    
     CCW   ......***......    CW
           ......***......    
           0....Back.....0  
      
           CW       CCW           
*/     

#include "FlightControlVariable.h"

//#define FRONT_LEFT  MOTOR1
//#define FRONT_RIGHT MOTOR2
//#define RIGHT       MOTOR3
//#define REAR_RIGHT  MOTOR4
//#define REAR_LEFT   MOTOR5
//#define LEFT        MOTOR6
//#define LASTMOTOR   (MOTOR6+1)

void applyMotorCommandHexX() {
  motorCommand[MOTOR1] = throttle + motorAxisCommandRoll/2 - motorAxisCommandPitch/2 - (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR4] = throttle - motorAxisCommandRoll/2 + motorAxisCommandPitch/2 + (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR2] = throttle - motorAxisCommandRoll/2 - motorAxisCommandPitch/2 + (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR5] = throttle + motorAxisCommandRoll/2 + motorAxisCommandPitch/2 - (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR3] = throttle - motorAxisCommandRoll                             - (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR6] = throttle + motorAxisCommandRoll                             + (yawDirection * motorAxisCommandYaw);
}

#endif  // #define _AQ_PROCESS_FLIGHT_CONTROL_HEX_X_MODE_H_
