echo "enter the cost price"
read cp
echo "enter the selling price"
read sp
difference=$(echo "$sp-$cp" | bc)
if [ $difference -lt 0 ]
then 
echo "loss of $difference"
else
echo "profit of $difference"
fi
