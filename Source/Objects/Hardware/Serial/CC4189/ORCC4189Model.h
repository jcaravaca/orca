//--------------------------------------------------------
// ORCC4189Model
// Created by Mark  A. Howe on Fri Jul 22 2005
// Code partially generated by the OrcaCodeWizard. Written by Mark A. Howe.
// Copyright (c) 2005 CENPA, University of Washington. All rights reserved.
//-----------------------------------------------------------
//This program was prepared for the Regents of the University of 
//Washington at the Center for Experimental Nuclear Physics and 
//Astrophysics (CENPA) sponsored in part by the United States 
//Department of Energy (DOE) under Grant #DE-FG02-97ER41020. 
//The University has certain rights in the program pursuant to 
//the contract and the program should not be copied or distributed 
//outside your organization.  The DOE and the University of 
//Washington reserve all rights in the program. Neither the authors,
//University of Washington, or U.S. Government make any warranty, 
//express or implied, or assume any liability or responsibility 
//for the use of this software.
//-------------------------------------------------------------

#pragma mark ***Imported Files

#import "ORAdcProcessing.h"

@class ORSerialPort;
@class ORTimeRate;

@interface ORCC4189Model : OrcaObject <ORAdcProcessing>
{
    @private
        NSString*       portName;
        BOOL            portWasOpen;
        ORSerialPort*   serialPort;
        unsigned long	dataId;
		NSString*		lastRequest;
		NSMutableArray* cmdQueue;
		float		    temperature;
		float		    humidity;
		unsigned long	timeMeasured;
		int				pollTime;
        NSMutableString*  buffer;
		BOOL			shipValues;
		ORTimeRate*		timeRates[2];
		BOOL            readOnce;
}

#pragma mark ***Initialization

- (id)   init;
- (void) dealloc;

- (void) registerNotificationObservers;
- (void) dataReceived:(NSNotification*)note;

#pragma mark ***Accessors
- (ORTimeRate*)timeRate:(int)index;
- (BOOL) shipValues;
- (void) setShipValues:(BOOL)aFlag;
- (ORSerialPort*) serialPort;
- (void) setSerialPort:(ORSerialPort*)aSerialPort;
- (BOOL) portWasOpen;
- (void) setPortWasOpen:(BOOL)aPortWasOpen;
- (NSString*) portName;
- (void) setPortName:(NSString*)aPortName;
- (void) openPort:(BOOL)state;
- (unsigned long) timeMeasured;
- (float) temperature;
- (void) setTemperature:(float)aValue;
- (float) humidity;
- (void) setHumidity:(float)aValue;

#pragma mark ***Data Records
- (void) appendDataDescription:(ORDataPacket*)aDataPacket userInfo:(id)userInfo;
- (NSDictionary*) dataRecordDescription;
- (unsigned long) dataId;
- (void) setDataId: (unsigned long) DataId;
- (void) setDataIds:(id)assigner;
- (void) syncDataIdsWith:(id)anotherCC4189;

- (void) shipAllValues;

- (id)   initWithCoder:(NSCoder*)decoder;
- (void) encodeWithCoder:(NSCoder*)encoder;

#pragma mark •••Adc Processing Protocol
- (void)processIsStarting;
- (void)processIsStopping;
- (void) startProcessCycle;
- (void) endProcessCycle;
- (BOOL) processValue:(int)channel;
- (void) setProcessOutput:(int)channel value:(int)value;
- (NSString*) processingTitle;
- (void) getAlarmRangeLow:(double*)theLowLimit high:(double*)theHighLimit  channel:(int)channel;
- (double) convertedValue:(int)channel;
- (double) maxValueForChan:(int)channel;
@end


extern NSString* ORCC4189ModelShipValuesChanged;
extern NSString* ORCC4189ModelPollTimeChanged;
extern NSString* ORCC4189ModelSerialPortChanged;
extern NSString* ORCC4189Lock;
extern NSString* ORCC4189ModelPortNameChanged;
extern NSString* ORCC4189ModelPortStateChanged;
extern NSString* ORCC4189TemperatureChanged;
extern NSString* ORCC4189HumidityChanged;
