/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import <UIKit/UIKit.h>
#import "SettingsDelegate.h"


#define TRANSITION_KEY  @"Transition"

#define SILENCE_KEY     @"Silence"
#define NSM_KEY         @"Noise, Speech, Music"
#define RATIO_KEY       @"Silence Ratio"

#define LOCAL_KEY       @"Local Query"
#define ONLINE_KEY      @"Online Query"

#define NETWORK_KEY     @"Network"
#define DEBUG_KEY       @"Debug"

#define ERROR_KEY       @"Error"
#define FP_KEY          @"Fingerprints"
#define MODE_KEY        @"Match Mode"

@interface SettingsController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (retain) NSArray *displaySettings;
@property (retain) NSArray *optimizationModes;

@property (assign) id <SettingsDelegate> settingsDelegate;

-(IBAction)settingsSwitch:(UISwitch*)sender;
-(IBAction)dismissMe:(id)sender;

@end
