# Check if exactly three arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Invalid input"
    echo "Enter input in the following format: op1 operator op2"
    exit 1
fi
# Assign command-line arguments to variables for readability
op1=$1
operator=$2
op2=$3
# Check if the first and third arguments are numbers
if ! [[ "$op1" =~ ^-?[0-9]+(\.[0-9]+)?$ ]] || ! [[ "$op2" =~ ^-?[0-9]+(\.[0-9]+)?$ ]]; then
    echo "Invalid input"
    echo "Enter input in the following format: op1 operator op2"
    exit 1
fi
# Perform the arithmetic operation based on the operator
case "$operator" in
    +)
        result=$(echo "$op1 + $op2" | bc)
        ;;
    -)
        result=$(echo "$op1 - $op2" | bc)
        ;;
    x)
        result=$(echo "$op1 * $op2" | bc)
        ;;
    /)
        if [ "$op2" == "0" ]; then
            echo "Error: Division by zero"
            exit 1
        fi
        result=$(echo "scale=2; $op1 / $op2" | bc)
        ;;
    %)
        result=$(echo "$op1 % $op2" | bc)
        ;;
    ^)
        result=$(echo "$op1 ^ $op2" | bc)
        ;;
    *)
        echo "Invalid input"
        echo "Enter input in the following format: op1 operator op2"
        exit 1
        ;;
esac
# Display the result
echo "$op1 $operator $op2 = $result"
