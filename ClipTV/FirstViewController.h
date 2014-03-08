//
//  FirstViewController.h
//  ClipTV
//
//  Created by Kenichi Aramaki on 2014/03/08.
//  Copyright (c) 2014年 SeeM. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "common.h"
#import "SettingsController.h"
#import "CustomerCredentials.h"
#import "GnCircularBuffer.h"
#import "SettingsDelegate.h"

#define ADAPTIVE_KEY  @"ADAPTIVE"


@interface FirstViewController : UIViewController <IGnAcrResultDelegate, IGnAcrStatusDelegate, AVAudioSessionDelegate, GnAudioSourceDelegate, GnFPCacheSourceDelegate, SettingsDelegate, UIWebViewDelegate>
{
    UIWebView* webView_;
    BOOL isWebViewReady_;
    
    GnACR               *mACR;
    GnSdkManager        *mManager;
    GnUser              *mUserACR;
    GnAudioSourceiOSMic *mSource;
    
#if ENABLE_MUSIC_ID
    GnUser              *mUserMusic;
    GnCircularBuffer    *mAudioCache;
    GnMusicID           *mMusicQuery;
#endif

    // for followup query
    GnAcrMatch          *mLatestAcrMatch;
    
    // for loading FP bundles
    NSFileHandle        *bundleFileHandle;
    BOOL                mIsAdaptive;
}


@end
