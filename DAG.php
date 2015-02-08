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

/**
 * 
 */
function topological_sort_variant($G, &$shortest, &$pred)
{
	foreach ($G as $key => $val) {
		$in_degree[$key] = 0;
	}
	foreach ($G as $u => $vertices) {
		foreach ($vertices as $v => $weight) {
			$in_degree[$v] += 1;
		}
	}
	$next = array_keys($in_degree, 0);
	$res = [];
	while (count($next)) {
		$res[] = $v = array_pop($next);
		if (count($G[$v])) {
			foreach ($G[$v] as $to => $weight) {
				relax($G, $v, $to, $shortest, $pred); //it's here
				if (--$in_degree[$to] == 0) 
					$next[] = $to;
			}
		}
	}
	return $res;
}


function relax($G, $u, $v, &$shortest, &$pred)
{
	if ($shortest[$u] + weight($G, $u, $v) < $shortest[$v]) {
		$shortest[$v] = $shortest[$u] + weight($G, $u, $v);
		$pred[$v] = $u;
	}
}

function weight($G, $u, $v)
{
	foreach ($G[$u] as $to => $weight) {
		if ($v == $to)
			return $weight;
	}
}

function dag_shortest_paths($G)
{
	foreach ($G as $key => $val) {
		$shortest[$key] = 0x0FFFFFFF; //max int...just cheat myself..u know
		$pred[$key] = null;
	}
	$shortest['start'] = 0;// this is very important
	topological_sort_variant($G, $shortest, $pred);
	return ['shortest' => $shortest, 'pred' => $pred];
}



$adjacency_list = [1 => [3], 2 => [4], 3 => [4, 5], 4 => [6], 5 => [6], 6 => [7, 11], 7 => [8], 8 => [13], 9 => [10], 10 => [11], 11 => [12], 12 => [13], 13 => [14], 14 => []];

$weight_adjacency_list = [
	'start' => [
		'mix-cooking-sauce' => -3,
		'chop-carrots' => -4,
		'chop-celery' => -3,
		'rinse-peanuts' => -2,
		'chop-garlic' => -4,
		'chop-ginger' => -3,
		'mix-marinade' => -2,
		'cut-up-chicken' => -6
	],
	'mix-cooking-sauce' => [
		'add-cooking-sauce' => -1,
	],
	'chop-carrots' => [
		'cook-carrots-celery-peanuts' => -4,
	],
	'chop-celery' => [
		'cook-carrots-celery-peanuts' => -4,
	],
	'rinse-peanuts' => [
		'cook-carrots-celery-peanuts' => -4,
	],
	'chop-garlic' => [
		'add-garlic-ginger' => -1,
	],
	'chop-ginger' => [
		'add-garlic-ginger' => -1,
	],
	'mix-marinade' => [
		'marinate-chicken' => -15,
	],
	'cut-up-chicken' => [
		'marinate-chicken' => -15,
	],
	'marinate-chicken' => [
		'partially-cook-chicken' => -1,
	],
	'partially-cook-chicken' => [
		'add-garlic-ginger' => -1,
	],
	'add-garlic-ginger' => [
		'finish-cooking-chicken' => -2,
	],
	'finish-cooking-chicken' => [
		'remove-chicken' => -1,
	],
	'remove-chicken' => [
		'cook-carrots-celery-peanuts' => -4,
	],
	'cook-carrots-celery-peanuts' => [
		'add-back-chicken' => -1,
	],
	'add-back-chicken' => [
		'add-cooking-sauce' => -1,
	],
	'add-cooking-sauce' => [
		'cook-sauce-until-thick' => -3,
	],
	'cook-sauce-until-thick' => [
		'remove-completed-dish' => -1
	],
	'remove-completed-dish' => [
		'finish' => 0,
	],
	'finish' => [
	],

];

var_dump(dag_shortest_paths($weight_adjacency_list));