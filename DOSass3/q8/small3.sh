echo "enter three numbers"
read a
read b
read c
max=$a
if [ $b -gt $max ]
then 
max=$b
fi
if [ $c -gt $max ]
then
max=$c
fi
echo "Max out of the three is: $max"
