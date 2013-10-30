//--------------------------------------------------------
// ORGT521Controller
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

#import "ORGT521Controller.h"
#import "ORGT521Model.h"
#import "ORTimeLinePlot.h"
#import "ORCompositePlotView.h"
#import "ORTimeAxis.h"
#import "ORTimeRate.h"
#import "ORSerialPortController.h"

@implementation ORGT521Controller

#pragma mark ***Initialization

- (id) init
{
	self = [super initWithWindowNibName:@"GT521"];
	return self;
}

- (void) dealloc
{
	[[NSNotificationCenter defaultCenter] removeObserver:self];
	[super dealloc];
}

- (void) awakeFromNib
{

    [[plotter0 yAxis] setRngLow:0.0 withHigh:100.];
	[[plotter0 yAxis] setRngLimitsLow:0 withHigh:1000. withMinRng:5];
	
    [[plotter0 xAxis] setRngLow:0.0 withHigh:10000];
	[[plotter0 xAxis] setRngLimitsLow:0.0 withHigh:200000. withMinRng:200];
	
	ORTimeLinePlot* aPlot = [[ORTimeLinePlot alloc] initWithTag:0 andDataSource:self];
	[plotter0 addPlot: aPlot];
	[aPlot setLineColor:[NSColor redColor]];
	[aPlot setName:@"0.5 ¬µm"];
	[aPlot release];

	aPlot = [[ORTimeLinePlot alloc] initWithTag:1 andDataSource:self];
	[plotter0 addPlot: aPlot];
	[aPlot setLineColor:[NSColor blueColor]];
	[aPlot setName:@"5 ¬µm"];
	[aPlot release];
	
	[plotter0 setYLabel:@"Counts/Ft^3/Min"];
	[plotter0 setShowLegend:YES];

	[(ORTimeAxis*)[plotter0 xAxis] setStartTime: [[NSDate date] timeIntervalSince1970]];

	[super awakeFromNib];
}

- (void) setModel:(id)aModel
{
	[super setModel:aModel];
	[[self window] setTitle:[NSString stringWithFormat:@"GT521 (Unit %lu)",[model uniqueIdNumber]]];
}

- (BOOL) portLocked
{
	return [gSecurity isLocked:ORGT521Lock];;
}

#pragma mark ***Notifications

- (void) registerNotificationObservers
{
	NSNotificationCenter* notifyCenter = [NSNotificationCenter defaultCenter];
    [super registerNotificationObservers];
    [notifyCenter addObserver : self
                     selector : @selector(lockChanged:)
                         name : ORRunStatusChangedNotification
                       object : nil];
    
    [notifyCenter addObserver : self
                     selector : @selector(lockChanged:)
                         name : ORGT521Lock
                        object: nil];

     [notifyCenter addObserver : self
                     selector : @selector(measurementDateChanged:)
                         name : ORGT521ModelMeasurementDateChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(size1Changed:)
                         name : ORGT521ModelSize1Changed
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(size2Changed:)
                         name : ORGT521ModelSize2Changed
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(count1Changed:)
                         name : ORGT521ModelCount1Changed
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(count2Changed:)
                         name : ORGT521ModelCount2Changed
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(countingModeChanged:)
                         name : ORGT521ModelCountingModeChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(cycleDurationChanged:)
                         name : ORGT521ModelCycleDurationChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(runningChanged:)
                         name : ORGT521ModelRunningChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(cycleStartedChanged:)
                         name : ORGT521ModelCycleStartedChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(cycleWillEndChanged:)
                         name : ORGT521ModelCycleWillEndChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(cycleNumberChanged:)
                         name : ORGT521ModelCycleNumberChanged
						object: model];

    [notifyCenter addObserver : self
					 selector : @selector(scaleAction:)
						 name : ORAxisRangeChangedNotification
					   object : nil];
	
    [notifyCenter addObserver : self
					 selector : @selector(miscAttributesChanged:)
						 name : ORMiscAttributesChanged
					   object : model];
	
    [notifyCenter addObserver : self
					 selector : @selector(updateTimePlot:)
						 name : ORRateAverageChangedNotification
					   object : nil];
	
    [notifyCenter addObserver : self
                     selector : @selector(maxCountsChanged:)
                         name : ORGT521ModelMaxCountsChanged
						object: model];

    [notifyCenter addObserver : self
                     selector : @selector(countAlarmLimitChanged:)
                         name : ORGT521ModelCountAlarmLimitChanged
						object: model];

	[serialPortController registerNotificationObservers];
    [notifyCenter addObserver : self
                     selector : @selector(locationChanged:)
                         name : ORGT521ModelLocationChanged
						object: model];

}

