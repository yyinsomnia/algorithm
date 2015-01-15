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

$a = [1,2,1,2,2,2,1,1,0];
$r = count_keys_equal($a, count($a), 3);
echo implode(',', $r);