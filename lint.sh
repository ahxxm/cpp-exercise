#!/bin/bash

pip install --user cpplint
cpplint --extensions=hpp,cpp --output=emacs --recursive --counting=detailed ./
exit 0
