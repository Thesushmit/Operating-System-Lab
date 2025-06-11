#!/bin/bash

echo "Enter marks for m1:"
read m1
echo "Enter marks for m2:"
read m2
echo "Enter marks for m3:"
read m3

total=$((m1 + m2 + m3))
percentage=$((total / 3))

echo "Total Marks: $total"
echo "Percentage: $percentage%"

if [ $percentage > 80 ]; then
    echo "Grade: A"
elif [ $percentage > 70 ]; then
    echo "Grade: B"
elif [ $percentage > 60 ]; then
    echo "Grade: C"
else
    echo "Grade: Fail"
fi

