#! /bin/ash
# Backup and shutdown

. /etc/init.d/tc-functions
clear
echo Backing up:
echo
yes | backup
echo
echo Done
sudo poweroff

