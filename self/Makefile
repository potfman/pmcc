CC = tcc

all:
	make clean
	make main

main: main.o parse.a lex.a gen.a util.o sys.o
	ld -o $@ $^

main.o: ../src/main.c
	./origc $@ $^

lex.a: lex.o basic.o eof.o ident.o num.o op.o str.o
	ar r $@ $^

lex.o: ../src/lex/lex.c
	./origc $@ $^

basic.o: ../src/lex/basic.c
	./origc $@ $^

eof.o: ../src/lex/eof.c
	./origc $@ $^

ident.o: ../src/lex/ident.c
	./origc $@ $^

num.o: ../src/lex/num.c
	./origc $@ $^

op.o: ../src/lex/op.c
	./origc $@ $^

str.o: ../src/lex/str.c
	./origc $@ $^

parse.a: parse.o expr.o stmt.o func.o type.o
	ar r $@ $^

parse.o: ../src/parse/parse.c
	./origc $@ $^

expr.o: ../src/parse/expr.c
	./origc $@ $^

stmt.o: ../src/parse/stmt.c
	./origc $@ $^

func.o: ../src/parse/func.c
	./origc $@ $^

type.o: ../src/parse/type.c
	./origc $@ $^

gen.a: gen.o flow.o funcs.o gvars.o ops.o llvm.o vars.o
	ar r $@ $^

gen.o: ../src/gen/gen.c
	./origc $@ $^

flow.o: ../src/gen/flow.c
	./origc $@ $^

funcs.o: ../src/gen/funcs.c
	./origc $@ $^

gvars.o: ../src/gen/gvars.c
	./origc $@ $^

ops.o: ../src/gen/ops.c
	./origc $@ $^

llvm.o: ../src/gen/llvm.c
	./origc $@ $^

vars.o: ../src/gen/vars.c
	./origc $@ $^

util.o: ../src/util.c
	./origc $@ $^

sys.o: ../src/sys.s
	as -o $@ $^

test: main
	./test.sh

clean:
	$(RM) *.o
	$(RM) *.a
	$(RM) main

.PHONY: all test clean
