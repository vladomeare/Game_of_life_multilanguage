#!/bin/bash

P=$( pwd )

echo "CURRENT_DIR=/""$P"/"" >> ./script/game_of_life_script.sh

cat >> ./script/game_of_life_script.sh << EOF

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

EOF

chmod +x ./script/game_of_life_script.sh

cat > /etc/systemd/system/Game_of_life.service << EOF
[Unit]
Description=Daemon for game of life

[Service]
EOF
echo "ExecStart="$P"/script/game_of_life_script.sh" >> /etc/systemd/system/Game_of_life.service
cat >> /etc/systemd/system/Game_of_life.service << EOF
Restart=always

[Install]
WantedBy=multi-user.target
EOF

chmod 664 /etc/systemd/system/Game_of_life.service
systemctl daemon-reload 
systemctl start Game_of_life.service
systemctl status /etc/systemd/system/Game_of_life.service
