CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
det_OS = -lcheck -lm -lpthread -lsubunit

all: clean s21_math.a test gcov_report

s21_math.a: s21_math.o
	ar rcs s21_math.a *.o
	ranlib s21_math.a

s21_math.o:
	$(CC) $(CFLAGS) s21_*.c -c
	
s21_math: s21_math.a
	gcc -g main.c -lm -L. -o main -ls21_math -lcheck_pic -pthread -lrt -lm -lsubunit
clean:
	rm -rf *.o 
	rm -rf main 
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.gcov 
	rm -rf report

clang:
	clang-format -style=Google -n *.c *.h tests/*.c tests/*.h

style:
	clang-format -style=Google -i *.c *.h tests/*.c tests/*.h

test: clean
	$(CC) $(CFLAGS) --coverage s21_*.c tests/s21_*.c -o testout $(det_OS)
	./testout

gcov_report: test
	mkdir report
	~/.local/bin/gcovr -r. --html --html-details -o report/index.html -e tests 
	# genhtml -o report math.info
	open report/index.html
	rm -rf *.gcno *gcda *.gcov 
	# rm -rf report

