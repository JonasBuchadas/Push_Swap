C=$2
L=$3
for i in {1..100};
do
	ARG=`seq $C | shuf | paste -sd " "`
	if [ `$1 $ARG | wc -l` -gt $L ];
	then
		echo "KO: Over $L"
	else
		echo "OK"
	fi
done
