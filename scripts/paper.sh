bkg="/opt/backgrounds/${1}.sh"
if [ -f "$bkg" ]
then
  echo "Applying ${bkg}..."
  $bkg
  /usr/bin/wbar.sh
else
  echo "That isn't a wallpaper script! Options:"
  ls -1 /opt/backgrounds
fi
