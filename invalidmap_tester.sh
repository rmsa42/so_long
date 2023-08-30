MAPS=$(find map/invalid -name "*.ber")

make re
for i in $MAPS; do
    echo $i
    valgrind ./so_long $i &> Valgrind_Result.txt
	cat Valgrind_Result.txt | grep "All heap blocks" | cut -b 1
    echo -e "\n"
done

rm Valgrind_Result.txt
