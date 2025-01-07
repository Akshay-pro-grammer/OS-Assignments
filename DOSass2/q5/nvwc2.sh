filename=$1
line=$(wc -l < $filename)
word=$(wc -w < $filename)
char=$(wc -m < $filename)
echo "filename   linecount  wordcount  charcount"
echo "$filename     $line           $word        $char" 
