//--------------------------------------------------------
// ORRad7Model
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
#import "ObjWithHistoryModel.h"

@class ORRad7DataPt;
@class ORSerialPort;


#define kRad7PumpModeAuto	0
#define kRad7PumpModeOn		1
#define kRad7PumpModeOff	2
#define kRad7PumpModeGrab	3

#define kRad7ThoronOn		0
#define kRad7ThoronOff		1

#define kRad7ModeSniff		0
#define kRad7ModeAuto		1
#define kRad7ModeWat40		2
#define kRad7ModeWat250		3
#define kRad7ModeNormal		4

#define  kRad7ModeOFF		0
#define  kRad7ToneChime		1
#define  kRad7ToneGeiger	2

#define  kRad7FormatOff		0
#define  kRad7FormatShort	1
#define  kRad7FormatMedium	2
#define  kRad7FormatLong	3

#define  kRad7PciL			0
#define  kRad7bqm3			1
#define  kRad7cpm			2
#define  kRad7ncnts			3

#define  kRad7Centigrade	0
#define  kRad7Fahrenheit	1

#define kRad7ProtocolNone	0
#define kRad7ProtocolSniff	1
#define kRad7Protocol1Day	2
#define kRad7Protocol2Day	3
#define kRad7ProtocolWeeks	4
#define kRad7ProtocolUser	5
#define kRad7ProtocolGrab	6
#define kRad7ProtocolWat40	7
#define kRad7ProtocolWat250	8
#define kRad7ProtocolThoron	9

#define kRad7Idle			  0
#define kRad7UpdatingSettings 1
#define kRad7Initializing	  2
#define kRad7ExecutingGroup   3
#define kRad7StartingRun	  4
#define kRad7StoppingRun	  5
#define kRad7DumpingSettings  6
#define kRad7Delay            7

#define kRad7RunStateUnKnown  0
#define kRad7RunStateCounting 1 
#define kRad7RunStateStopped  2

#define kRad7FreeCycles			@"freeCycles"
#define kRad7RunNumber			@"runNumber"
#define kRad7CycleNumber		@"cycleNumber"
#define kRad7RunStatus			@"runStatus"
#define kRad7RunPumpStatus		@"runPumpStatus"
#define kRad7RunCountDown		@"runCountDown"
#define kRad7NumberCounts		@"numberCounts"
#define kRad7LastRunNumber		@"lastRunNumber"
#define kRad7LastCycleNumber	@"lastCycleNumber"
#define kRad7LastRadon			@"lastRadon"
#define kRad7LastRadonUnits		@"lastRadonUnits"
#define kRad7LastRadonUncertainty		@"lastRadonUncertainty"
#define kRad7Temp				@"temperature"
#define kRad7TempUnits			@"temperatureUnits"
#define kRad7RH					@"relativeHumidty"
#define kRad7Battery			@"batteryVoltage"
#define kRad7PumpCurrent		@"pumpCurrent"
#define kRad7HV					@"highVoltage"
#define kRad7DutyCycle			@"dutyCycle"
#define kRad7LeakageCurrent		@"leakageCurrent"
#define kRad7SignalVoltage		@"signalVoltage"

@class ORRad7DataPt;
@class ORSafeQueue;

enum {
    kRad7QueueIdle,
    kRad7SendCntrlC,
    kRad7WaitForCarrot,
    kRad7WaitForResponse,
    kRad7FinishedWithCmd,
    kNumberRad7CommandStates //must be last
};

@interface ORRad7Model : ObjWithHistoryModel <ORAdcProcessing>
{
@private
	NSString*       portName;
    NSString*       lastOpenPortName;
	BOOL            portWasOpen;
	ORSerialPort*   serialPort;
	ORSafeQueue* cmdQueue;
	unsigned long	timeMeasured;
	int				pollTime;
	NSMutableString* buffer;
	int				protocol;
	int				cycleTime;
	int				recycle;
	int				mode;
	BOOL			thoron;
	int				pumpMode;
	int				tone;
	int				formatSetting;
	int				rUnits;
	int				tUnits;
	NSMutableDictionary*   statusDictionary;
	int				runState;
	int				dataRecordCount;
	NSMutableArray*	dataPointArray;
	int				runToPrint;
	BOOL			deleteDataOnStart;
	BOOL			verbose;
	BOOL			makeFile;
	
