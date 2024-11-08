filename=$1
line=$(wc $filename | wc -l)
word=$(wc $filename | wc -w)
char=$(wc $filename | wc -m)
echo "filename   linecount  wordcount  charcount"
echo "$filename     $line           $word        $char" 
