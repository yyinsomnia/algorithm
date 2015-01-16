<?php

/**
 * a: an array in which each element is either 1 or 2.
 * n: the number of elements in A to sort.
 */
function really_simple_sort(array &$a, $n)
{
	$k = 0;
	for ($i = 0; $i < $n; $i++) {
		if ($a[$i] === 1)
			$k++;
	}

	for ($i = 0; $i < $k; $i++) {
		$a[$i] = 1;
	}

	for ($i = $k; $i < $n; $i++) {
		$a[$i] = 2;
	}
}

/**
 * Inputs:
 * A: an array of integers in the range 0 to m-1.
 * n: the number of elements in A.
 * m: defines the range of the values in A
 * Output:
 * An array equal[0..m - 1] such that equal[j] contains the
 * number of elements of A that equal j , for j = 0,1,2,...,m - 1.
 */
function count_keys_equal(array $a, $n, $m)
{
	$equal = array_fill(0, $m, 0);
	for ($i = 0; $i < $n; $i++) {
		$key = $a[$i];
		$equal[$key]++;
	}
	return $equal;
}

function count_keys_less(array $equal, $m)
{
	$less = array_fill(0, $m, 0);
	for ($i = 0; $i < $m; $i++) {
		for ($j = $i + 1; $j < $m; $j++) {
			$less[$j] += $equal[$i];
		}
	}
	return $less;
}

function better_count_keys_less(array $equal, $m)
{
	$less = array_fill(0, $m, 0);
	for ($j = 1; $j < $m; $j++) {
		$less[$j] = $less[$j - 1] + $equal[$j - 1];
	}
	return $less;
}

function rearrange(array $a, $less, $n, $m)
{
	$b = [];
	$cursor = 0;
	for ($i = 0; $i < $m - 1; $i++) {
		$count = $less[$i + 1] - $less[$i];
		while ($count-- > 0) {
			$b[$cursor++] = $i;
		}
	}
	while ($cursor++ < $n) {
		$b[$cursor] = $i;
	}
	return $b;
}

function another_rearrange(array $a, $less, $n, $m)
{
	$b = array_fill(0, $n, 0);
	for ($i = 0; $i < $n; $i++) {
		$key = $a[$i];
		$b[$less[$key]++] = $a[$i];
	}
	return $b;
}

function counting_sort(array $a, $n, $m)
{
	$equal = count_keys_equal($a, $n, $m);
	$less = better_count_keys_less($equal, $m);
	return another_rearrange($a, $less, $n, $m);

}

$a = [1,2,1,2,2,2,1,1,0,0,2];
echo implode(',', counting_sort($a, count($a), 3));
die();
$r = count_keys_equal($a, count($a), 3);
$r2 = count_keys_less($r, 3);
$r3 = better_count_keys_less($r, 3);
$b = another_rearrange($a, $r3, count($a), 3);
echo implode(',', $r);
echo '<br />';
echo implode(',', $r2);
echo '<br />';
echo implode(',', $r3);
echo '<br />';
echo implode(',', $b);