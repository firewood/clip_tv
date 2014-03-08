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
#import "GnLocale.h"
#import "GnLogs.h"

/** @addtogroup manager Manager 
 *  \brief SDK Manager APIs
 *  @{
 */


typedef enum {
    SDKTypeManager      = 1<<0,
    SDKTypeACR          = 1<<1,
    SDKTypeMusicID      = 1<<2,
    SDKTypeMusicIDFile  = 1<<3,
    SDKTypeVideo        = 1<<4,
    SDKTypeLink         = 1<<5,
    SDKTypeDSP          = 1<<6,
    SDKTypeMusicMatch   = 1<<7,
    SDKTypeSubmit       = 1<<8,
    SDKTypeStorage      = 1<<9,
    SDKTypeEPG          = 1<<10,
    SDKTypeFPLocal      = 1<<11
}SDKType;


@interface GnSdkManager : NSObject 



-(id)initWithLicense:(NSString*)licenseData error:(NSError**)error;

-(NSString*)productVersion;
-(NSString*)version;
-(NSString*)buildDate;

-(NSError*)initializeSDK:(SDKType)sdkType;
-(BOOL)isSDKInitialized:(SDKType)sdkType;


// Set locales for SDK
@property (atomic, retain)      GnLocale*   defaultLocaleMusic;
@property (atomic, retain)      GnLocale*   defaultLocaleVideo;
@property (atomic, retain)      GnLocale*   defaultLocaleEPG;

// logging
@property (nonatomic, readonly) GnLogs*     logs;


// TODO: list





@end
/** @} */ // End of Manager

