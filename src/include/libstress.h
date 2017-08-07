/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   libstress.h
   libstress library

   (C) Copyright 2009 Olivier Delhomme
   e-mail : olivierdelhomme@gmail.com

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
#ifndef _LIBSTRESS_H_
#define _LIBSTRESS_H_

#include <errno.h>
#include <fcntl.h>
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define LIBSTRESS_NAME "libstress"
#define LIBSTRESS_VERSION "0.0.1"
#define LIBSTRESS_SUMMARY "libstress library"
#define LIBSTRESS_DESCRIPTION "Provide some stress tests"
#define LIBSTRESS_AUTHOR "Olivier Delhomme <olivierdelhomme@gmail.com>"
#define LIBSTRESS_MAINTAINER "Olivier Delhomme <olivierdelhomme@gmail.com>"
#define LIBSTRESS_HOMEPAGE "none"
#define LIBSTRESS_DATE "29.05.2009"

#include "config.h"

/**
 *  Main structure
 */
typedef struct
{
	GList *test_list;   /**< lists of tests  */
} main_struct_t;

/**
 * Prototype definition for the tests functions
 * The vary function will be called until it returns FALSE
 * TRUE is passed when an initialisation is requiered (begin and end of the tests)
 */
typedef gboolean (* TestExecFunc) (gpointer, guint, guint); /**< Test execution function type          */
typedef void (* TestInitFunc) (gpointer);                   /**< Test initialisation function type     */
typedef void (* TestFinalFunc) (gpointer);                  /**< Test finalisation function type       */
typedef gboolean (* TestVaryFunc) (gpointer, gboolean);     /**< Test varying function definition type */

/**
 *  Test structure
 */
typedef struct
{
	gchar *groupname;       /**< test group name                                                     */
	gchar *name;            /**< test name                                                           */
	gchar *dirname;         /**< base directory name (should not change after init)                  */
	gchar *exec_dirname;    /**< directory name where the test should executes itself                */
	TestExecFunc exec;      /**< execution function for the specified test                           */
	TestInitFunc init;      /**< init function for the specified test                                */
	TestFinalFunc final;    /**< final function for the specified test                               */
	TestVaryFunc vary;      /**< vary funciton used to vary internal parameters                      */
	gpointer data;          /**< internal data of the test                                           */
	guint max_nb;           /**< max number of atomic test per threads                               */
	guint max_threads;      /**< max number of threads                                               */
	gfloat percent;         /**< values from 0.0 to 1.0 represents, in percent.                      */
} test_t;


#endif /* _LIBSTRESS_H_ */
