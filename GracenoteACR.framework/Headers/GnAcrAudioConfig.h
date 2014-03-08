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

/** @addtogroup acr ACR 
 *  \brief ACR Query APIs
 *  @{
 */




/**
 *  The audio algorith that the intenal fingerprinter will use. 
 *  This should be set to GnAcrAudioSourceMic for most cases.
 */
typedef enum 
{
    GnAcrAudioSourceMic,
    GnAcrAudioSourceLineIn
}GnAcrAudioSourceType;

/**
 *  The sample format of the audio PCM data to be fed to the GnACR object via the writeBytes API. 
 *  GnAcrAudioSampleFormatPCM8 is signed 8-bit integer linear PCM data.
 *  GnAcrAudioSampleFormatPCM16 is signed 16-bit integer linear PCM data. Little endian.
 */
typedef enum 
{
    GnAcrAudioSampleFormatPCM8      = 1,
    GnAcrAudioSampleFormatPCM16     = 2,
}GnAcrAudioSampleFormat;

/**
 *  These are the audio sample rates accepted by the ACR system. 
 *  GnAcrAudioSampleRate44100 is recommended for best performance on mobile devices.
 */
typedef enum
{
    GnAcrAudioSampleRate8000     = 8000,
    GnAcrAudioSampleRate44100    = 44100,
    GnAcrAudioSampleRate48000    = 48000,
}GnAcrAudioSampleRate;



/**
 *  The GnAcrAudioConfig object encapsulates all the information needed to fully configure 
 *  the GnACR object for audio input.
 */
@interface GnAcrAudioConfig : NSObject



/**
 *  A convenience method for creating the suggested configuration for mobile devices.
 *  GnAcrAudioSampleRate44100
 *  GnAcrAudioSampleFormatPCM16
 *  GnAcrAudioSourceMic
 *  1 channel (mono)
 */
+(GnAcrAudioConfig*)suggestedConfigMobile;



/**
 *  Initializes a new GnAcrAudioConfig with the specified parameters. 
 *  numChannels should be either 1 (mono) or 2 (stereo)
 */
-(id)initWithAudioSourceType:(GnAcrAudioSourceType)audioSourceType 
           sampleRate:(GnAcrAudioSampleRate)sampleRate 
                 format:(GnAcrAudioSampleFormat)format 
            numChannels:(NSUInteger)numChannels;



/**
 *  A property to access the GnAcrAudioAlgorithm of the GnAcrAudioConfig object.
 */
@property (nonatomic, readonly) GnAcrAudioSourceType       audioSourceType;
/**
 *  A property to access the GnAcrAudioSampleRate of the GnAcrAudioConfig object.
 */
@property (nonatomic, readonly) GnAcrAudioSampleRate      sampleRate;
/**
 *  A property to access the GnAcrAudioSampleFormat of the GnAcrAudioConfig object.
 */
@property (nonatomic, readonly) GnAcrAudioSampleFormat    format;
/**
 *  A property to access the number of channels of the GnAcrAudioConfig object.
 */
@property (nonatomic, readonly) NSUInteger                numChannels;


@end
/** @} */ // end of acr

