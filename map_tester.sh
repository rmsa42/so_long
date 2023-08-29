RUN=valgrind ./so_long
MAPS=$(find map/invalid -name "*.ber")

make re
for i in $MAPS; do
    echo $i
    $RUN $i
done
