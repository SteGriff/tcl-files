if [ -e $1 ]
then
  [ -d $1 ] && echo "${1} is a directory." || ls -1al $1
fi
