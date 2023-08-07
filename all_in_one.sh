#!/bin/bash
#prime or not
echo "Enter a number"
read num

if [ $num -lt 2 ]; then
    echo "$num is not a prime number."
    exit
fi

flag=0
for ((i=2; i<=$num/2; i++))
do
	if [ $(( num % i )) -eq 0 ]
	then 
		flag=1
		break
	fi
done
if [ $flag -eq 0 ]
then 
	echo "$num is prime"
else
	echo "$num is not prime"
fi
#calculator
echo "Enter two numbers"
read num1
read num2
echo "Enter 1 for addition 2 for subtraction 3 for multiplication 4 for division"
read choice
case ${choice} in 
	1) operation=`expr $num1 + $num2`
	;;
	2) operation=`expr $num1 - $num2`
	;;
	3) operation=`expr $num1 * $num2`
	;;
	4) 
	if [ $num2 -eq 0 ]
	then
		operation="division cannot be done"
	else
		operation=`expr $num1 / $num2`
	fi
	;; 
	*)
		operation="no choice applied"
	;;
esac

echo "$operation"

#area of circle
echo -n "Enter the radius of a circle : "
read r
area=$(echo "3.14 * ($r * $r)" | bc)
echo "Area of circle is $area"

#armstrong
echo "Enter a number"
read n
temp=$n
count=0
check=0
while [ $n -ne 0 ]
do
	n=`expr $n / 10`
	((count++))
done
n=$temp
while [ $n -ne 0 ]
do 
	remainder=`expr $n % 10`
	check=$(echo "$check+($remainder^$count)" | bc)
	n=`expr $n / 10`
done
if [ $check -eq $temp ]
then
	echo "$temp is armstrong"
else
	echo "$temp is not armstrong"
fi

#palindrome
echo "Enter a string"
read word
rev=""
len=${#word}
for (( i=$len-1; i>=0; i-- ))
do
   rev="$rev${word:$i:1}"
done
if [ $rev = $word ]
then 
	echo "$word is a palindrome"
else
	echo "$word is not a palindrome"
fi

#fibonacci
echo "Enter the limit"
read n
i=0
a=0
b=1
while [ $i -lt $n ]
do
	echo $a
	b=$(($a+$b))
	a=$(($b-$a))
	((i++))
done

#num palindrome
echo "Enter a number"
read num
temp=$num
rev=0
while [ $temp -ne 0 ]
do
	rev=$(echo "($rev*10)+($temp%10)" | bc)
	temp=`expr $temp / 10`
done 
if [ $rev -eq $num ]
then
	echo "$num is palindrome"
else 
	echo "$num is not palindrome"
fi
