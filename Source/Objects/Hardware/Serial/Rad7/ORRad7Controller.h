//--------------------------------------------------------
// ORRad7Controller
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

@class ORPlotView;

@interface ORRad7Controller : OrcaObjectController
{
    IBOutlet NSTextField*   lockDocField;
	IBOutlet NSButton*		makeFileCB;
	IBOutlet NSButton*		verboseCB;
	IBOutlet NSButton*		deleteDataOnStartCB;
	IBOutlet NSTextField*	runToPrintTextField;
	IBOutlet NSTextField*	runStateTextField;
	IBOutlet NSTextField*   operationStateField;
	IBOutlet NSPopUpButton* rUnitsPU;
	IBOutlet NSPopUpButton* tUnitsPU;
	IBOutlet NSPopUpButton* formatPU;
	IBOutlet NSPopUpButton* tonePU;
	IBOutlet NSPopUpButton* pumpModePU;
	IBOutlet NSPopUpButton* thoronPU;
	IBOutlet NSPopUpButton* modePU;
	IBOutlet NSPopUpButton* protocolPU;
	IBOutlet NSTextField*   recycleTextField;
	IBOutlet NSTextField*   cycleTimeTextField;
    IBOutlet NSButton*      lockButton;
    IBOutlet NSTextField*   portStateField;
    IBOutlet NSPopUpButton* portListPopup;
    IBOutlet NSPopUpButton* pollTimePopup;
    IBOutlet NSButton*      openPortButton;
    IBOutlet NSButton*      updateSettingsButton;
    IBOutlet NSTextField*   timeField;
	IBOutlet ORPlotView*    plotter0;
	
	IBOutlet NSButton*		startTestButton;
	IBOutlet NSButton*		stopTestButton;
	IBOutlet NSButton*		initHWButton;
	IBOutlet NSButton*		loadDialogButton;
	IBOutlet NSButton*		saveUserProtocolButton;
	IBOutlet NSButton*		eraseAllDataButton;
	IBOutlet NSButton*		printRunButton;
	IBOutlet NSButton*		printCycleButton;

	//status fields
	IBOutlet NSTextField*   freeCyclesField;
	IBOutlet NSTextField*   stateField;
	IBOutlet NSTextField*   runNumberField;
	IBOutlet NSTextField*   cycleNumberField;
	IBOutlet NSTextField*   pumpModeField;
	IBOutlet NSTextField*   countDownField;
	IBOutlet NSTextField*   countsField;
	IBOutlet NSTextField*   lastRunNumberField;
	IBOutlet NSTextField*   lastCycleNumberField;
	IBOutlet NSTextField*   lastRadonField;
	IBOutlet NSTextField*   lastRadonUnitsField;
	IBOutlet NSTextField*   lastRadonUncertaintyFieldField;
	IBOutlet NSTextField*   uncertaintyField;
	IBOutlet NSTextField*   temperatureField;
	IBOutlet NSTextField*   temperatureUnitsField;
	IBOutlet NSTextField*   rhField;
	IBOutlet NSTextField*   batteryField;
	IBOutlet NSTextField*   pumpCurrentField;
	IBOutlet NSTextField*   hvField;
	IBOutlet NSTextField*   signalField;
	
	IBOutlet NSTabView*		protocolTabView;
	IBOutlet NSTextField*   userModeField;
	IBOutlet NSTextField*   userPumpModeField;
	IBOutlet NSTextField*   userThoronField;
	IBOutlet NSTextField*   useCycleField;
	IBOutlet NSTextField*   userRecycleField;

	
}

#pragma mark ***Initialization
- (id) init;
- (void) dealloc;
- (void) awakeFromNib;

#pragma mark ***Notifications
- (void) registerNotificationObservers;
- (void) updateWindow;

#pragma mark ***Interface Management
- (void) makeFileChanged:(NSNotification*)aNote;
- (void) verboseChanged:(NSNotification*)aNote;
- (void) deleteDataOnStartChanged:(NSNotification*)aNote;
- (void) runToPrintChanged:(NSNotification*)aNote;
- (void) runStateChanged:(NSNotification*)aNote;
- (void) updateButtons;
- (void) operationStateChanged:(NSNotification*)aNote;
- (void) tUnitsChanged:(NSNotification*)aNote;
- (void) rUnitsChanged:(NSNotification*)aNote;
- (void) formatChanged:(NSNotification*)aNote;
- (void) toneChanged:(NSNotification*)aNote;
- (void) pumpModeChanged:(NSNotification*)aNote;
- (void) thoronChanged:(NSNotification*)aNote;
- (void) modeChanged:(NSNotification*)aNote;
- (void) recycleChanged:(NSNotification*)aNote;
- (void) cycleTimeChanged:(NSNotification*)aNote;
- (void) protocolChanged:(NSNotification*)aNote;
- (void) lockChanged:(NSNotification*)aNote;
- (void) portNameChanged:(NSNotification*)aNote;
- (void) portStateChanged:(NSNotification*)aNote;
- (void) pollTimeChanged:(NSNotification*)aNote;
- (void) statusChanged:(NSNotification*)aNote;

- (void) miscAttributesChanged:(NSNotification*)aNotification;
- (void) scaleAction:(NSNotification*)aNotification;
- (void) updatePlot:(NSNotification*)aNote;

#pragma mark ***Actions
- (IBAction) makeFileAction:(id)sender;
- (IBAction) verboseAction:(id)sender;
- (IBAction) deleteDataOnStartAction:(id)sender;
- (IBAction) runToPrintTextFieldAction:(id)sender;
- (IBAction) rUnitsAction:(id)sender;
- (IBAction) tUnitsAction:(id)sender;
- (IBAction) formatAction:(id)sender;
- (IBAction) toneAction:(id)sender;
- (IBAction) pumpModeAction:(id)sender;
- (IBAction) thoronAction:(id)sender;
- (IBAction) modeAction:(id)sender;
- (IBAction) recycleTextFieldAction:(id)sender;
- (IBAction) cycleTimeTextFieldAction:(id)sender;
- (IBAction) protocolAction:(id)sender;
- (IBAction) lockAction:(id) sender;
- (IBAction) portListAction:(id) sender;
- (IBAction) openPortAction:(id)sender;
- (IBAction) updateSettingsAction:(id)sender;
- (IBAction) pollTimeAction:(id)sender;
- (IBAction) initAction:(id)sender;
- (IBAction) getStatusAction:(id)sender;
- (IBAction) startAction:(id)sender;
- (IBAction) stopAction:(id)sender;
- (IBAction) dumpUserValuesAction:(id)sender;
- (IBAction) saveUserSettings:(id)sender;
- (IBAction) eraseAllDataAction:(id)sender;
- (IBAction) printRunAction:(id)sender;
- (IBAction) printDataInProgress:(id)sender;

#pragma mark ***Data Source
- (double) plotterStartTime:(id)aPlotter;
- (int) numberPointsInPlot:(id)aPlotter;
- (void) plotter:(id)aPlotter index:(int)i x:(double*)xValue y:(double*)yValue;

@end


