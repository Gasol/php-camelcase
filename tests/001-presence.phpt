--TEST--
Check for camelcase presence
--SKIPIF--
<?php if (!extension_loaded("camelcase")) print "skip"; ?>
--FILE--
<?php
echo "camelcase extension is available";
?>
--EXPECT--
camelcase extension is available
