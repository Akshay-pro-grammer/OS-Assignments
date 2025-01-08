echo "Enter marks for 5 :"
read a
read b
read c
read d
read e

total=$(echo "$a+$b+$c+$d+$e" | bc)

percentage=$((total / 5))

echo "Percentage: $percentage%"

if [ $percentage -ge 60 ]; then
    echo "First division"
elif [ $percentage -ge 50 ]; then
    echo "Second division"
elif [ $percentage -ge 40 ]; then
    echo "Third division"
else
    echo "Fail"
fi
