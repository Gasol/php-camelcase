--TEST--
Check for camelcase presence
--SKIPIF--
<?php if (!extension_loaded("camelcase")) print "skip"; ?>
--FILE--
<?php
echo camelize('foo') . PHP_EOL;
echo camelize('foo_bar') . PHP_EOL;
echo camelize('foo_bar_zoo') . PHP_EOL;
echo camelize('foo__bar') . PHP_EOL;
?>
--EXPECT--
Foo
FooBar
FooBarZoo
FooBar

