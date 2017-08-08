//
//  ORIpeCardDecoder.h
//  Orca
//
//  Created by Mark Howe on 10/18/05.
//  Copyright 2004 CENPA, University of Washington. All rights reserved.
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
#import "ORIpeCardDecoder.h"
#import "ORKatrinV4FLTDefs.h"

@class ORDataSet;
@interface ORKatrinV4FLTDecoderForEnergy : ORIpeCardDecoder {
@protected
	BOOL getRatesFromDecodeStage;
    BOOL getFifoFlagsFromDecodeStage;
    unsigned char oldFifoFlags[kNumV4FLTChannels];
	NSMutableDictionary* actualFlts;
}

// Documentation in m-file
- (unsigned long) decodeData:(void*)someData fromDecoder:(ORDecoder*)aDecoder intoDataSet:(ORDataSet*)aDataSet;
- (NSString*) dataRecordDescription:(unsigned long*)dataPtr;
@end

@interface ORKatrinV4FLTDecoderForWaveForm : ORKatrinV4FLTDecoderForEnergy {
}
// Documentation in m-file
- (unsigned long) decodeData:(void*)someData fromDecoder:(ORDecoder*)aDecoder intoDataSet:(ORDataSet*)aDataSet;
- (NSString*) dataRecordDescription:(unsigned long*)dataPtr;
@end

@interface ORKatrinV4FLTDecoderForHitRate : ORIpeCardDecoder {
}
- (unsigned long) decodeData:(void*)someData fromDecoder:(ORDecoder*)aDecoder intoDataSet:(ORDataSet*)aDataSet;
- (NSString*) dataRecordDescription:(unsigned long*)ptr;
@end

@interface ORKatrinV4FLTDecoderForHistogram : ORIpeCardDecoder {
@protected
	BOOL getHistoReceivedNoteFromDecodeStage;
    unsigned char oldFifoFlags[kNumV4FLTChannels];
	NSMutableDictionary* actualFlts;
}
- (unsigned long) decodeData:(void*)someData fromDecoder:(ORDecoder*)aDecoder intoDataSet:(ORDataSet*)aDataSet;
- (NSString*) dataRecordDescription:(unsigned long*)ptr;
@end

