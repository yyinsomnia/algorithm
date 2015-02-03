<?php

/**
 * use adjacency list to represent directed graph
 */
function topological_sort($G)
{
	$count = count($G);
	$in_degree = array_fill(1, $count, 0);
	foreach ($G as $u => $vertices) {
		foreach ($vertices as $v) {
			$in_degree[$v] += 1;
		}
	}
	$next = array_keys($in_degree, 0);
	$res = [];
	while (count($next)) {
		$res[] = $v = array_pop($next);
		if (count($G[$v])) {
			foreach ($G[$v] as $to) {
				if (--$in_degree[$to] == 0) 
					$next[] = $to;
			}
		}
	}
	return $res;
}

$adjacency_list = [1 => [3], 2 => [4], 3 => [4, 5], 4 => [6], 5 => [6], 6 => [7, 11], 7 => [8], 8 => [13], 9 => [10], 10 => [11], 11 => [12], 12 => [13], 13 => [14], 14 => []];


print_r(topological_sort($adjacency_list));