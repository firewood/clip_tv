/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

// Public header

#import "GnObject.h"

/** @addtogroup SQLite SQLite
 *  \brief SQLite config APIs
 *  @{
 */

/** 
 * 
 *   GnStorageSqlite. An interface to configure local cache parameters.                                                      
 */
@interface GnStorageSqlite : GnObject

/** 
 * 
 *   Sets/Gets the folder path where storage file(s) can be created within or
 *   opened from.                                                      
 */
+(void)setStorageFolder:(NSString*)folderPath error:(NSError**)error;
+(NSString*)getStorageFolder;


/** 
 * 
 *   Sets/Gets the maximum size the cache can grow to; for example 100
 *   for 100 Kb or 1024 for 1 MB. This limit applies to each cache
 *   that is created.                                                           
 */
+(void)setStorageFileSize:(NSUInteger)size error:(NSError**)error;
+(NSUInteger)getStorageFileSize;



/** 
 * 
 *   Sets/Gets the maximum amount of memory SQLite can use to buffer cache data.
 */
+(void)setStorageMemorySize:(NSUInteger)size error:(NSError**)error;
+(NSUInteger)getStorageMemorySize;

@end
/** @} */ // end of SQLite
