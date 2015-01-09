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

function merge_sort(array $a, $p, $r)
{
	$q = floor(($p + $r) / 2);
	merge_sort($p, $q);
	merge_sort($q, $r);
	merge($a, $p, $q, $r);
}

function merge(array $a, $p, $q, $r)
{
	$i = $p;
	$j = $q + 1;
	$res = array();
	while ($i <= $q && $j <= $r) {
		if ($a[$i] <= $a[$j]) {
			$res[] = $a[$i++];
		} else {
			$res[] = $a[$j++];
		}
	}
	return $res;
}

$a = array(5,4,2,3,1,7,8);
print_r(insertion_sort($a, count($a)));