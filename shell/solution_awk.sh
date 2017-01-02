#!/bin/bash
 awk '
{for(i=1;i<=NF;i++) {++D[$i]}}
END {for(i in D){print i,D[i]}}
' words.txt|sort -k2 -nr
