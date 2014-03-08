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

/** @addtogroup acr ACR 
 *  \brief ACR Query APIs
 *  @{
 */



/**
 * Specifies the status of an operation as it progresses.
 */
typedef enum {

	/**
	 * ACR has started receiving PCM audio.
	 */
	GnAcrStatusTypeRecordingStarted,

	/**
	 * ACR status type Debug. Further info may be contained in the message
     * property of the GnAcrStatus object.
	 */
	GnAcrStatusTypeDebug,

	/**
	 * ACR query process has begun.
	 */
	GnAcrStatusTypeQueryBegin,

	/**
	 * Connecting to the Gracenote Service.
	 */
	GnAcrStatusTypeConnecting,

	/**
	 * Sending ACR query data to the Gracenote Service.
	 */
	GnAcrStatusTypeNetworkSending,

	/**
	 * Receiving ACR result data from the Gracenote Service.
	 */
	GnAcrStatusTypeNetworkReceiving,

	/**
	 * ACR audio fingerprint generation has started.
	 */
	GnAcrStatusTypeFingerprintStarted,

	/**
	 * ACR audio fingerprint generation has completed.
	 */
	GnAcrStatusTypeFingerprintGenerated,

	/**
	 * Silence detected.
	 * The value propery will return the number of seconds of continuous silence previous to now.
	 */
	GnAcrStatusTypeSilent,

	/**
	 * Music detected
	 */
	GnAcrStatusTypeMusic,

	/**
	 * Speech detected
	 */
	GnAcrStatusTypeSpeech,

	/**
	 * Noise (non-pitched sound) detected.
	 */
	GnAcrStatusTypeNoise,

    /**
	 * This status communicates the ratio of silent content to non-silent
     *  content of the previous 3 seconds of audio data. This value will be in the
     *  "value" property of the status object.
     */
    GnAcrStatusTypeSilentRatio,

	/**
	 * ACR has completed a query to the local database.
	 */
	GnAcrStatusTypeLocalLookupComplete,

	/**
	 * ACR has completed a query to the online database.
	 */
	GnAcrStatusTypeOnlineLookupComplete,

	/**
	 * ACR status has an error.  The "error" property of the GnAcrStatus object will
     *  contain a descriptive NSError object.
	 */
	GnAcrStatusTypeError,

	/**
	 * ACR detected a transition in the audio content.
	 */
	GnAcrStatusTypeTransition,

	/**
	 * ACR has switched to "No Match Mode". After a configuable numner of "no matches",
     *  the system will enter this mode to reduce the querly load.
	 */
	GnAcrStatusTypeNoMatchMode,

	/**
	 * ACR has returned to "Normal Match Mode". Normal query intervals will resume.
     *  This is typically triggered by a successful match.
	 */
	GnAcrStatusTypeNormalMatchMode

} GnAcrStatusType;



/**
 *  A GnAcrStatus ob ject encapulates all the status communicated to the statusDelegate of the GnACR object
 */
@interface  GnAcrStatus : NSObject


/**
 *  This is an internal helper function create GnAcrStatus objects. There is no reason your
 *  application should need to create these.
 */
-(GnAcrStatus*) initWithType:(GnAcrStatusType)type value:(float)value message:(NSString*)message error:(NSError*)error;


/**
 *  The GnAcrStatusType enum related to this object.
 */
@property (nonatomic, readonly)     GnAcrStatusType     statusType;

/**
 *  The value related to this object. Only valid for GnAcrStatusTypeSilent and GnAcrStatusTypeSilentRatio.
 */
@property (nonatomic, readonly)     float               value;

/**
 *  The NSError related to this object. Only valid for GnAcrStatusTypeError.
 */
@property (nonatomic, readonly)     NSError*            error;

/**
 *  The NSString related to this status, if any. May often be nil.
 */
@property (nonatomic, readonly)     NSString*            message;


@end
/** @} */ // end of acr

