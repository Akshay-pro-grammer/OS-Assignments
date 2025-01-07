echo "enter three numbers"
read a
read b
read c
small=$a
if [ $b -lt $small ]
then 
small=$b
fi
if [ $c -lt $small ]
then
small=$c
fi
echo "small out of the three is: $small"
