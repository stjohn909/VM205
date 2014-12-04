/*
 * Copyright (C) 2014 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file settings.h
 * @brief Configuration settings
 * @author Gunther Van Butsele
 */
#ifndef VM205_SETTINGS_H
#define VM205_SETTINGS_H

#define VM205_VDIV_5V      0x01 /**< 5V/div */
#define VM205_VDIV_2V      0x02 /**< 2V/div */
#define VM205_VDIV_1V      0x03 /**< 1V/div */
#define VM205_VDIV_500mV   0x04 /**< 500mV/div */
#define VM205_VDIV_200mV   0x05 /**< 200mV/div */
#define VM205_VDIV_100mV   0x06 /**< 100mV/div */

#define VM205_COUPLING_AC   0x01 /**< AC input coupling */
#define VM205_COUPLING_DC   0x02 /**< DC input coupling */

#define VM205_YPOS_HIGH     0x00
#define VM205_YPOS_CENTER   0x7f
#define VM205_YPOS_LOW      0xff

#define VM205_TIMEBASE_200ms    0x01 /**< 200ms/div */
#define VM205_TIMEBASE_100ms    0x02 /**< 100ms/div */
#define VM205_TIMEBASE_50ms     0x03 /**< 50ms/div */
#define VM205_TIMEBASE_20ms     0x04 /**< 20ms/div */
#define VM205_TIMEBASE_10ms     0x05 /**< 10ms/div */
#define VM205_TIMEBASE_5ms      0x06 /**< 5ms/div */
#define VM205_TIMEBASE_2ms      0x07 /**< 2ms/div */
#define VM205_TIMEBASE_1ms      0x08 /**< 1ms/div */
#define VM205_TIMEBASE_500us    0x09 /**< 500탎/div */
#define VM205_TIMEBASE_200us    0x0a /**< 200탎/div */
#define VM205_TIMEBASE_100us    0x0b /**< 100탎/div */
#define VM205_TIMEBASE_50us     0x0c /**< 50탎/div */

#define VM205_TRIG_ON       0x01 /**< Trigger enabled */
#define VM205_TRIG_OFF      0x02 /**< Trigger disabled */
#define VM205_TRIG_RISING   0x03 /**< Trigger on rising slope */
#define VM205_TRIG_FALLING  0x04 /**< Trigger on falling slope */

#define VM205_TRIG_LOW   0x01
#define VM205_TRIG_MID   0x7f
#define VM205_TRIG_HIGH  0xff

#define VM205_YPOS_MAX   0x00
#define VM205_YPOS_MIN   0xff
#define VM205_YPOS_MID   0x7f

#define VM205_SET_VDIV        0x91 /**< Set the volts per division */
#define VM205_SET_COUPLING    0x92 /**< Set the input coupling */
#define VM205_SET_TIMEBASE    0x93 /**< Set the timebase */
#define VM205_SET_TRIG        0x94 /**< Enable or disabled triggering */
#define VM205_SET_YPOS        0x95 /**< Set the Y-position */
#define VM205_SET_TRIG_LEVEL  0x96 /**< Set the trigger level */
#define VM205_GET_SAMPLES     0x81 /**< Start acquiring samples */
#define VM205_GET_STATUS      0x82 /**< Checks if sampling is complete */
#define VM205_READY           0x02 /**< Samples have been acquired */
#define VM205_BUSY            0x00 /**< Samples are being acquired */
#define VM205_GET_SAMPLE      0x01 /**< Get the next sample */
#define VM205_GET_ANALOG1     0x02 /**< Get the next logic analyzer value */
#define VM205_GET_ANALOG2     0x03 /**< Get the next logic analyzer value */

#endif