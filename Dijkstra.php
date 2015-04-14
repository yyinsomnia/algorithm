<?php

class LeoDijkstra
{
	public $G;
	public $s;
	public $edgeCount;
	public $shortest;
	public $pred;
	public $edges;
	
	public function __construct($G, $s)
	{
		$this->G = $G;
		$this->s = $s;
		$this->edges = array();
		$this->vertexCount = 0;

		foreach ($G as $key => $val) {
			$this->shortest[$key] = 0x0FFFFFFF; //max int...just cheat myself..u know
			$this->pred[$key] = null;
			$this->edgeCount += count($val);
		}
		$this->shortest[$s] = 0;
		$this->pred[$s] = null;
	}

	public function weight($u, $v)
	{
		foreach ($this->G[$u] as $to => $weight) {
			if ($v == $to)
				return $weight;
		}
	}

	public function relax($u, $v)
	{
		if ($this->shortest[$u] + $this->weight($u, $v) < $this->shortest[$v]) {
			$this->shortest[$v] = $this->shortest[$u] + $this->weight($u, $v);
			$this->pred[$v] = $u;
		}
	}

	public function topologicalSort()
	{
		$next = array();
		$next[] = $this->s;
		while (count($this->edges) < $this->edgeCount) {
			$s = array_pop($next);
			foreach ($this->G[$s] as $vertex => $weight) {
				if (in_array($s. '-' . $vertex, $this->edges))
					continue;
				$this->relax($s, $vertex);
				$this->edges[] = $s. '-' . $vertex;
				$next[] = $vertex;
			}
		}
	}

}

class LeoBetterDijkstra
{
	public $G;
	public $s;
	public $vertexCount;
	public $shortest;
	public $pred;
	public $vertexVisited;
	
	public function __construct($G, $s)
	{
		$this->G = $G;
		$this->s = $s;
		$this->vertexVisited = array();
		$this->vertexCount = 0;

		foreach ($G as $key => $val) {
			$this->shortest[$key] = 0x0FFFFFFF; //max int...just cheat myself..u know
			$this->pred[$key] = null;
			$this->vertexCount += 1;
		}
		$this->shortest[$s] = 0;
		$this->pred[$s] = null;
	}

	public function weight($u, $v)
	{
		foreach ($this->G[$u] as $to => $weight) {
			if ($v == $to)
				return $weight;
		}
	}

	public function relax($u, $v)
	{
		if ($this->shortest[$u] + $this->weight($u, $v) < $this->shortest[$v]) {
			$this->shortest[$v] = $this->shortest[$u] + $this->weight($u, $v);
			$this->pred[$v] = $u;
		}
	}

	public function sort()
	{
		$next = array();
		$next[] = $this->s;
		while (count($next)) {
			print_r($this->vertexVisited);
			$this->vertexVisited[] = $s = array_shift($next);
			foreach ($this->G[$s] as $vertex => $weight) {
				$this->relax($s, $vertex);
				if (!in_array($vertex, $this->vertexVisited) && !in_array($vertex, $next))
					$next[] = $vertex;
			}
		}
	}

}

/**
 * this implementation is more like the runner model
 */
class DijkstraArrayImplementation
{
	public $G;
	public $s;

	public $shortest;
	public $pred;

	public $Q;
	public $decreaseKey;

	public function __construct($G, $s)
	{
		$this->G = $G;
		$this->s = $s;
		$this->Q = array();

		foreach ($G as $key => $val) {
			$this->shortest[$key] = 0x0FFFFFFF; //max int...just cheat myself..u know
			$this->pred[$key] = null;
			$this->insertQ($key);
		}
		$this->shortest[$s] = 0;
		$this->pred[$s] = null;
	}

	public function insertQ($v)
	{
		$this->Q[] = $v;
	}

	public function extractMinQ()
	{
		$min_index = null;
		$min_vertex = null;
		$min_value = 0x0FFFFFFF;
		foreach ($this->Q as $index => $v) {
			if ($this->shortest[$v] < $min_value) {
				$min_index = $index;
				$min_vertex = $v;
				$min_value = $this->shortest[$v];
			}
		}
		unset($this->Q[$min_index]);
		return $min_vertex;
	}

	public function decreaseKeyQ($v)
	{

	}

	public function relax($u, $v)
	{
		if ($this->shortest[$u] + $this->weight($u, $v) < $this->shortest[$v]) {
			$this->shortest[$v] = $this->shortest[$u] + $this->weight($u, $v);
			$this->pred[$v] = $u;
		}
	}

