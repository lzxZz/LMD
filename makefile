objs = ./out/main.o ./out/code.o ./out/document.o ./out/image.o ./out/list.o \
./out/math.o ./out/order.o ./out/quot.o ./out/read.o ./out/table.o ./out/text.o ./out/title.o

term_h = ./include/term.h

./debug/lmd: $(objs)
	g++ -o ./debug/lmd $(objs)
    
./out/main.o : ./src/main.cpp ./include/read.h ./include/term.h
	gcc -c ./src/main.cpp -o ./out/main.o

./out/code.o : ./src/code.cpp ./include/term.h
	gcc -c ./src/code.cpp -o ./out/code.o

./out/document.o : ./src/document.cpp $(term_h)
	gcc -c ./src/document.cpp -o ./out/document.o

./out/image.o : ./src/image.cpp $(term_h)
	gcc -c ./src/image.cpp -o ./out/image.o

./out/list.o : ./src/list.cpp $(term_h)
	gcc -c ./src/list.cpp -o ./out/list.o

./out/math.o : ./src/math.cpp $(term_h)
	gcc -c ./src/math.cpp -o ./out/math.o

./out/order.o : ./src/order.cpp $(term_h)
	gcc -c ./src/order.cpp -o ./out/order.o

./out/quot.o : ./src/quot.cpp $(term_h)
	gcc -c ./src/quot.cpp -o ./out/quot.o

./out/read.o : ./src/read.cpp $(term_h)
	gcc -c ./src/read.cpp -o ./out/read.o

./out/table.o : ./src/table.cpp $(term_h)
	gcc -c ./src/table.cpp -o ./out/table.o

./out/text.o : ./src/text.cpp $(term_h)
	gcc -c ./src/text.cpp -o ./out/text.o

./out/title.o : ./src/title.cpp $(term_h)
	gcc -c ./src/title.cpp -o ./out/title.o

clean:
	rm ./debug/lmd $(objs)


