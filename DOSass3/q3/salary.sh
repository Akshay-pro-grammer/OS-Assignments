echo "enter your salary Ramesh: "
read s
a=0.4
b=0.2
dearness=$(echo "$s*$a" | bc)
rent=$(echo "$s*$b" | bc)
echo "da is : $dearness"
echo "hra is : $rent"
gross=$(echo "$s+$dearness+$rent" | bc)
echo "The gross salary is: $gross"
