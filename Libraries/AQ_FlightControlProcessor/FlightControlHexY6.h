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

#ifndef _AQ_PROCESS_FLIGHT_CONTROL_HEX_Y6_MODE_H_
#define _AQ_PROCESS_FLIGHT_CONTROL_HEX_Y6_MODE_H_

/*  
             UPPER/LOWER


       CW/CCW           CCW/CW
            
           0....Front....0  
           ......***......    
           ......***......
           ......***......    
           0....Back.....0  
      
                CW/CCW           
*/     

#include "FlightControlVariable.h"

//#define LEFT            MOTOR1
//#define RIGHT           MOTOR2
//#define REAR            MOTOR3
//#define LEFT_UNDER      MOTOR4
//#define RIGHT_UNDER     MOTOR5
//#define REAR_UNDER      MOTOR6
//#define LASTMOTOR       (MOTOR6+1)

void applyMotorCommandY6() {
  // Front = Front/Right, Back = Left/Rear, Left = Front/Left, Right = Right/Rear 
  motorCommand[MOTOR3] = throttle                        + (motorAxisCommandPitch*4/3) - (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR2] = throttle - motorAxisCommandRoll - (motorAxisCommandPitch*2/3) + (yawDirection * motorAxisCommandYaw);  
  motorCommand[MOTOR1] = throttle + motorAxisCommandRoll - (motorAxisCommandPitch*2/3) - (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR6] = throttle                        + (motorAxisCommandPitch*4/3) + (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR5] = throttle - motorAxisCommandRoll - (motorAxisCommandPitch*2/3) - (yawDirection * motorAxisCommandYaw);
  motorCommand[MOTOR4] = throttle + motorAxisCommandRoll - (motorAxisCommandPitch*2/3) + (yawDirection * motorAxisCommandYaw);
}

#endif // #define _AQ_PROCESS_FLIGHT_CONTROL_HEX_Y6_MODE_H_
