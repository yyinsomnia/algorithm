<?php

class LeoDijkstra
{
	public $G;
	public $s;
	public $vertexCount;
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
			$this->vertexCount += count($val);
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
		while (count($this->edges) < $this->vertexCount) {
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
	public $arrayToassoc;

	public function __construct($G, $s)
	{
		$this->G = $G;
		$this->s = $s;
		$this->Q = array();

		$i = 1;
		foreach ($G as $key => $val) {
			$this->arrayToassoc[$i] = $key;
			$this->shortest[$key] = 0x0FFFFFFF; //max int...just cheat myself..u know
			$this->pred[$key] = null;
			$this->insertQ($key);
		}
		$this->shortest[$s] = 0;
		$this->pred[$s] = null;
	}

	public function insertQ($v)
	{
		$i = count($this->Q) + 1;
		$this->Q[$i] = $v;
		$i_parent = floor($i / 2);
		while ($i > 1 && $this->shortest[$this->arrayToassoc[$i]] < $this->shortest[$this->arrayToassoc[$i_parent]]) {
			$tmp = $this->shortest[$this->arrayToassoc[$i]];
			$this->shortest[$this->arrayToassoc[$i]] = $this->shortest[$this->arrayToassoc[$i_parent]];
			$this->shortest[$this->arrayToassoc[$i_parent]] = $tmp;
		}
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

	public function binaryHeapSort()
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

$di = new DijkstraArrayImplementation($weight_adjacency_list, 's');
$di->simpleSort();
print_r(get_object_vars($di));


