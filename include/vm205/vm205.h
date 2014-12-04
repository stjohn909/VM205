/*
 * Copyright (C) 2014 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file vm205.h
 * @brief VM205 api
 * @author Gunther Van Butsele
 */
#ifndef VM205_H
#define VM205_H

#include "vm205/defs.h"
#include "vm205/settings.h"

#define VM205_MAX_SAMPLES  800

/**
 * Buffer for sample and logic analyzer data.
 */
typedef struct vm205_buffer {
	unsigned char samples[VM205_MAX_SAMPLES];
} vm205_buffer_t;

/**
 * Initializes communication with the VM205. Call this function once on
 * application startup.
 */
VM205_DECLARE(void) vm205_init();

/**
 * Sets a configuration settings for the VM205.
 * @param setting Configuration setting to change.
 * @param value New value for the configuration setting.
 */
VM205_DECLARE(void) vm205_set(char setting, char value);

/**
 * Send a command to the vm205 and read the response.
 * @param cmd Command to send.
 * @return Response value.
 */
VM205_DECLARE(char) vm205_cmd(char cmd);

/**
 * Gets the sample buffer and logic analyzer data.
 * @param buffer Buffer that will receive the data.
 */
VM205_DECLARE(void) vm205_acquire(vm205_buffer_t *buffer);

/**
 * Closes communication with the VM205. Call this function once on
 * application exit.
 */
VM205_DECLARE(void) vm205_quit();

#endif