.PHONY : build clean test

build:
	@./script/build.sh

clean:
	@-rm -r build
test:
	@make
	@clear
	@./build/test/test_main
