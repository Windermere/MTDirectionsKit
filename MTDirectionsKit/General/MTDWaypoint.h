//
//  MTDWaypoint.h
//  MTDirectionsKit
//
//  Created by Matthias Tretter
//  Copyright (c) 2012 Matthias Tretter (@myell0w). All rights reserved.
//


#import <CoreLocation/CoreLocation.h>
#import "MTDDirectionsAPI.h"


/**
 An instance of MTDWaypoint is a lightweight immutable object wrapper for a CLLocationCoordinate2D coordinate.
 It is used in MTDDirectionsKit to store coordinates in collections like NSArray.
 */
@interface MTDWaypoint : NSObject

/******************************************
 @name Location
 ******************************************/

/** the coordinate wrapped, may be invalid */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
/** the address wrapped, may be nil */
@property (nonatomic, readonly) NSString *address;

/** is this waypoint valid (valid coordinate or set address) */
@property (nonatomic, readonly, getter = isValid) BOOL valid;

/******************************************
 @name Lifecycle
 ******************************************/

/**
 This method is used to create an instance of MTDWaypoint with a given coordinate.
 
 @param coordinate the coordinate to save
 @return the wrapper object created to store the coordinate
 
 @see initWithCoordinate:
 */
+ (MTDWaypoint *)waypointWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 This method is used to create an instance of MTDWaypoint with a given address string.
 
 @param address the address of the waypoint
 @return the wrapper object created to store the address
 
 @see initWithAddress:
 */
+ (MTDWaypoint *)waypointWithAddress:(NSString *)address;

/**
 The initializer used to create an instance of MTDWaypoint that wraps a given coordinate.
 
 @param coordinate the coordinate to save
 @return the wrapper object created to store the coordinate
 */
- (id)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 The initializer used to create an instance of MTDWaypoint that wraps a given address.
 
 @param address the address to save
 @return the wrapper object created to store the address
 */
- (id)initWithAddress:(NSString *)address;


/******************************************
 @name API
 ******************************************/

/**
 Returns a string representation of this waypoint used for the call to the given API.
 
 @param api the API we use to retreive the directions
 @return string representation that can be used as part of the URL to call the API
 */
- (NSString *)descriptionForAPI:(MTDDirectionsAPI)api;

@end
