#!/bin/bash

set -e

mkdir build
cd build
cmake ..
make -j8
make test ARGS="-VV"
