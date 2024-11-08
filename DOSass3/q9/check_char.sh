echo "Enter a Character:"
read c
if [ $(echo -n "$c" | wc -c) -gt 1 ]; then
  echo "You have entered more than one character"
else
  if [[ "$c" =~ [a-z] ]]; then
    echo "You entered a lower case alphabet"
  elif [[ "$c" =~ [A-Z] ]]; then
    echo "You entered an upper case alphabet"
  elif [[ "$c" =~ [0-9] ]]; then
    echo "You have entered a digit"
  else
    echo "You have entered a special symbol"
  fi
fi
