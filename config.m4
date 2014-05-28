dnl $Id$
dnl config.m4 for extension camelcase

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(camelcase, for camelcase support,
dnl Make sure that the comment is aligned:
dnl [  --with-camelcase             Include camelcase support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(camelcase, whether to enable camelcase support,
dnl Make sure that the comment is aligned:
dnl [  --enable-camelcase           Enable camelcase support])

if test "$PHP_CAMELCASE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-camelcase -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/camelcase.h"  # you most likely want to change this
  dnl if test -r $PHP_CAMELCASE/$SEARCH_FOR; then # path given as parameter
  dnl   CAMELCASE_DIR=$PHP_CAMELCASE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for camelcase files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CAMELCASE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CAMELCASE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the camelcase distribution])
  dnl fi

  dnl # --with-camelcase -> add include path
  dnl PHP_ADD_INCLUDE($CAMELCASE_DIR/include)

  dnl # --with-camelcase -> check for lib and symbol presence
  dnl LIBNAME=camelcase # you may want to change this
  dnl LIBSYMBOL=camelcase # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CAMELCASE_DIR/lib, CAMELCASE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_CAMELCASELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong camelcase lib version or lib not found])
  dnl ],[
  dnl   -L$CAMELCASE_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(CAMELCASE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(camelcase, camelcase.c, $ext_shared)
fi
