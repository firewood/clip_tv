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

/** @addtogroup manager Manager 
 *  SDK Manager APIs
 *  @{
 */



/** 
 *  These represent the various levels of logging severity.
 *  They are used to filter the log for entries of the desired severity only.
 *  They can be treated as a bitmask and combined for bitwise-OR.
 */
typedef enum
{
    GnLogFilterAll      =   0xF,
    GnLogFilterError    =   0x1,
    GnLogFilterWarning  =   0x2,
    GnLogFilterDebug    =   0x4,
    GnLogFilterInfo     =   0x8    
}GnLogFilter;


/** 
 *  These values represent different options for the log output. 
 *  They can be treated as a bitmask and combined for bitwise-OR.
 */
typedef enum 
{
    GnLogFieldAll           =   0xFF000000,     /// Includes all log options
    GnLogFieldTimestamp     =   0x01000000,     /// Includes a log creation timestamp of the format: Wed Jan 30 18:56:37 2008
    GnLogFieldCategory      =   0x02000000,     /// Categorizes the log entries by headings such as ERROR, INFO, and so on. 
    GnLogFieldPackage       =   0x04000000,     /// Includes the Package Name, or the Package ID if the name is unavailable. 
    GnLogFieldThread        =   0x08000000,     /// Includes the Thread ID.
    GnLogFieldSourceInfo    =   0x10000000,     /// Includes the source information in the format: FILE_(_INFO_) 
    GnLogFieldNewLine       =   0x20000000,     /// Includes a trailing newline in the format: rn 
    GnLogFieldNone          =   0x00000000      /// Indicates to not include any extra information in the log. 
}GnLogField;

/** 
 *  These represent the various packages or modules that support logging. 
 *  They are used to filter the log for entries of the desired packages only.
 *  They can be treated as a bitmask and combined for bitwise-OR.
 *
 *  The application can add custom logging by including a GnLogPackage value between
 *  GnLogPackageAppStart and GnLogPackageMaxID, and using the GnLogs write API.
 */
typedef enum
{
    GnLogPackageAll         =   0xFF,
    GnLogPackageGCSL        =   0x7F,
    GnLogPackageGNSDK       =   0xFE,
    GnLogPackageSDKManager  =   0x80,
    GnLogPackageMusicID     =   0x81,
    GnLogPackageMusicIDFile =   0x82,
    GnLogPackageLink        =   0x84,
    GnLogPackageVideo       =   0x85,
    GnLogPackageSubmit      =   0x86,
    GnLogPackageStreamID    =   0x87,
    GnLogPackageSQLite      =   0xA0,
    GnLogPackageDSP         =   0xA1,
    GnLogPackageMusicMatch  =   0xA2,
    GnLogPackageACR         =   0xA4,
    GnLogPackageLookupLocal =   0xA5,
    GnLogPackageEPG         =   0xA7,
    
    GnLogPackageAppStart    =   0xE0,
    GnLogPackageMaxID       =   0xFD
}GnLogPackage;


@interface GnLogOption : NSObject

/** 
 *  Maximum size of log before new log is created. Enter a value of zero (0) to always create new log 
 */
@property (nonatomic, assign)   NSUInteger      maxSize;

/** 
 *  The mask of GnLogPackage values to apply to the log. 
 */
@property (nonatomic, assign)   GnLogPackage    packageFilter;

/** 
 *  The name of a custom app log package (optional)
 */
@property (nonatomic, retain)   NSString*       packageName;

/** 
 *  The mask of GnLogFilter values to apply to the log
 */
@property (nonatomic, assign)   GnLogFilter     entryFilter;

/** 
 *  The mask of GnLogField values to apply to the log
 */
@property (nonatomic, assign)   GnLogField      fields;

/** 
 *  Specify YES for the archive to retain and rename old logs, or NO to delete old logs 
 */
@property (nonatomic, assign)   BOOL            isArchived;

@end
/** @} */ // End of Manager