	NSString*		stopRunFilePath;
	BOOL			tempVerbose;
	BOOL			runEnded;
	unsigned long	maxRadon;
	unsigned long	alarmLimit;
	BOOL			gotAtLeastOneRH;
	float			humidityAlarm;
	float			pumpCurrentAlarm;
	float			pumpCurrentMaxLimit;
	float			humidityMaxLimit;
	BOOL            dataValid;  
	int				okCount;
    BOOL			radLinkLoading;
    BOOL			unLoading;
    int             commandState;
    BOOL            gotResponse;
    BOOL            gotCarrot;
    BOOL            poweringUp;
    BOOL            rebooting;
    BOOL            gettingData;
    BOOL            gettingReview;
    int             radLinkSize;
    NSString*       statusString;
}

#pragma mark ***Initialization
- (id)   init;
- (void) dealloc;
- (void) registerNotificationObservers;
- (void) dataReceived:(NSNotification*)note;
- (void) portsChanged:(NSNotification*)aNote;

#pragma mark ***Accessors
- (NSString*)statusString;
- (void) setStatusString:(NSString*)aString;
- (int) commandState;
- (void) setCommandState:(int)aState;
- (BOOL) radLinkLoading;
- (void) setRadLinkLoading:(BOOL)aRadLinkLoading;
- (float) humidityMaxLimit;
- (void) setHumidityMaxLimit:(float)aHumidityMaxLimit;
- (float) pumpCurrentMaxLimit;
- (void) setPumpCurrentMaxLimit:(float)aPumpCurrentMaxLimit;
- (float) pumpCurrentAlarm;
- (void) setPumpCurrentAlarm:(float)aPumpCurrentAlarm;
- (float) humidityAlarm;
- (void) setHumidityAlarm:(float)aHumidityAlarm;
- (unsigned long) alarmLimit;
- (void) setAlarmLimit:(unsigned long)aAlarmLimit;
- (unsigned long) maxRadon;
- (void) setMaxRadon:(unsigned long)aMaxRadon;
- (BOOL) makeFile;
- (void) setMakeFile:(BOOL)aMakeFile;
- (BOOL) verbose;
- (void) setVerbose:(BOOL)aVerbose;
- (BOOL) verbose;
- (void) setVerbose:(BOOL)aVerbose;
- (BOOL) deleteDataOnStart;
- (void) setDeleteDataOnStart:(BOOL)aDeleteDataOnStart;
- (int) runToPrint;
- (void) setRunToPrint:(int)aRunToPrint;
- (NSMutableArray*) dataPointArray;
- (void) setDataPointArray:(NSMutableArray*)aDataPt;
- (int) runState;
- (void) setRunState:(int)aRunState;
- (int) tUnits;
- (void) setTUnits:(int)aUnits;
- (int) rUnits;
- (void) setRUnits:(int)aUnits;
- (int) formatSetting;
- (void) setFormatSetting:(int)aFormat;
- (int) tone;
- (void) setTone:(int)aTone;
- (int) pumpMode;
- (void) setPumpMode:(int)aPumpMode;
- (BOOL) thoron;
- (void) setThoron:(BOOL)aThoron;
- (int) mode;
- (void) setMode:(int)aMode;
- (int) recycle;
- (void) setRecycle:(int)aRecycle;
- (int) cycleTime;
- (void) setCycleTime:(int)aCycleTime;
- (int) protocol;
- (void) setProtocol:(int)aProtocol;
- (void) setRad7Protocol:(int)aProtocol;
- (int) pollTime;
- (void) setPollTime:(int)aPollTime;
- (ORSerialPort*) serialPort;
- (void) setSerialPort:(ORSerialPort*)aSerialPort;
- (BOOL) portWasOpen;
- (void) setPortWasOpen:(BOOL)aPortWasOpen;
- (NSString*) portName;
- (void) setPortName:(NSString*)aPortName;
- (void) setLastOpenPortName:(NSString*)aPortName;
- (void) openPort:(BOOL)state;
- (unsigned long) timeMeasured;
- (NSDictionary*) statusDictionary;
- (id) statusForKey:(id)aKey;

