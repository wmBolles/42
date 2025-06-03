#!/bin/bash
echo $FT_NBR1 + $FT_NBR2 | tr "\'\\\\\"\?\!" "01234" | tr "mrdoc" "01234" | echo "ibase=5; obase=23; $(cat)" | bc | tr "0123456789ABC" "gtaio luSnemf" 
