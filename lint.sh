#!/bin/bash

wget https://github.com/google/styleguide/raw/gh-pages/cpplint/cpplint.py
python cpplint.py --extensions=hpp,cpp --output=emacs --recursive --counting=detailed ./
exit 0
