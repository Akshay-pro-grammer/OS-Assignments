echo "enter internal mark"
read m
echo "enter percentage of attendance"
read p

if [ $m -ge 20 ] && [ $p -ge 75 ]
then 
echo "allowed for semester"
else
echo "not allowed for semester"
fi
