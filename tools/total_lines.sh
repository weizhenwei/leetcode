#!/bin/bash

totalline=`find ./src -name \*.cpp | xargs cat | wc -l`;

echo "total code written in project = $totalline";
