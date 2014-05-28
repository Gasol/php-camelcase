/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2014 The PHP Group                                |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_camelcase.h"

/* True global resources - no need for thread safety here */
static int le_camelcase;

/* {{{ camelcase_functions[]
 */
const zend_function_entry camelcase_functions[] = {
	PHP_FE(camelize,	NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ camelcase_module_entry
 */
zend_module_entry camelcase_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"camelcase",
	camelcase_functions,
	PHP_MINIT(camelcase),
	PHP_MSHUTDOWN(camelcase),
	NULL,
	NULL,
	PHP_MINFO(camelcase),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_CAMELCASE_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CAMELCASE
ZEND_GET_MODULE(camelcase)
#endif

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(camelcase)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(camelcase)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(camelcase)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "camelcase support", "enabled");
	php_info_print_table_end();
}
/* }}} */


PHP_FUNCTION(camelize)
{
	const char *delim = "_";
	zval *arg;
	int arg_len;
	char *token = NULL, *result = NULL;
	size_t result_len = 0, token_len = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &arg) == FAILURE) {
		return;
	}
	if (Z_TYPE_P(arg) != IS_STRING) {
		RETURN_NULL();
	}
	arg_len = Z_STRLEN_P(arg);
	if (!arg_len) {
		RETURN_EMPTY_STRING();
	}

	result = emalloc(arg_len + 1);

	char *stringp = Z_STRVAL_P(arg);
	while ((token = strsep(&stringp, delim)) != NULL) {
		token_len = strlen(token);
		if (token[0] > 0x60 && token[0] < 0x7b) {
			token[0] -= 0x20;
		}
		strcpy(result + result_len, token);
		result_len += token_len;
	}
	Z_ADDREF_P(return_value);
	RETURN_STRINGL(result, result_len, 0);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