- (void) updateWindow
{
    [super updateWindow];
    [self lockChanged:nil];
	[self measurementDateChanged:nil];
	[self size1Changed:nil];
	[self size2Changed:nil];
	[self count1Changed:nil];
	[self count2Changed:nil];
	[self countingModeChanged:nil];
	[self cycleDurationChanged:nil];
	[self runningChanged:nil];
	[self cycleStartedChanged:nil];
	[self cycleWillEndChanged:nil];
	[self cycleNumberChanged:nil];
	[self updateTimePlot:nil];
    [self miscAttributesChanged:nil];
	[self maxCountsChanged:nil];
	[self countAlarmLimitChanged:nil];
	[serialPortController updateWindow];
	[self locationChanged:nil];
}

- (void) locationChanged:(NSNotification*)aNote
{
	[locationField setIntValue: [(ORGT521Model*)model location]];
}

- (void) countAlarmLimitChanged:(NSNotification*)aNote
{
	[countAlarmLimitTextField setFloatValue: [model countAlarmLimit]];
}

- (void) maxCountsChanged:(NSNotification*)aNote
{
	[maxCountsTextField setFloatValue: [model maxCounts]];
}

- (void) scaleAction:(NSNotification*)aNotification
{
	if(aNotification == nil || [aNotification object] == [plotter0 xAxis]){
		[model setMiscAttributes:[(ORAxis*)[plotter0 xAxis]attributes] forKey:@"XAttributes0"];
	};
	
	if(aNotification == nil || [aNotification object] == [plotter0 yAxis]){
		[model setMiscAttributes:[(ORAxis*)[plotter0 yAxis]attributes] forKey:@"YAttributes0"];
	};
}

- (void) miscAttributesChanged:(NSNotification*)aNote
{
	
	NSString*				key = [[aNote userInfo] objectForKey:ORMiscAttributeKey];
	NSMutableDictionary* attrib = [model miscAttributesForKey:key];
	
	if(aNote == nil || [key isEqualToString:@"XAttributes0"]){
		if(aNote==nil)attrib = [model miscAttributesForKey:@"XAttributes0"];
		if(attrib){
			[(ORAxis*)[plotter0 xAxis] setAttributes:attrib];
			[plotter0 setNeedsDisplay:YES];
			[[plotter0 xAxis] setNeedsDisplay:YES];
		}
	}
	if(aNote == nil || [key isEqualToString:@"YAttributes0"]){
		if(aNote==nil)attrib = [model miscAttributesForKey:@"YAttributes0"];
		if(attrib){
			[(ORAxis*)[plotter0 yAxis] setAttributes:attrib];
			[plotter0 setNeedsDisplay:YES];
			[[plotter0 yAxis] setNeedsDisplay:YES];
		}
	}
}

- (void) updateTimePlot:(NSNotification*)aNote
{
	if(!aNote || ([aNote object] == [model timeRate:1])){
		[plotter0 setNeedsDisplay:YES];
	}
}

- (void) cycleStartedChanged:(NSNotification*)aNote
{
	
	NSDateFormatter* dateFormatter = [[NSDateFormatter alloc] initWithDateFormat:@"%H:%M:%S" allowNaturalLanguage:NO];
	NSString* dateString = [dateFormatter stringFromDate:[model cycleStarted]];
	
	[dateFormatter release];
	if(dateString) [cycleStartedField setStringValue:dateString];
	else [cycleStartedField setStringValue:@"---"];
	
}

- (void) cycleWillEndChanged:(NSNotification*)aNote
{
	NSDate* now = [NSDate date];
	NSDate* timeCycleWillEnd = [model cycleWillEnd];
	NSTimeInterval  timeLeft = [timeCycleWillEnd timeIntervalSinceDate:now];
	[timeLeftInCycleField setIntValue:(int)ceil(timeLeft)];
}

