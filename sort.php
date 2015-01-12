<?php

function selection_sort(array $a, $n) 
{
	$i = 0;
	while ($i < $n-1) {
		$j = $i;
		$smallest_index = $j;
		while ($j < $n-1) {
			if ($a[$j] < $a[$smallest_index])
				$smallest_index = $j;
			$j++;
		}
		if ($smallest_index !== $i) {
			$tmp = $a[$i];
			$a[$i] = $a[$smallest_index];
			$a[$smallest_index] = $tmp;
		}
		$i++;
	}
	return $a;
}

function better_selection_sort(array $a, $n) 
{
	$i = 0;
	while ($i < $n-1) {
		$smallest_index = $i;
		$j = $i+1;
		while ($j < $n-1) {
			if ($a[$j] < $a[$smallest_index])
				$smallest_index = $j;
			$j++;
		}
		if ($smallest_index !== $i) {
			$tmp = $a[$i];
			$a[$i] = $a[$smallest_index];
			$a[$smallest_index] = $tmp;
		}
		$i++;	
	}
	return $a;
}

function insertion_sort(array $a, $n) 
{
	for ($i = 0; $i < $n; $i++) {
		$the_one = $a[$i];
		$index = 0;
		for ($j = $i-1; $j >= 0; $j--) {
			if ($a[$j] > $the_one) {
				$a[$j+1] = $a[$j];
			} else {
				$index = $j + 1;
				break;
			}
		}
		$a[$index] = $the_one;
	}
	return $a;
}

function better_insertion_sort(array $a, $n) 
{
	for ($i = 1; $i < $n; $i++) {
		$the_one = $a[$i];
		$index = 0;
		for ($j = $i-1; $j >= 0; $j--) {
			if ($a[$j] > $the_one) {
				$a[$j+1] = $a[$j];
			} else {
				$index = $j + 1;
				break;
			}
		}
		$a[$index] = $the_one;
	}
	return $a;
}

function merge_sort(array &$a, $p, $r)
{
	if ($p >= $r) return ;
	$q = floor(($p + $r) / 2);
	merge_sort($a, $p, $q);
	merge_sort($a, $q + 1, $r);
	another_merge($a, $p, $q, $r);
}

function merge(array &$a, $p, $q, $r)
{
	$a_clone = $a;
	$i = $p;
	$j = $q + 1;
	$count = $p;
	while (true) {
		if ($i == $q + 1 && $j == $r + 1) {
			break;
		} elseif ($i <= $q && $j <= $r) {
			if ($a_clone[$i] <= $a_clone[$j]) {
				$a[$count++] = $a_clone[$i++];
			} else {
				$a[$count++] = $a_clone[$j++];
			}
		} else {
			if ($i > $q)
				$a[$count++] = $a_clone[$j++];
			else 
				$a[$count++] = $a_clone[$i++];
		}
	}
}

function another_merge(array &$a, $p, $q, $r)
{
	$m = array_slice($a, $p, $q - $p + 1);
	$n = array_slice($a, $q + 1, $r - $q);
	$m[] = 2147483648; //just bigger than int
	$n[] = 2147483648; //just bigger than int
	$i = $j = 0;
	for ($k = $p; $k <= $r; $k++) {
		if ($m[$i] <= $n[$j]) {
			$a[$k] = $m[$i++];
		} else {
			$a[$k] = $n[$j++];
		}
	}
}

function quick_sort(array &$a, $p, $r)
{
	if ($p >= $r) return ;
	$q = floor(($p + $r) / 2);
	$new_q = quick($a, $p, $q, $r);
	var_dump($a);
	quick_sort($a, $p, $new_q);
	quick_sort($a, $new_q + 1, $r);
}

function quick(array &$a, $p, $q, $r) 
{
	$tmp = $a[$p];
	$a[$p] = $a[$q];
	$a[$q] = $tmp;
	for ($i = $sentry = $p + 1; $i <= $r; $i++) {
		if ($a[$i] <= $a[$p]) {
			$tmp = $a[$sentry];
			$a[$sentry++] = $a[$i];
			$a[$i] = $tmp;
		}
	}
	$tmp = $a[$p];
	$a[$p] = $a[$sentry - 1];
	$a[$sentry - 1] = $tmp;
	return ($sentry-1);
}

$a = array(5,4,2,3,1,7,8);
quick_sort($a, 0, count($a) - 1);
echo implode(',', $a);