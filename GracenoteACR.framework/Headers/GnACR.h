/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */



// Public header

#import <Foundation/Foundation.h>
#import "GnObject.h"
#import "GnUser.h"
#import "GnAcrAudioConfig.h"
#import "IGnAcrResultDelegate.h"
#import "IGnAcrStatusDelegate.h"


/** @addtogroup acr ACR 
 *  \brief ACR Query APIs
 *  @{
 */


/** The GnACR object is responsible for making ACR queries. 
 *  To use this object, initialize it with an GnAcrAudioConfig and then write bytes of PCM 
 *  audio data of that format. Results and Status will be returned asyncronously via the 
 *  statusDelegate and resultDelegate that you set on the object.
 */
@interface GnACR : GnObject


/**
 *  Initialzes a new GnACR object with the Application's GnUser object.
 */
-(id)initWithUser:(GnUser*)user
            error:(NSError**)error;


/**
 *  Calling doManualLookup will request the system to return a result ASAP. This is only a request. 
 *  Depending on the load of the system and other factors, the request may not be honored 
 *  for several seconds.
 */
-(NSError*)doManualLookup;


/**
 *  Informs the ACR object what format the audio bytes will be. The bytes written 
 *  via calls to writeBytes ahould be of this format.
 */
-(NSError*)audioInitWithAudioConfig:(GnAcrAudioConfig*)config; 

/** 
 *  Inspect the audio config supplied via the audioInitWithAudioConfig API
 */ 
@property (nonatomic, readonly)     GnAcrAudioConfig* audioConfig;


/**
 *  USe this API to write PCM audio data to the ACR object. The PCM data should be of the 
 *  same format specified in the GnAcrAudioConfig object. Buffers of consistent length representing 
 *  less than a second of PCM data are best.
 */
-(NSError*)writeBytes:(void const * const)bytes length:(int)length;



/**
 *  Sets the object on which status callbacks will be called. See IGnAcrStatusDelegate for more info.
 */
@property (nonatomic, assign) id<IGnAcrStatusDelegate> statusDelegate;

/**
 *  Sets the object on which result callbacks will be called. See IGnAcrResultDelegate for more info.
 */
@property (nonatomic, assign) id<IGnAcrResultDelegate> resultDelegate;


/**
 *  Sets the maximum number of seconds allowed between continuous consecutive queries. 
 *  TODO: Default and range need to be verified
 */
@property (nonatomic, assign) NSTimeInterval    preferredMaxQueryInterval;


/**
 *  Sets the maximum number of seconds allowed between continuous consecutive local queries.
 *  TODO: Default and range need to be verified
 */
@property (nonatomic, assign) NSTimeInterval    preferredMaxLocalQueryInterval;


/** 
 *   Configurable number of no matches before increasing back off timer
 *   Default is "60". This means after 60 no matches the SDK will go into
 *   no match mode
 */
@property (nonatomic, assign) unsigned          noMatchModeTriggerLimit;

/**
 *   Configurable time increment to add to back off timer
 *   
 *   Default is "60". This means 60 seconds will be added to the time between
 *   lookups every time we have noMatchModeTriggerLimit no matches.
 *
 *   Valid range is 8 to 2592000 seconds (30 days)
 */
@property (nonatomic, assign) unsigned          noMatchModeTimeIncrement;

/**
 *   Configurable maximum time for no match mode
 *
 *   Default value is 300 seconds (5 minutes). This means that we will stop applying the
 *   noMatchModeTimeIncrement value after we have reached 300 seconds.
 *
 *   Valid range is 60 to 5184000 seconds (60 days)
 */
@property (nonatomic, assign) unsigned          noMatchModeMaxTime;

/**
 *
 *   Sets ACR queries to be optimized for different GnAcrOptimization Modes
 *
 *   Default value is for accuracy. Optimizing for speed could result in
 *   slightly faster responses but they will not be as accurate.
 */
@property (nonatomic, assign) NSString*         optimizationMode;

/**
 *
 *   Set to YES to restict lookups to local cache. 
 *   Set to NO to allow online lookups. Default is NO.
 */
@property (nonatomic, assign) BOOL              lookupCacheOnly;


/** @name GnAcrOptimization
 *  Options for optimizationMode
 */
///@{
extern  NSString * const GnAcrOptimizationDefault;
extern  NSString * const GnAcrOptimizationAccuracy;
extern  NSString * const GnAcrOptimizationSpeed;
extern  NSString * const GnAcrOptimizationAdaptive;
///@}




@end

/** @} */ // end of acr

