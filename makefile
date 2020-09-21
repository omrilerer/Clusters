LIBS = -lm

all: main.o modMax.o spmat.o computeF.o createG.o createG1G2.o createS.o divideG.o inputRead.o matrixOps.o mix.o multDiag.o outputWrite.o powerIt.o shiftMat.o arrayOps.o matVecMult.o mainFuncs.o modMaxFuncs.o
	gcc modMax.o main.o spmat.o computeF.o createG.o createG1G2.o createS.o divideG.o inputRead.o matrixOps.o mix.o multDiag.o outputWrite.o powerIt.o shiftMat.o arrayOps.o matVecMult.o mainFuncs.o modMaxFuncs.o -o cluster $(LIBS)
clean:
	rm -rf *.o prog
main.o: main.c spmat.h inputRead.h divideG.h outputWrite.h mainFuncs.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c main.c
spmat.o: spmat.c spmat.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c spmat.c
computeF.o: computeF.c spmat.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c computeF.c
createG.o: createG.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c createG.c
createG1G2.o: createG1G2.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c createG1G2.c
createS.o: createS.c multDiag.h mix.h spmat.h matrixOps.h matVecMult.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c createS.c
divideG.o: divideG.c spmat.h shiftMat.h computeF.h powerIt.h createS.h createG1G2.h modMax.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c divideG.c
inputRead.o: inputRead.c spmat.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c inputRead.c
matrixOps.o: matrixOps.c spmat.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c matrixOps.c
mix.o: mix.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c mix.c
multDiag.o: multDiag.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c multDiag.c
outputWrite.o: outputWrite.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c outputWrite.c
powerIt.o: powerIt.c multDiag.h mix.h spmat.h matrixOps.h 
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c powerIt.c
shiftMat.o: shiftMat.c spmat.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c shiftMat.c
modMax.o: modMax.c spmat.h matrixOps.h multDiag.h mix.h arrayOps.h matVecMult.h modMaxFuncs.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c modMax.c
arrayOps.o: arrayOps.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c arrayOps.c
matVecMult.o: matVecMult.c multDiag.h mix.h spmat.h matrixOps.h
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c matVecMult.c
mainFuncs.o: mainFuncs.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c mainFuncs.c
modMaxFuncs.o: modMaxFuncs.c
	gcc -ansi -Wall -Wextra -Werror -pedantic-errors -c modMaxFuncs.c
	


