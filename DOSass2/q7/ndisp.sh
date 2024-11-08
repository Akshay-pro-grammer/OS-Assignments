n=$1
m=$2
filename=$3
flines=$(head -n $n $filename)
llines=$(tail -n $m $filename)
echo "The first $n lines are: "
echo "$flines"
echo "The last $m lines are: "
echo "$llines"

