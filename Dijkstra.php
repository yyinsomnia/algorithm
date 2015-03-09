<?php

class Dijkstra
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

$di = new Dijkstra($weight_adjacency_list, 's');
$di->topologicalSort();
print_r(get_object_vars($di));


