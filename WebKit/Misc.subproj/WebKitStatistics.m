//
//  WebKitStatistics.m
//  WebKit
//
//  Created by Darin Adler on Fri Jul 19 2002.
//  Copyright (c) 2002 Apple Computer, Inc. All rights reserved.
//

#import "WebKitStatistics.h"

#import "WebKitStatisticsPrivate.h"

int WebBridgeCount;
int WebControllerCount;
int WebDataSourceCount;
int WebFrameCount;
int WebViewCount;

@implementation WebKitStatistics

+ (int)controllerCount
{
    return WebControllerCount;
}

+ (int)frameCount
{
    return WebFrameCount;
}

+ (int)dataSourceCount
{
    return WebDataSourceCount;
}

+ (int)viewCount
{
    return WebViewCount;
}

+ (int)bridgeCount
{
    return WebBridgeCount;
}

@end
