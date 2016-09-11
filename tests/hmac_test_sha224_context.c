/*
 * Library SHA224 context type testing program
 *
 * Copyright (C) 2011-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "hmac_test_libcerror.h"
#include "hmac_test_libcstring.h"
#include "hmac_test_libhmac.h"
#include "hmac_test_macros.h"
#include "hmac_test_memory.h"
#include "hmac_test_unused.h"

/* Tests the libhmac_sha224_initialize function
 * Returns 1 if successful or 0 if not
 */
int hmac_test_sha224_initialize(
     void )
{
	libhmac_sha224_context_t *sha224_context = NULL;
	libcerror_error_t *error                 = NULL;
	int result                               = 0;

	/* Test libhmac_sha224_initialize without entries
	 */
	result = libhmac_sha224_initialize(
	          &sha224_context,
	          &error );

	HMAC_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        HMAC_TEST_ASSERT_IS_NOT_NULL(
         "sha224_context",
         sha224_context );

        HMAC_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = libhmac_sha224_free(
	          &sha224_context,
	          &error );

	HMAC_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 1 );

        HMAC_TEST_ASSERT_IS_NULL(
         "sha224_context",
         sha224_context );

        HMAC_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = libhmac_sha224_initialize(
	          NULL,
	          &error );

	HMAC_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        HMAC_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	sha224_context = (libhmac_sha224_context_t *) 0x12345678UL;

	result = libhmac_sha224_initialize(
	          &sha224_context,
	          &error );

	HMAC_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        HMAC_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	sha224_context = NULL;

#if defined( HAVE_HMAC_TEST_MEMORY )

	/* Test libhmac_sha224_initialize with malloc failing
	 */
	hmac_test_malloc_attempts_before_fail = 0;

	result = libhmac_sha224_initialize(
	          &sha224_context,
	          &error );

	if( hmac_test_malloc_attempts_before_fail != -1 )
	{
		hmac_test_malloc_attempts_before_fail = -1;
	}
	else
	{
		HMAC_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		HMAC_TEST_ASSERT_IS_NULL(
		 "sha224_context",
		 sha224_context );

		HMAC_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Test libhmac_sha224_initialize with memset failing
	 */
	hmac_test_memset_attempts_before_fail = 0;

	result = libhmac_sha224_initialize(
	          &sha224_context,
	          &error );

	if( hmac_test_memset_attempts_before_fail != -1 )
	{
		hmac_test_memset_attempts_before_fail = -1;
	}
	else
	{
		HMAC_TEST_ASSERT_EQUAL(
		 "result",
		 result,
		 -1 );

		HMAC_TEST_ASSERT_IS_NULL(
		 "sha224_context",
		 sha224_context );

		HMAC_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
#endif /* defined( HAVE_HMAC_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( sha224_context != NULL )
	{
		libhmac_sha224_free(
		 &sha224_context,
		 NULL );
	}
	return( 0 );
}

/* Tests the libhmac_sha224_free function
 * Returns 1 if successful or 0 if not
 */
int hmac_test_sha224_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libhmac_sha224_free(
	          NULL,
	          &error );

	HMAC_TEST_ASSERT_EQUAL(
	 "result",
	 result,
	 -1 );

        HMAC_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( LIBCSTRING_HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc HMAC_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] HMAC_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc HMAC_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] HMAC_TEST_ATTRIBUTE_UNUSED )
#endif
{
	HMAC_TEST_UNREFERENCED_PARAMETER( argc )
	HMAC_TEST_UNREFERENCED_PARAMETER( argv )

	HMAC_TEST_RUN(
	 "libhmac_sha224_initialize",
	 hmac_test_sha224_initialize() )

	HMAC_TEST_RUN(
	 "libhmac_sha224_free",
	 hmac_test_sha224_free() )

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

