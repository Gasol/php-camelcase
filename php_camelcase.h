/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Gasol Wu <gasol.wu@gmail.com>                                |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_CAMELCASE_H
#define PHP_CAMELCASE_H

extern zend_module_entry camelcase_module_entry;
#define phpext_camelcase_ptr &camelcase_module_entry

#define PHP_CAMELCASE_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_CAMELCASE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_CAMELCASE_API __attribute__ ((visibility("default")))
#else
#	define PHP_CAMELCASE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(camelcase);
PHP_MSHUTDOWN_FUNCTION(camelcase);
PHP_MINFO_FUNCTION(camelcase);

PHP_FUNCTION(camelize);

#ifdef ZTS
#define CAMELCASE_G(v) TSRMG(camelcase_globals_id, zend_camelcase_globals *, v)
#else
#define CAMELCASE_G(v) (camelcase_globals.v)
#endif

#endif	/* PHP_CAMELCASE_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
