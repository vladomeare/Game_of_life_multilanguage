#!/bin/bash

chmod +x ./script/game_of_life_script.sh

P=$( pwd )

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
