BIN_NAME="example"
CFLAGS="-Wall -Wextra -pedantic -g"
COMP_CMD="gcc -o ${BIN_NAME} example.c cvecs.c ${CFLAGS}"

execute() {
    echo $1
    eval $1
}

if [ "$1" = "clean" ]; then
    execute "rm ${BIN_NAME}"
else
    execute "$COMP_CMD"
fi
