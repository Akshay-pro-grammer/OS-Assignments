echo "Enter the number 1"
read a
echo "Enter the number 2"
read b
add=$(echo "$a+$b" | bc)
echo "addition is : $add"
sub=$(echo "$a-$b" | bc)
echo "subtraction is : $sub"
mul=$(echo "$a*$b" | bc)
echo "Multiplication is : $mul"
div=$(echo "$a/$b" | bc)
echo "Division is : $div"
