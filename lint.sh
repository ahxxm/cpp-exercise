#!/bin/bash

pip install cpplint
cpplint --extensions=hpp,cpp --output=emacs --recursive --counting=detailed ./
exit 0
