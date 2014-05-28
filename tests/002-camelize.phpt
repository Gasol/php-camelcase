--TEST--
Check for camelcase presence
--SKIPIF--
<?php if (!extension_loaded("camelcase")) print "skip"; ?>
--FILE--
<?php
var_dump(camelize(null));
var_dump(camelize(123));
var_dump(camelize(array("foo")));
var_dump(camelize(new stdClass()));
echo PHP_EOL;
var_dump(camelize(''));
var_dump(camelize("123"));
echo camelize('foo') . PHP_EOL;
echo camelize('foo_bar') . PHP_EOL;
echo camelize('foo_bar_zoo') . PHP_EOL;
echo camelize('foo__bar') . PHP_EOL;
?>
--EXPECT--
NULL
NULL
NULL
NULL

string(0) ""
string(3) "123"
Foo
FooBar
FooBarZoo
FooBar

