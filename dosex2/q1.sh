#!/bin/bash

# C-style for loop
for ((i = 0; i < 10; i++))
do
    echo "Enter hours worked by Employee $((i + 1)):"
    read hours

    if [ $hours -gt 40 ]; then
        overtime=$((hours - 40))
        overtime_pay=$((overtime * 12))
        echo "Employee $((i + 1)) Overtime Pay: Rs. $overtime_pay"
    else
        echo "Employee $((i + 1)) worked less than or equal to 40 hours. No overtime pay."
    fi
done
