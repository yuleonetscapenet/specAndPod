//
//  NSURL+AXSSDKMobile.h
//  AXSSDKMobile
//
//  Created by Wilson Lei on 6/11/15.
//  Copyright (c) 2015 AXS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSURL (AXSSDKMobile)

/**
 *  Returns URL query parameters in NSDictionary
 *
 *  @return
 */
- (nonnull NSDictionary*)axssdk_queryDictionary;

/**
 *  Returns URL fragment parameters in NSDictionary
 *
 *  @return
 */
- (nonnull NSDictionary *)axssdk_fragmentDictionary;
@end
