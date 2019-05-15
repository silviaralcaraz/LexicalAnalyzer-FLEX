p2Compiladores:
	lex python.l
	gcc *.c -g -o p2Compiladores -lfl -ll
