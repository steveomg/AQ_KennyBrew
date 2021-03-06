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

#ifndef _AEROQUAD_RECEIVER_BASE_MEGA_H_
#define _AEROQUAD_RECEIVER_BASE_MEGA_H_

#include "Arduino.h"
#include "Receiver_Base.h"


int receiverCommand[MAX_NB_CHANNEL] = {1500,1500,1500,1000,1000,1000,1000,1000};
float receiverMinValue[MAX_NB_CHANNEL] = {1000,1000,1000,1000,1000,1000,1000,1000};
float receiverMaxValue[MAX_NB_CHANNEL] = {2000,2000,2000,2000,2000,2000,2000,2000};
byte receiverChannelMap[MAX_NB_CHANNEL] = {XAXIS,YAXIS,ZAXIS,THROTTLE,MODE,AUX1,AUX2,AUX3};

void initializeReceiverPPM();
void initializeReceiverPWM();
void initializeReceiverSBUS();

void readReceiver();

functionPtr initializeReceiver[] = {initializeReceiverPPM,initializeReceiverPWM,initializeReceiverSBUS};

int getRawChannelValuePPM(byte channel);
int getRawChannelValuePWM(byte channel);
int getRawChannelValueSBUS(byte channel);

intFunctionPtrByte getRawChannelValue[] = {getRawChannelValuePPM,getRawChannelValuePWM,getRawChannelValueSBUS};


void readReceiver()
{
  for(byte channel = XAXIS; channel < LAST_CHANNEL; channel++) {

    // Apply receiver calibration adjustment
	receiverCommand[channel] = map(((*getRawChannelValue[receiverTypeUsed])(channel)),receiverMinValue[channel],receiverMaxValue[channel],1000,2000);
  }
}
  
  
const float getReceiverSIData(byte channel) {
  return ((receiverCommand[receiverChannelMap[channel]] - 1500) * (2.5 * PWM2RAD));  // +/- 2.5RPS 50% of full rate
}
  
#endif



