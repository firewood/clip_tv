/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import <Foundation/Foundation.h>
@interface GnCircularBuffer : NSObject


-(id)initWithCapacity:(NSUInteger)numBytes;

-(int)writeBytes:(void const * const)bytes length:(int)length;
-(int)readBytes:(void * const)bytes length:(int)length;

@property (atomic, readonly) NSUInteger length;

@end
