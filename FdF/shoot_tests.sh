#!/bin/bash

MAP_DIR="test_maps"

for file in "$MAP_DIR"/*.fdf; do
    echo "Running: ./fdf $file"
    ./fdf "$file"
done
