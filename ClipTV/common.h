/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import <UIKit/UIKit.h>

// subset of ACR/EPG/Video classes
#import "GracenoteACR/GnACR.h"
#import <GracenoteACR/GnVideo.h>
#import <GracenoteACR/GnVideoTitle.h>
#import <GracenoteACR/GnVideoWork.h>
#import <GracenoteACR/GnSdkManager.h>
#import <GracenoteACR/GnUser.h>
#import <GracenoteACR/GnLocale.h>
#import <GracenoteACR/GnResult.h>
#import <GracenoteACR/GnLocaleSetting.h>
#import <GracenoteACR/GnAcrMatch.h>
#import <GracenoteACR/IGnAcrResultDelegate.h>
#import <GracenoteACR/IGnAcrStatusDelegate.h>
#import <GracenoteACR/GnAcrStatus.h>
#import <GracenoteACR/GnAcrAudioConfig.h>
#import <GracenoteACR/GnAcrAudioConfig.h>
#import <GracenoteACR/GnEPG.h>
#import <GracenoteACR/GnStorageSqlite.h>
#import <GracenoteACR/GnAudioSourceiOSMic.h>


// subset of Music ID classes
#import <GracenoteACR/GnMusicID.h>
#import <GracenoteACR/GnTrack.h>

#import <GracenoteACR/GnFPCache.h>



//#define AppLog(format, ...) NSLog(@"AppLog:%@",[NSString stringWithFormat:format, ## __VA_ARGS__])
#define AppLog(format, ...) 

//#define ENABLE_BUTTONS

