srcf="${1}.c"
binf="${1}"
echo "	-Building C program from ${srcf} to ${binf}..."
gcc -Wall $srcf -o $binf
echo "	-Done. Running ${binf}... "
$binf
echo "	-Finished."
