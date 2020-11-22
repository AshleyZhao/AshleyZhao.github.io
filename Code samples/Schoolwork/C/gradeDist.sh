#A script that takes two parameters: a marking script and a directory of submission files, and returns the grade distribution for the files.
#Katie Yang - 10139334
#Ashley Zhao - 10193698

if (($#!=2))
then
    echo "error: gradeDist.sh needs two arguments" >&2
    exit 1
fi

if [[ !  -x $1  ]]
then
    echo "error: $1 is not an existing, executable file" >&2
    exit 2
fi

if [[ ! -d $2  ]]
then
    echo "error: folder $2 does not exist" >&2
    exit 2
fi

SCRIPT=$1
FOLDER=$2

A=0
B=0
C=0
D=0
F=0

for FILE in $FOLDER/*
do
    GRADE=$($SCRIPT $FILE)
    if [[ $GRADE == "A" ]]
    then
	((A++))
    elif [[ $GRADE == "B" ]]
    then
	((B++))
    elif [[ $GRADE == "C" ]]
    then
	((C++))
    elif [[ $GRADE == "D" ]]
    then
	((D++))
    else
	((F++))
    fi
done

echo "A: $A"
echo "B: $B"
echo "C: $C"
echo "D: $D"
echo "F: $F"
