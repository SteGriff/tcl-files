. /etc/init.d/tc-functions
BATDIR=$(cat /home/tc/batdir)

if [ -d $BATDIR ];
then

STAT=$(cat ${BATDIR}"/status")

if [ "$STAT" = "Discharging" ]; then
	STAT="-"
else
	STAT="+"
fi

FULL=$(cat ${BATDIR}"/charge_full")
CHRG=$(cat ${BATDIR}"/charge_now")
PC=$(( 100*$CHRG/$FULL ))
FORMAT="${PC}%${NORMAL} ${STAT}"

if [ $PC -lt 15 ]; then
	echo $RED$FORMAT
elif [ $PC -lt 30 ]; then
	echo $YELLOW$FORMAT
else
	echo $FORMAT
fi

else
echo "Running on mains."
fi
