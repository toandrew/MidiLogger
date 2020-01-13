//
//  MidiLoggerBridge.h
//  MidiLoggerKit
//
//  Created by zengqingfu on 2019/1/15.
//  Copyright © 2019 dev. All rights reserved.
//

#ifndef MIDI_LOGGER_BRIDGE_H_
#define MIDI_LOGGER_BRIDGE_H_
bool isLoging(void);
void startLog(void);
void writeLog(const char *tag, const char *log);
void writeNLog(NSString *tag, NSString *log);
void stopLog(void);
NSString *logPath(void);

#endif
