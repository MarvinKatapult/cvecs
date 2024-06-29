COMP_CMD="gcc -o example example.c cvecs.c -Wall -Wextra -pedantic -g"

execute() {
    echo $1
    eval $1
}

execute "$COMP_CMD"
