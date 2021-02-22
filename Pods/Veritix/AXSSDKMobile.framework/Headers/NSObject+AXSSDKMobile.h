//
//  NSObject+AXSSDKMobile.h
//  AXSSDKMobile
//
//  Created by Wilson Lei on 10/8/15.
//  Copyright © 2015 AXS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AXSSDKMobile)

@property (nonatomic, retain) id axssdk_associatedObject;
- (void)axssdk_setAssociatedObject:(id)object forKey:(NSString *)key;
- (id)axssdk_associatedObjectForKey:(NSString *)key;

@end
