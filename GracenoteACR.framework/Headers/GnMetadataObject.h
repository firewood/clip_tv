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
#import "GnID.h"
#import "GnLocale.h"


/** @addtogroup metadata Metadata (General) 
 *  \brief General Metadata Classes
 *  @{
 */



/** The GnMetadataObject is the base class for all metadata objects in the SDK. 
 *  Subclasses contain most of the useful functionality.
 */
@interface GnMetadataObject : GnObject 



/** 
 *  initialize a new object with ID, Tag and sourcetype.
 */
-(id)initWithID:(NSString*)ID tag:(NSString*)tag idSource:(NSString*)idSource;



-(void)setLocale:(GnLocale*)locale error:(NSError**) error;


@end

/** @} */ // End of metadata
