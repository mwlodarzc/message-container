TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++17 -iquote inc

${TRGDIR}/mes_con: ${OBJ} ${OBJ}/main.o
	g++ -o ${TRGDIR}/mes_con ${OBJ}/main.o
	
${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp 
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

clear:
	rm -r ${OBJ} mes_con
