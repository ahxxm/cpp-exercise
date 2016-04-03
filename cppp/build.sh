#!/bin/bash

set -e

# cd cppp
cd "$(dirname "$0")"


mkdir build
cd build
cmake ..
make -j8
make test ARGS="-VV"