	public function weight($u, $v)
	{
		foreach ($this->G[$u] as $to => $weight) {
			if ($v == $to)
				return $weight;
		}
	}

	public function simpleSort()
	{
		while (count($this->Q) > 0) {
			$u = $this->extractMinQ();
			foreach ($this->G[$u] as $v => $weight) {
				$this->relax($u, $v);
				if ($this->pred[$v] == $u)
					$this->decreaseKeyQ($v);
			}
		}
	}
	
}

class DijkstraBinaryHeapImplementation
{
	public $G;
	public $s;

	public $shortest;
	public $pred;

	public $Q;
	public $decreaseKey;
	public $arrayToAssoc;

	public function __construct($G, $s)
	{
		$this->G = $G;
		$this->s = $s;
		$this->Q = array();

		$i = 1;
		foreach ($G as $key => $val) {
			$this->arrayToAssoc[$i] = $key;
			$this->shortest[$key] = 0x0FFFFFFF; //max int...just cheat myself..u know
			$this->pred[$key] = null;
			$this->insertQ($key);
			$i++;
		}
		$this->shortest[$s] = 0;
		$this->pred[$s] = null;
	}

	public function insertQ($v)
	{
		$i = count($this->Q) + 1;
		$this->Q[$i] = $v;
		$i_parent = intval($i / 2);
		while ($i > 1 && $this->shortest[$this->arrayToAssoc[$i]] < $this->shortest[$this->arrayToAssoc[$i_parent]]) {
			$tmp = $this->Q[$i];
			$this->Q[$i] = $this->Q[$i_parent];
			$this->Q[$i_parent] = $tmp;
			$i = $i_parent;
			$i_parent = intval($i / 2);
		}
	}

	public function extractMinQ()
	{
		$i = 1;
		$eax = $this->Q[$i];
		$count = count($this->Q);
		$this->Q[$i] = $this->Q[$count];
		unset($this->Q[$count]);

		$i_left_child = 2 * $i;
		$i_right_child = 2 * $i + 1;
		while ($i_right_child <= $count - 1) {
			if ($this->shortest[$this->arrayToAssoc[$i]] > $this->shortest[$this->arrayToAssoc[$i_left_child]]) {
				$i_change = $i_left_child;
			} elseif ($this->shortest[$this->arrayToAssoc[$i]] > $this->shortest[$this->arrayToAssoc[$i_right_child]]) {
				$i_change = $i_right_child;
			} else {
				break;
			}
			$tmp = $this->Q[$i];
			$this->Q[$i] = $this->Q[$i_change];
			$this->Q[$i_change] = $tmp;
			$i = $i_change;
			$i_left_child = 2 * $i;
			$i_right_child = 2 * $i + 1;
		} 
			
		return $eax;
	}

	public function decreaseKeyQ($v)
	{
		$i = array_keys($this->arrayToAssoc, $v)[0]; //the data struct is bad...
		$i_parent = intval($i / 2);
		while ($i > 1 && $this->shortest[$this->arrayToAssoc[$i]] < $this->shortest[$this->arrayToAssoc[$i_parent]]) {
			$tmp = $this->Q[$i];
			$this->Q[$i] = $this->Q[$i_parent];
			$this->Q[$i_parent] = $tmp;
			$i = $i_parent;
			$i_parent = intval($i / 2);
		}

	}

	public function relax($u, $v)
	{
		if ($this->shortest[$u] + $this->weight($u, $v) < $this->shortest[$v]) {
			$this->shortest[$v] = $this->shortest[$u] + $this->weight($u, $v);
			$this->pred[$v] = $u;
		}
	}

	public function weight($u, $v)
	{
		foreach ($this->G[$u] as $to => $weight) {
			if ($v == $to)
				return $weight;
		}
	}

	public function binaryHeapSort()
	{
		while (count($this->Q) > 0) {
			$u = $this->extractMinQ();
			foreach ($this->G[$u] as $v => $weight) {
				$this->relax($u, $v);
				if ($this->pred[$v] == $u)
					$this->decreaseKeyQ($v); //keep the heap property holds,
			}
		}
	}
	
}

$weight_adjacency_list = [
	's' => [
		't' => 6,
		'y' => 4,
	],
	'y' => [
		't' => 1,
		'x' => 9,
		'z' => 3,
	],
	't' => [
		'y' => 2,
		'x' => 3,
	],
	'z' => [
		's' => 7,
		'x' => 5,
	],
	'x' => [
		'z' => 4,
	],
];

$di = new LeoBetterDijkstra($weight_adjacency_list, 's');
$di->sort();
print_r(get_object_vars($di));


