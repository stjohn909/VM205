/*
 * Copyright (C) 2014 Velleman nv
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
/**
 * @file defs.h
 * @brief Preprocessor definitions
 * @author Gunther Van Butsele
 */
#ifndef VM205_DEFS_H
#define VM205_DEFS_H

#if defined(__cplusplus)
#	define VM205_EXTERN extern "C"
#else
#	define VM205_EXTERN
#endif

#define VM205_DECLARE(type) VM205_EXTERN type

#endif