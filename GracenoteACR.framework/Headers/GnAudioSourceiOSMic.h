/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

// This class requires that the application link to the Apple AudioToolbox Framework.
// Public header

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "GnAcrAudioConfig.h"


/** @addtogroup ios iOS
 *  \brief iOS specific APIs
 *  @{
 */


/** The GnAudioSourceDelegate protocol defines a delegate callback through which 
 *  audio samples will be delivered from the device's audio input. Classes that adopt 
 *  this protocol can use these audio samples as needed to save to memory or file, or to
 *  pass the audio to the ACR or MusicID "writeBytes" APIs.
 */
@protocol GnAudioSourceDelegate <NSObject>

/**
 *  The callback interface to receive audio samples from the GnAudioSourceiOSMic class.
 *  Classes that implement this interface will receive buffers of audio via the delegate 
 *  callback called on a high priority thread. Delegates should be careful to not block 
 *  this thread or do any expensive operations that my disrupt the real-time deadline of 
 *  delivering subsequent audio buffers.
 */
-(void)audioBytesReady:(void const * const)bytes length:(int)length;

@end




/** The GnAudioSourceiOSMic class implements a simplified interface to configure 
 *  and control the iOS audio input device for use with Gracenote SDKs. This is a convenience
 *  class and may not be suitable for every application. 
 *  This class does not assume or take responsibility for mic input interruptions or route changes. 
 *  This is the responsibility of the application. To learn more about handling these types of 
 *  interruptions, familiarize yourself with the AVAudioSession documentation from Apple.
 *  http://developer.apple.com/library/ios/#documentation/Audio/Conceptual/AudioSessionProgrammingGuide/Introduction/Introduction.html
 */
@interface GnAudioSourceiOSMic : NSObject 

/** A GnAudioSourceiOSMic object must be initialized with an GnAcrAudioConfig object. This config
 *  should repesent the same config that is needed to feed the writeBytes APIs of GnAcr or GnMusicID.
 */

-(id)initWithAudioConfig:(GnAcrAudioConfig*)config;

/** A GnAudioSourceiOSMic object must be initialized with an GnAcrAudioConfig object. This config
 *  should repesent the same config that is needed to feed the writeBytes APIs of GnAcr or GnMusicID.
 *  This API returns an error in case there is any error while using iOS audio APIs. 
 */

-(id)initWithAudioConfig:(GnAcrAudioConfig*)config error:(NSError**) error;

/** Activates audio session and starts the stream of audio data from the 
 *  device inputs (microphone) through the delegate callback.
 *  \deprecated This method is deprecated in version 1.5 and later
 */
-(NSError*)start  __attribute__((deprecated));

/** Deactivates audio session and stops the stream of audio data from the 
 *  device inputs (microphone) through the delegate callback.
 *  \deprecated This method is deprecated in version 1.5 and later
 */
-(NSError*)stop  __attribute__((deprecated));

/** Starts the stream of audio data from the microphone.
 *  Note: The audio session is owned by the applicaiton.
 */
-(NSError*)startMicrophone;

/** Stops the stream of audio data from the microphone.
 *  Note: The audio session is owned by the applicaiton.
 */
-(NSError*)stopMicrophone;


/** The application must set this delegate to receive audio callbacks from the 
 *  GnAudioSourceiOSMic object.
 */
@property (nonatomic, assign) id<GnAudioSourceDelegate>     audioDelegate;

@end
/** @} */ // end of ios
