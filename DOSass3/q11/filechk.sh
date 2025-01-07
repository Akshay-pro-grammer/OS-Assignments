if [ "$#" -ne 2 ]; then
    echo "Usage: $0 filename1 filename2"
    exit 1
fi
file1=$1
file2=$2
if [ ! -e "$file1" ]; then
    echo "File $file1 does not exist."
    exit 1
elif [ ! -e "$file2" ]; then
    echo "File $file2 does not exist."
    exit 1
fi
if cmp -s "$file1" "$file2"; then
    echo "Files $file1 and $file2 have the same content."
    rm "$file2"
    echo "So $file2 is deleted."
else
    echo "Files $file1 and $file2 have different content."
fi

