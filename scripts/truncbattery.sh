. /etc/init.d/tc-functions
BATDIR="/home/tc/batdir"
[ -d $BATDIR ] && echo "$(calc 100*$(cat $(cat $BATDIR)"/charge_now")/$(cat $(cat $BATDIR)"/charge_full"))%" || echo "Mains power."
