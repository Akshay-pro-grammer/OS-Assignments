echo "enter the year"
read y
if [ -z "$y" ]
then
y=$(date +"%Y")
fi
if [ $((y%100)) -eq 0 ] || [ $((y%4)) -eq 0 ] && [ $((y%100)) -ne 0 ]
	then
		echo "$y is a leap year"
	else 
		echo "$y is not a leap year"
fi