- (int) convertPumpModeStringToIndex:(NSString*)aPumpMode;
- (int) convertThoronStringToIndex:(NSString*)aMode;
- (int) convertCycleHours:(NSString*)hourString minutes:(NSString*)minutesString;
- (int) convertModeStringToIndex:(NSString*)aMode;
- (int) convertToneStringToIndex:(NSString*)aMode;
- (int) convertFormatStringToIndex:(NSString*)aMode;
- (void) convertUnitsString:(NSString*)aUnitsString;
- (int) convertProtocolStringToIndex:(NSString*)aProtocol;

#pragma mark ***Data
- (void) saveUser;
- (void) pollHardware;
- (void) dataErase;
- (int) numPoints;
- (double) radonValue:(int)index;
- (double) radonTime:(int)index;
- (double) rhValue:(int)index;

#pragma mark ***Commands
- (void) addCmdToQueue:(NSString*)aCmd;
- (void) loadDialogFromHardware;
- (id)   initWithCoder:(NSCoder*)decoder;
- (void) encodeWithCoder:(NSCoder*)encoder;
- (void) initHardware;
- (void) specialStatus;
- (void) specialStart;
- (void) specialStop;
- (void) printRun;
- (void) printDataInProgress;
- (void) printRun:(int) runNumber;
- (void) loadRadLinkFile:(NSString*)filePath index:(int)type;
- (void) stopOpsAndInterrupt;

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
- (BOOL) dataForChannelValid:(int)aChannel;
@end

extern NSString* ORRad7ModelRadLinkLoadingChanged;
extern NSString* ORRad7ModelHumidityMaxLimitChanged;
extern NSString* ORRad7ModelPumpCurrentMaxLimitChanged;
extern NSString* ORRad7ModelPumpCurrentAlarmChanged;
extern NSString* ORRad7ModelHumidityAlarmChanged;
extern NSString* ORRad7ModelAlarmLimitChanged;
extern NSString* ORRad7ModelMaxRadonChanged;
extern NSString* ORRad7ModelMakeFileChanged;
extern NSString* ORRad7ModelVerboseChanged;
extern NSString* ORRad7ModelDeleteDataOnStartChanged;
extern NSString* ORRad7ModelRunToPrintChanged;
extern NSString* ORRad7ModelDataPointArrayChanged;
extern NSString* ORRad7ModelRunStateChanged;
extern NSString* ORRad7ModelTUnitsChanged;
extern NSString* ORRad7ModelRUnitsChanged;
extern NSString* ORRad7ModelFormatChanged;
extern NSString* ORRad7ModelToneChanged;
extern NSString* ORRad7ModelPumpModeChanged;
extern NSString* ORRad7ModelThoronChanged;
extern NSString* ORRad7ModelModeChanged;
extern NSString* ORRad7ModelRecycleChanged;
extern NSString* ORRad7ModelCycleTimeChanged;
extern NSString* ORRad7ModelProtocolChanged;
extern NSString* ORRad7ModelPollTimeChanged;
extern NSString* ORRad7Lock;
extern NSString* ORRad7ModelStatusChanged;
extern NSString* ORRad7ModelUpdatePlot;
extern NSString* ORRad7ModelCommandStateChanged;
extern NSString* ORRad7ModelStatusStringChanged;

@interface ORRad7DataPt : NSObject
{
	NSTimeInterval time;
	double value;
	double rh;
}

- (id) initWithCoder:(NSCoder*)decoder;
- (void) encodeWithCoder:(NSCoder*)encoder;

@property (assign) NSTimeInterval time;
@property (assign) double value;
@property (assign) double rh;
@end
