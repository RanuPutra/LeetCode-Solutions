<?php

class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @return String[]
     */
    function createGrid($m, $n) {
        $grid = [];
        for ($i = 0; $i < $m; $i++) {
            if ($i === 0) {
                $grid[] = str_repeat('.', $n);
            } else {
                $grid[] = str_repeat('#', $n - 1) . '.';
            }
        }
        return $grid;
    }
}
