// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2018, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *DALoggerName NS_TYPED_EXTENSIBLE_ENUM;
FOUNDATION_EXPORT DALoggerName const DALoggerNameASL NS_SWIFT_NAME(DALoggerName.asl); // DAASLLogger
FOUNDATION_EXPORT DALoggerName const DALoggerNameTTY NS_SWIFT_NAME(DALoggerName.tty); // DATTYLogger
FOUNDATION_EXPORT DALoggerName const DALoggerNameOS NS_SWIFT_NAME(DALoggerName.os); // DAOSLogger
FOUNDATION_EXPORT DALoggerName const DALoggerNameFile NS_SWIFT_NAME(DALoggerName.file); // DAFileLogger

NS_ASSUME_NONNULL_END
