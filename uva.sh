#!/usr/bin/env bash
code=$1
matches=$(ls code | egrep "^${code}(_.*?)?\.c(pp)?$")
matchesCount=$(echo $matches | wc -l)
if [ $matchesCount == 1 ]
  filename=$(echo $matches)
  then echo "Compiling $filename..."
  if [[ $filename =~ ^.*c$ ]] ; then
    #C program
    compresult=$(gcc code/$filename -o bin/$code.o -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE)
    if [ $? == 0 ]; then
    	echo "Compiled!"
	echo "Starting test cases..."
        inputs=$(ls input | egrep "^${code}(_.*?)?\.txt$")
	printf '%s\n' "$inputs" | while IFS= read -r line
	do
   	  if [ ! -f output/$line ]; then
            echo "	No suitable output found for $line!"
          else
	    printf "	Running test case $line..."
	    bin/$code.o < input/$line | cmp --silent output/$line
	    if [ $? == 0 ]; then printf "Passed!\n"
	    else printf "NOK!\n"
	    fi
	  fi
	done
	echo "Done!"
    fi
  else
    echo "not OK"
  fi
else
  echo "No file found for problem $code"
fi
