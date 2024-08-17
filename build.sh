BIN_NAME="example"
CFLAGS="-Wall -Wextra -pedantic -g"
COMP_CMD="gcc -o ${BIN_NAME} example.c cvecs.c ${CFLAGS}"
#COMP_CMD="gcc -o ${BIN_NAME} c_string_example.c cvecs.c ../cstring/cstring.c ${CFLAGS} -I../cstring/ -D__USE_CSTRING__" #Example for with CString

execute() {
    echo $1
    eval $1
}

if [ "$1" = "clean" ]; then
    execute "rm ${BIN_NAME}"
else
    execute "$COMP_CMD"
fi
