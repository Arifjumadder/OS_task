// Find Even and Odd NUmber

#!/bin/bash

read -p "Enter a number: " num

if ! [[ "$num" =~ ^-?[0-9]+$ ]]; then
    echo "Invalid input. Please enter an integer."
    exit 1
fi

if (( num % 2 == 0 )); then
    echo "$num is Even."
else
    echo "$num is Odd."
fi


//Calculate fibonacci

#!/bin/bash

read -p "Enter the number of terms: " n

if ! [[ "$n" =~ ^[0-9]+$ ]]; then
    echo "Invalid input. Please enter a non-negative integer."
    exit 1
fi

a=0
b=1

echo "Fibonacci Series up to $n terms:"

for (( i=0; i<n; i++ ))
do
    echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
done

echo


//Compare two numbers
#!/bin/bash

read -p "Enter first number: " num1
read -p "Enter second number: " num2

if [ "$num1" -gt "$num2" ]; then
    echo "$num1 is greater than $num2"
elif [ "$num1" -lt "$num2" ]; then
    echo "$num2 is greater than $num1"
else
    echo "Both numbers are equal"
fi


// A number is Prime or not

#!/bin/bash

read -p "Enter a number: " num

if [ $num -le 1 ]; then
    echo "$num is not a prime number."
    exit
fi

is_prime=1

for ((i = 2; i <= num / 2; i++)); do
    if [ $((num % i)) -eq 0 ]; then
        is_prime=0
        break
    fi
done

if [ $is_prime -eq 1 ]; then
    echo "$num is a prime number."
else
    echo "$num is not a prime number."
fi

// Calculate GCD and LCM

#!/bin/bash

read -p "Enter first number: " a
read -p "Enter second number: " b

gcd() {
    local x=$1
    local y=$2
    while [ $y -ne 0 ]; do
        local temp=$y
        y=$((x % y))
        x=$temp
    done
    echo $x
}

g=$(gcd $a $b)
l=$(( (a * b) / g ))

echo "GCD of $a and $b is: $g"
echo "LCM of $a and $b is: $l"

// Find the max of an array

#!/bin/bash

read -p "Enter the number of elements: " n
echo "Enter $n numbers:"
for (( i=0; i<n; i++ ))
do
    read arr[i]
done

max=${arr[0]}

for (( i=1; i<n; i++ ))
do
    if [ ${arr[i]} -gt $max ]; then
        max=${arr[i]}
    fi
done

echo "Maximum value is: $max"





