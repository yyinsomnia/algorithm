<?php

function linear_search(array $a, $n, $x) {
	$i = 0;
	$flag = false;
	while ($i < $n) {
		if ($a[$i] === $x)
			$flag = $i;
		$i++;
	}
	return $flag;
}

function better_linear_search(array $a, $n, $x) {
	$i = 0;
	while ($i < $n) {
		if ($a[$i] === $x)
			return $i;
		$i++;
	}
	return false;
}

function sentinel_linear_search(array $a, $n, $x) {
	$last = $a[$n-1];
	$a[$n-1] = $x;
	$i = 0;
	while (true) {
		if ($a[$i] == $x) {
			$a[$n-1] = $last;
			if ($i < $n-1 || $a[$n-1] === $x) {
				return $i;
			} else {
				return false;
			}
		}
		$i++;
	}
}


var_dump(linear_search(array(2,3,4,5,6,2), 6, 2));
var_dump(better_linear_search(array(2,3,4,5,6,2), 6, 2));
var_dump(sentinel_linear_search(array(2,3,4,5,6,2), 6, 2));