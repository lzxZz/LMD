objs = ./out/main.o ./out/code.o ./out/document.o ./out/image.o ./out/list.o ./out/math.o ./out/order.o ./out/quot.o ./out/read.o ./out/table.o ./out/text.o ./out/title.o ./out/parser.o
FLAG = -g -Wall

TARGER = ./debug/lmd
term_h = ./include/term.h
vpath %.h ./include
vpath %.cpp ./src
vpath %.o ./out

./debug/lmd: $(objs)
	g++ $(FLAG) -o  ./debug/lmd $(objs) 
    

./out/main.o : main.cpp read.h term.h
	gcc -c $(FLAG) ./src/main.cpp -o ./out/main.o -std=c++11
./out/parser.o : parser.cpp parser.h term.h
	gcc -c $(FLAG) ./src/parser.cpp -o ./out/parser.o -std=c++11
./out/code.o : code.cpp term.h
	gcc -c $(FLAG) ./src/code.cpp -o ./out/code.o -std=c++11

./out/document.o : document.cpp term.h
	gcc -c $(FLAG) ./src/document.cpp -o ./out/document.o -std=c++11
./out/image.o : image.cpp term.h
	gcc -c $(FLAG) ./src/image.cpp -o ./out/image.o -std=c++11

./out/list.o : list.cpp term.h
	gcc -c $(FLAG) ./src/list.cpp -o ./out/list.o  -std=c++11

./out/math.o : math.cpp term.h
	gcc -c $(FLAG) ./src/math.cpp -o ./out/math.o  -std=c++11

./out/order.o : order.cpp term.h
	gcc -c $(FLAG) ./src/order.cpp -o ./out/order.o  -std=c++11

./out/quot.o : quot.cpp term.h
	gcc -c $(FLAG) ./src/quot.cpp -o ./out/quot.o  -std=c++11

./out/read.o : read.cpp term.h
	gcc -c $(FLAG) ./src/read.cpp -o ./out/read.o  -std=c++11

./out/table.o : table.cpp term.h
	gcc -c $(FLAG) ./src/table.cpp -o ./out/table.o  -std=c++11

./out/text.o : text.cpp term.h
	gcc -c $(FLAG) ./src/text.cpp -o ./out/text.o  -std=c++11

./out/title.o : title.cpp term.h
	gcc -c $(FLAG) ./src/title.cpp -o ./out/title.o  -std=c++11

.PHONY:clean
.PHONY:cleanobj
.PHONY:test
.PHONY:local

clean:
	rm ./debug/lmd ./out/*.o
cleanobj:
	rm $(objs)

test:
	./debug/lmd -char utf-8  -css /css/style.css ./readme.md
local:
	./debug/lmd -char utf-8 -css F:/website/css/style.css ./readme.md


