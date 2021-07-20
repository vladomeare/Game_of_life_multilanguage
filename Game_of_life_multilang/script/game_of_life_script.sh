#! /bin/bash

RUN=1
RESTART=0
CURRENT_DIR=$(pwd)

python3 $CURRENT_DIR"/../python/generate_zerofield.py"
echo "Field generate: 200"

while (($RUN == 1))
do
	$CURRENT_DIR"/../Cpp/game_of_life"
	RUN=$(python3 $CURRENT_DIR"/../python/html_builder.py")
	sleep 3
	echo "html-page building: 200"
	echo "run code: $RUN"
done

if [$RUN -eq 0]
echo "exit"
 exec $CURRENT_DIR"/game_of_life_script.sh"
 exit
else
 echo "error in game of life!"
fi
