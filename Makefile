CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17
LIBS = -lgtest -lstdc++
GCOV_FLAGS = -fprofile-arcs -ftest-coverage
BREW_FLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib
OS := $(shell uname)

ifeq ($(OS), Darwin)
	OPEN_CMD = open
else
	OPEN_CMD = xdg-open 
	LIBS += -lpthread -lrt -lsubunit -lm
endif

all: clean s21_matrix.a gcov_report

s21_matrix.a:
	$(CC) $(CFLAGS) -c s21_matrix_oop.cpp
	# ar rc s21_matrix.a s21_matrix.o
	ar rc s21_matrix.a s21_matrix_oop.cpp
	ranlib s21_matrix.a
	rm -rf *.o	

test: tests.cpp s21_matrix.a
	$(CC) $(CFLAGS) $(BREW_FLAGS) tests.cpp s21_matrix.a $(LIBS) -o s21_test
	# $(CC) $(CFLAGS) tests.cpp s21_matrix.a $(LIBS) -o s21_test
	./s21_test


gcov_report: 
	$(CC) $(CFLAGS) $(BREW_FLAGS) $(GCOV_FLAGS) tests.cpp s21_matrix_oop.cpp $(LIBS) -o s21_test
	# $(CC) $(CFLAGS) $(GCOV_FLAGS) s21_matrix_oop.cpp $(LIBS) -o s21_test
	./s21_test
	gcov s21_test-s21_matrix.cpp  
	lcov --capture --directory . --output-file coverage.info --ignore-errors inconsistent                   
	lcov --remove coverage.info '*/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory out
	open out/index.html


clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov *.html *.css
	rm -rf ./report
	rm -rf s21_test

valgrind: 
	$(CC) $(CFLAGS) tests.cpp s21_matrix.a $(LIBS) -o s21_test
	valgrind --tool=memcheck --leak-check=yes ./s21_test

leaks: s21_matrix.a
	$(CC) $(CFLAGS) $(BREW_FLAGS) tests.cpp s21_matrix.a $(LIBS) -o s21_test
	leaks -atExit -- ./s21_test

style_check:
	clang-format -style=Google -n *.h *.cpp 

style_correct:
	clang-format -style=Google -i *.cpp 
	clang-format -style=Google -i *.h 

