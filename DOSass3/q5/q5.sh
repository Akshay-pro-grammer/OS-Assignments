echo "enter the cost price"
read cp
echo "enter the selling price"
read sp
diff=$(echo "$sp-$cp" | bc)
if [ $diff -lt 0 ]
then 
echo "loss of $diff"
else
echo "profit of $diff"
fi