- (void) cycleNumberChanged:(NSNotification*)aNote
{
	[cycleNumberField setIntValue: [model cycleNumber]];
}

- (void) runningChanged:(NSNotification*)aNote
{
	[self updateButtons];
}

- (void) cycleDurationChanged:(NSNotification*)aNote
{
	[cycleDurationPU selectItemWithTag: [model cycleDuration]];
}

- (void) countingModeChanged:(NSNotification*)aNote
{
	[countingModeTextField setStringValue: [model countingModeString]];
}

- (void) count2Changed:(NSNotification*)aNote
{
	[count2TextField setIntValue: [model count2]];
}

- (void) count1Changed:(NSNotification*)aNote
{
	[count1TextField setIntValue: [model count1]];
}

- (void) size2Changed:(NSNotification*)aNote
{
	[size2TextField setFloatValue: [model size2]];
}

- (void) size1Changed:(NSNotification*)aNote
{
	[size1TextField setFloatValue: [model size1]];
}

- (void) measurementDateChanged:(NSNotification*)aNote
{
	[measurementDateTextField setStringValue: [model measurementDate]];
}

- (void) checkGlobalSecurity
{
    BOOL secure = [[[NSUserDefaults standardUserDefaults] objectForKey:OROrcaSecurityEnabled] boolValue];
    [gSecurity setLock:ORGT521Lock to:secure];
    [lockButton setEnabled:secure];
}

- (void) lockChanged:(NSNotification*)aNotification
{
	[self updateButtons];
}

- (void) updateButtons
{
    BOOL locked = [gSecurity isLocked:ORGT521Lock];

    [lockButton setState: locked];
	
   	[serialPortController updateButtons:locked];
 
	if(!locked){
		[startCycleButton setEnabled:![model running]];
		[stopCycleButton setEnabled:[model running]];
	}
	else {
		[startCycleButton setEnabled:NO];
		[stopCycleButton setEnabled:NO];
	}
	[cycleDurationPU setEnabled:![model running] && !locked];

	if([model running]){
		NSDate* now = [NSDate date];
		NSDate* timeCycleWillEnd = [model cycleWillEnd];
		NSTimeInterval  timeLeft = [timeCycleWillEnd timeIntervalSinceDate:now];
		[timeLeftInCycleField setIntValue:(int)ceil(timeLeft)];
		
	}
	else {
		[timeLeftInCycleField setStringValue:@"---"];
		[cycleStartedField setStringValue:@"---"];
	}
}



#pragma mark ***Actions
- (void) locationAction:(id)sender
{
	[model setLocation:[sender intValue]];	
}

- (void) countAlarmLimitTextFieldAction:(id)sender
{
	[model setCountAlarmLimit:[sender floatValue]];	
}

- (void) maxCountsTextFieldAction:(id)sender
{
	[model setMaxCounts:[sender floatValue]];	
}
- (IBAction) startCycleAction:(id)sender
{
	[model startCycle];	
}

- (IBAction) stopCycleAction:(id)sender
{
	[model stopCycle];	
}

- (IBAction) cycleDurationAction:(id)sender
{
	[model setCycleDuration:[[sender selectedItem]tag]];	
}

- (IBAction) lockAction:(id) sender
{
    [gSecurity tryToSetLock:ORGT521Lock to:[sender intValue] forWindow:[self window]];
}

- (IBAction) readRecordAction:(id)sender
{
	[model getLastRecord];
}

- (IBAction) clearBufferAction:(id)sender
{
    [model clearBuffer];
}

#pragma mark •••Data Source
- (int) numberPointsInPlot:(id)aPlotter
{
	return [[model timeRate:[aPlotter tag]]   count];
}

- (void) plotter:(id)aPlotter index:(int)i x:(double*)xValue y:(double*)yValue
{
	int set = [aPlotter tag];
	int count = [[model timeRate:set] count];
	int index = count-i-1;
	*yValue = [[model timeRate:set] valueAtIndex:index];
	*xValue = [[model timeRate:set] timeSampledAtIndex:index];
}

@end
