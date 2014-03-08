/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import <UIKit/UIKit.h>
#import "common.h"
#import "SettingsController.h"
// for audio session delegate
#import <AVFoundation/AVFoundation.h>
#import "CustomerCredentials.h"
#import "GnCircularBuffer.h"
#import "SettingsDelegate.h"

#define ADAPTIVE_KEY  @"ADAPTIVE"


@interface GN_ACR_SDKViewController : UIViewController <IGnAcrResultDelegate, IGnAcrStatusDelegate, AVAudioSessionDelegate, GnAudioSourceDelegate, GnFPCacheSourceDelegate, SettingsDelegate, UIWebViewDelegate>
{
    UIWebView* webView_;
    BOOL isWebViewReady_;

    IBOutlet UITextView *statusTextView;
    IBOutlet UITextView *resultsTextView;
    IBOutlet UIButton   *buttonACR;
    GnACR               *mACR;
    GnSdkManager        *mManager;
    GnUser              *mUserACR;
    GnAudioSourceiOSMic *mSource;

#if ENABLE_MUSIC_ID
    GnUser              *mUserMusic;
    GnCircularBuffer    *mAudioCache;
    GnMusicID           *mMusicQuery;
#endif
    IBOutletCollection(UIButton) NSArray *buttonCollection;
    
    SettingsController  *mSettingsController;
    
    // for followup query
    GnAcrMatch          *mLatestAcrMatch;
    
    // for loading FP bundles
    NSFileHandle        *bundleFileHandle;
    BOOL                mIsAdaptive;
}

// ACR methods
-(IBAction)acrButtonPressed:(UIButton*)sender;
-(IBAction)secondaryQueryButtonPressed:(UIButton*)sender;
-(IBAction)doManualLookUp;

// MusicID methods
-(IBAction)doMusicID;

// Utility
-(IBAction)settingsButtonPressed;

-(IBAction)settingsSwitch:(UISwitch*)sender;
// loading FP bundles
-(IBAction)loadFPBundle:(id)sender;


-(void)updateStatusMessage:(NSString *)msg;
-(void)updateResultMessage:(NSString *)msg;




@end

