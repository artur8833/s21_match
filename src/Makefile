CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
MAIN_FILES= math/*.c 
TEST_FILES= unit_tests/*.c
CHECK_LINK=$(shell pkg-config --libs --cflags check)
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBNAME = s21_math.a
GLFLAGS = --coverage
LIBS = -lcheck -lsubunit -lm -lgcov

all: s21_math.a

object:
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $(MAIN_FILES)

lib:
	ar rcs s21_math.a *.o

s21_math.a:
	$(CC) $(CFLAGS) -c $(MAIN_FILES)
	ar rc s21_math.a *.o
	ranlib s21_math.a

test: s21_math.a
	$(CC) $(CFLAGS) $(TEST_FILES) -L. s21_math.a $(CHECK_LINK) $(GLFLAGS) $(GCOVFLAGS) -o s21_math_tests
	./s21_math_tests

gcov_report: object lib test
	gcov *.gcno *.gcda
	~/.local/bin/gcovr -r . --html --html-details -o s21_math.html
	open s21_math.html

clean:
	rm -f *.o
	rm -f *.a
	rm -f unit_tests/*.o
	rm -f unit_tests/*.a
	rm -f math/*.o
	rm -f math/*.a
	rm -rf *.gcno
	rm -rf *.gcov
	rm -rf *.gcda
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -f ./s21_math_tests

clang:
	clang-format $(MAIN_FILES) -n
	clang-format $(TEST_FILES) -n
	clang-format unit_tests/*.h -n