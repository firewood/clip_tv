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
#import "GnLogOption.h"

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */


/** 
 *  For use with the writeToLog API
 */
typedef enum
{
    GnLogEntryTypeError     = GnLogFilterError,
    GnLogEntryTypeWarning   = GnLogFilterWarning,
    GnLogEntryTypeDebug     = GnLogFilterDebug,
    GnLogEntryTypeInfo      = GnLogFilterInfo
}GnLogEntryType;

/** 
 *  Manages logging for the SDK. Enable/diable logging to file. Write custom log entries.
 */
@interface GnLogs : NSObject

/** 
 *  Enables logging to a specified file, with the given options
 */
-(void)enableLogging:(NSString*)filename options:(GnLogOption*)options error:(NSError**)error;

/** 
 *  Disables logging to a specified file.
 */
-(void)disableLogging:(NSString*)filename error:(NSError**)error;

/** 
 *  Call this to write custom log entires into the log. 
 */
-(void)writeToLog:(int)sourceLine                                  
   sourceFilename:(NSString*)sourceFilename    
            entry:(NSString*)entry             
        entryType:(GnLogEntryType)entryType 
        packageID:(GnLogPackage)packageID 
            error:(NSError**)error;

@end
/** @} */ // End of Manager
