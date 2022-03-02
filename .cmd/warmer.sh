#!/bin/sh
color=$(< /home/tk/.cmd/color_temperature)
if [ $color -gt 1000 ]; then
	color=$(($color - 250))
	echo $color > /home/tk/.cmd/color_temperature
	sct $color
fi
