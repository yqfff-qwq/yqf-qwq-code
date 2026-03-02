#!/bin/bash
name=$1
cp "${name}.in" a.in
time ./a
diff -Z a.out "${name}.out"