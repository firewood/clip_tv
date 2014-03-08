/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

#import "GnCircularBuffer.h"
#import <string.h>

@implementation GnCircularBuffer
{
    char *mData;
    NSUInteger mReadIndex;
    NSUInteger mWriteIndex;
    NSUInteger mCapacity;
    NSUInteger mLength;
}

@synthesize length = mLength;

-(void)dealloc
{
    if (mData) {
        free(mData);
        mData = nil;
    }
    [super dealloc];
}

-(id)initWithCapacity:(NSUInteger)numBytes
{
    if (numBytes == 0) {
        return nil;
    }
    
    self = [super init];
    if (self)
    {
        mData        = malloc(numBytes);
        mCapacity    = numBytes;
        mReadIndex   = 0;
        mWriteIndex  = 0;
        mLength      = 0;
    }
    return self;
}



-(int)writeBytes:(void const * const)bytes length:(int)length
{
    @synchronized(self)
    {
        char const * const inData = bytes;
        NSInteger overFlow = length + mLength - mCapacity;
        if (overFlow > 0) {
            // incoming data too large
            // ignore newest data
            length-= overFlow;
        }
        
        NSInteger wrapAround = mWriteIndex + length - mCapacity;
        
        if (wrapAround <= 0) {
            // normal situation: write all data contiguously
            char *dest = mData + mWriteIndex;
            char const *source = inData;
            memcpy(dest, source, length);
        }
        else
        {
            // wrap around situation
            // write first block at end of buffer
            char *dest = mData + mWriteIndex;
            char const * source = inData;
            memcpy(dest, source, length - wrapAround);
            
            // then write rest of data at begining of buffer
            dest = mData;
            source = inData + (length - wrapAround);
            memcpy(dest, source, wrapAround);
            
        }
        
        mLength += length;
        mWriteIndex = (mWriteIndex + length) % mCapacity;

    }
    
    return length;
    
}


-(int)readBytes:(void * const)bytes length:(int)length
{
    @synchronized(self)
    {
        char *inData = bytes;
        NSInteger underflow = length - mLength;
        if (underflow > 0) {
            // not enough data to fill request
            // adjust output
            length-= underflow;
        }
        
        NSInteger wrapAround = mReadIndex + length - mCapacity;
        
        if (wrapAround <= 0) {
            // normal situation: write all data contiguously
            char *source = mData + mReadIndex;
            char *dest = inData;
            memcpy(dest, source, length);
        }
        else
        {
            // wrap around situation
            // write first block at end of buffer
            char *source = mData + mReadIndex;
            char *dest = inData;
            memcpy(dest, source, length - wrapAround);
            
            // then write rest of data at begining of buffer
            source = mData;
            dest = inData + (length - wrapAround);
            memcpy(dest, source, wrapAround);
            
        }
        
        mLength -= length;
        mReadIndex = (mReadIndex + length) % mCapacity;

    }
    
    return length;
    
}

//-(NSString*)description
//{
//    NSMutableString *desc = [NSMutableString stringWithCapacity:mCapacity];
//    
//    for (int i = 0; i<mCapacity; ++i) {
//        [desc appendFormat:@"%d, ", mData[i] ];
//    }
//    
//    return desc;
//}


@end
