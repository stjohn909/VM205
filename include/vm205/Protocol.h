/*
 * Copyright (C) 2015 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file Protocol.h
 * @brief 
 * @author Gunther Van Butsele
 */
#ifndef VM205_PROTOCOL_H
#define VM205_PROTOCOL_H

namespace vm205 {

#define OSC_DATA_READY 0x02

#define OSC_SET_VDIV             0x91
#define OSC_SET_INPUT_COUPLING   0x92
#define OSC_SET_TIMEBASE         0x93
#define OSC_SET_TRIGGER          0x94
#define OSC_SET_Y_POS            0x95
#define OSC_SET_TRIGGER_LEVEL    0x96

#define OSC_GET_DATA             0x81
#define OSC_GET_DATA_READY       0x82
#define OSC_GET_SAMPLE           0x01
#define OSC_LA_GET_SAMPLE_1      0x02
#define OSC_LA_GET_SAMPLE_2      0x03

#define OSC_DATA_READY           0x02

}

#endif
