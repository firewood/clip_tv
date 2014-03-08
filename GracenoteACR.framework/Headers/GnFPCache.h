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

/** @addtogroup LocalFP Local FP Cache
 *  \brief Local fingerprint Management APIs
 *  @{
 */

/** The GnFPCacheSourceDelegate protocol defines an interface through which the application supplies bundle data to be ingested. 
 *  The readBundleData:capacity:numBytesRead callback will be called on the delegate when the system requests to data to ingest. The 
 *  application initaites this process by calling the ingest:error: method below. 
 *  The delegate is given a a data buffer and a capacity. The application should write data into the buffer up to capacity bytes. 
 *  The application should update the numBytesRead value to reflect the actual number of bytes written to the data buffer. Updating 
 *  numBytesRead to zero indicated there is no more data to ingest.
 *  The return value should be used to indicate if an error occurred (file i/o, newtork failue, etc.).  Returning  YES indicates 
 *  that an error occured, at which point the ingestion will be aborted.
 */
@protocol GnFPCacheSourceDelegate <NSObject>

-(BOOL)readBundleData:(void*)data
             capacity:(size_t)capacity
         numBytesRead:(size_t*)numBytesRead;

@end
 


/** The GnFPCache is a static class interface for managing Fingerprint Cache Bundles.
 *  This API can be used to ingest bundle data, to set and purge local storage for ingested data
 */
@interface GnFPCache : GnObject

/** Call this method to initiate the ingestion of bundle data. The delegate is 
 *  responsible for supplying the bundle data via the GnFPLocalSourceDelegate protocol.
 */
+(int)ingest:(id<GnFPCacheSourceDelegate>)sourceDelegate error:(NSError**)error;


/** Use this API to set a local storage location for ingested bundle data. 
 *  This location will be used internally by the system to cache bundle data to disk. This storage location 
 *  is unrelated to the source data used for ingestion.
 */
+(int)setStorageFolder:(NSString*)folderPath error:(NSError**)error;


/** Use this API to clear all cached fingerprint data from the GnFPCache system.
 */
+(void)clearCache;



@end
/** @} */ // end of LocalFP
