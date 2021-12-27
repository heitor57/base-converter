#!/bin/bash
# ENTRY TEST
make
entry="+AB.A 16 10
-101. 2 16
-32.5 10 8
-10. 10 10
+111.001 2 8
+111111111111111111111111111111111111111111111111. 2 10
+.111111111111111111111111111111111111111111111111 2 16
-1111.01 2 8
+1111.01 2 10
+1111.01 2 16
-77.1 8 2
+77.1 8 10
-77.1 8 16
+10.5 10 2
-10.5 10 8
+10.5 10 16
-AA.B 16 2
+AA.B 16 8
-AA.B 16 10
+0 0 0"
result=`./tp << EOF
$entry
EOF`
count=$((0))
base=0
value=0
for c in $entry
do 
	#echo "Contador: $count"
	if [ $(($count%3)) -eq 2 ]
	then
		obase=$(($c))
		value=$(sed 's/+//; s/-//' <<< $value)
		echo $(echo "scale=50;obase=$obase;ibase=$base;$value" | bc -q)
	elif [ $(($count%3)) -eq 1 ]
	then
		#echo "Base: $c"
		base=$(($c))
		if [ $base -eq 0 ]
		then
			break
		fi
	elif [ $(($count%3)) -eq 0 ]
	then
		#echo "Valor: $c"
		value=$c
	fi
	count=$(($count+1))

done

echo $result
exit
for c in $entry
do 
	read -a temp <<< $c
	resultbc=$($(echo "ibase=$temp[1]; $temp[0]") | bc -q)
	echo "$resultbc"
done

###### CRAP ZONE ###
exit
entry=("+AB.A 16 10" "-101. 2 16" "-32.5 10 8" "-10. 10 10" "+111.001 2 8" "+0 0 0" )
for i in "${entry[@]}"
do
	result=`./prog << EOF
	$i
	EOF`
	echo ${result}
done
