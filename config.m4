dnl $Id$
dnl config.m4 for extension camelcase

PHP_ARG_ENABLE(camelcase, whether to enable camelcase support,
[  --enable-camelcase           Enable camelcase support])

if test "$PHP_CAMELCASE" != "no"; then
  PHP_NEW_EXTENSION(camelcase, camelcase.c, $ext_shared)
fi
