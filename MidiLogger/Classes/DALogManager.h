//
//  DALogManager.h
//  MidiLogger
//
//  Created by zengqingfu on 2019/1/14.
//  Copyright © 2019 dev. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DALogManager : NSObject
+ (instancetype)manager;
@property (nonatomic, readonly, getter=isLoging) BOOL loging;
@property (nonatomic, readonly) NSString *logFilePath;

- (void)start;

- (void)writeLog:(NSString *)tag
          andLog:(NSString *)log;

- (void)stop;
@end

NS_ASSUME_NONNULL_END
