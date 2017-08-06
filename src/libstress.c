/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   libstress.c
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

#include "libstress.h"

/**
 *  Populates a new test_t structure with the right values
 *  @param groupname : a group_name where tests might be grouped together
 *  @param name : the test name
 *  @param dirname : the subdirectory name where the tests migth be conducted
 *  @param exec : the exec function for an atomic test (might be NULL but the test will not run)
 *  @param init : the init function for an atomic test (might be NULL)
 *  @param final: the final function for an atomic test (might be NULL)
 *  @param vary : the vary function used for internal datas (might be NULL)
 *  @param data : the internal datas (if any - might be NULL) for the test itself
 *  @param max_nb : maximum number of atomic test to be run
 *  @param max_thread : maximum threads to run at a time
 */
test_t *new_test_t_struct(gchar *groupname, gchar *name, gchar *dirname, gchar *exec_dirname, TestExecFunc exec, TestInitFunc init, TestFinalFunc final, TestVaryFunc vary, gpointer data, guint max_nb, guint max_threads)
{
	test_t *the_test = NULL;

	if (exec != NULL)
		{
			the_test = (test_t *) g_malloc0(sizeof(test_t));
	
			if (groupname == NULL)
				{
					the_test->groupname = g_strdup("Default Group");
				}
			else
				{
					the_test->groupname = g_strdup(groupname);
				}

			if (name == NULL)
				{
					the_test->name = g_strdup("Default Name");
				}
			else
				{
					the_test->name = g_strdup(name);
				}

			if (dirname == NULL)
				{
					the_test->dirname = g_strdup("dirname");
				}
			else
				{
					the_test->dirname = g_strdup(dirname);
				}

			if (exec_dirname == NULL)
				{
					the_test->exec_dirname = g_strdup("exec_dirname");
				}
			else
				{
					the_test->exec_dirname = g_strdup(exec_dirname);
				}

			the_test->exec = exec;
			the_test->init = init;
			the_test->final = final;
			the_test->vary = vary;
			
			the_test->data = data;
			
			the_test->max_nb = max_nb;
			the_test->max_threads = max_threads;
			
			the_test->percent = 0.0;  /**< at init time we do think that nothing happened within the test itself */

			return the_test;
		}
	else
		{
			return NULL;
		}
}


/**
 *  Adds a test to a test list
 *  @param test_list : a list of tests
 *  @param one_test : one test to add to the list
 */
GList *add_test_to_test_list(GList *test_list, test_t *one_test)
{
	if (one_test != NULL)
	{
		return g_list_append(test_list, (gpointer) one_test);
	}
	else
		return test_list;
}


