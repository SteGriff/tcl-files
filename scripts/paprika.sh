#! /bin/sh

adr="http://paprika.me.uk?q=$1"
echo $adr
wget $adr
echo 'Done'
