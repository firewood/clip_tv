/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import <UIKit/UIKit.h>

@class GN_ACR_SDKViewController;

@interface GN_ACR_SDKAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
    GN_ACR_SDKViewController *viewController;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet GN_ACR_SDKViewController *viewController;

@end

