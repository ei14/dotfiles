#!/bin/sh
color=$(< /home/tk/.cmd/color_temperature)
if [ $color -lt 10000 ]; then
	color=$(($color + 250))
	echo $color > /home/tk/.cmd/color_temperature
	sct $color
fi
