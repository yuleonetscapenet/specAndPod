//
//  AXSSDKIdentityManager.h
//  AXSSDKMobile
//
//  Created by Wessen Alsaadie on 6/5/15.
//  Copyright (c) 2015 AXS. All rights reserved.
//

@import UIKit;
#import <Foundation/Foundation.h>

@class AXSSDKIdentity;
@class AXSSDKLocation;

/**
 *  The AXSSDKIdentityManager allows you to create and update identities on the AXS Identity platform. Any service that requires an "identity" will need you to first register that identity through this service.
 */
@interface AXSSDKIdentityManager : NSObject

@property (nonatomic, strong, nullable) AXSSDKIdentity* identity;

/**
 *  Shared instance of the class
 *
 *  @return class object
 */
+ (nonnull AXSSDKIdentityManager *)sharedInstance;


- (void)initialize:(void(^ _Nullable)(NSError * _Nullable error, id _Nullable response))completionHandler;

/**
 *  Link an existing identity with an AXS user ID.
 *
 *  @param userId The user ID of the My AXS user account.
 *  @param completionHandler The completion block that fires when the update succeeds/fails.
 */
- (void)linkIdentity:(nonnull NSNumber *)userId completionHandler:(void(^ _Nullable)(NSError * _Nullable error, id _Nullable response))completionHandler;


/**
 Unlink AXS user from identity. Set identity userId to nil
 */
- (void)unlinkIdentity;

/**
 *  Link an existing identity with any external identity information
 *
 *  @param identityData      dictionary of identity information
 *  @param completionHandler The completion block that fires when the update succeeds/fails.
 */
- (void)linkExternalIdentity:(nonnull NSDictionary*)identityData completionHandler:(void(^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 *  Update the location on file for this identity.
 *
 *  @param location   The new location record.
 *  @param completionHandler The completion block that fires when the update succeeds/fails.
 */
- (void)updateLocationForIdentity:(nullable AXSSDKLocation *)location completionHandler:(void(^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 *  Update identity region status
 *
 *  @param regionId          AXS region ID
 *  @param typeId            region type id. e.g. geofence, beacon
 *  @param action            region action. e.g. enter, exit, inside
 *  @param coordinates       array of coordinates including lat, long and timestamp
 *  @param completionHandler The completion block that fires when the update succeeds/fails.
 */
- (void)updateIdentityRegionStatus:(nonnull NSString *)regionId typeId:(int)typeId action:(int)action coordinates:(nonnull NSArray *)coordinates completionHandler:(void(^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 *  Register device token with current identity
 *
 *  @param token   device token
 */
- (void)registerForPushNotificationsWithDeviceToken:(nullable NSData *)token;

/**
 *  Register device token with current identity
 *
 *  @param token   device token
 *  @param completionHandler The completion block that fires when the registeration succeeds/fails.
 */
- (void)registerForPushNotificationsWithDeviceToken:(nullable NSData *)token completionHandler:(void(^ _Nullable)(NSError * _Nullable error))completionHandler;

/**
 *  Call this method in AppDelegate didReceiveRemoteNotification so AXS SDK can handle notification send by AXS.
 *
 *  @param application application from AppDelegate
 *  @param userInfo    userInfo from AppDelegate
 *
 *  @return BOOL indicates if remote notification is handled or not.
 */
- (BOOL)application:(nonnull UIApplication *)application didReceiveRemoteNotification:(nullable NSDictionary *)userInfo;

@end
