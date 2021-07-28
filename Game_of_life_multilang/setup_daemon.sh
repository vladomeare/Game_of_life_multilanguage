#!/bin/bash

PATH=$( pwd )

cat > /etc/systemd/system/Game_of_life.service << EOF
/[Unit]
Description=Daemon for game of life
/[Service]
ExecStart= $PATH
Restart=always
/[Install]
WantedBy=multi-user.target
EOF

chmod -x /etc/systemd/system/Game_of_life.service
systemctl daemon-reload 
systemctl enable --now /etc/systemd/system/Game_of_life.service
systemctl status /etc/systemd/system/Game_of_life.service
