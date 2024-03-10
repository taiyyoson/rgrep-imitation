CC = gcc
FLAGS = -std=c99 -O0 -Wall -Werror -g -pedantic

default:
	$(CC) $(FLAGS) rgrep.c matcher.c -o rgrep

clean:
	rm -f rgrep
	rm -rf *.dSYM

check: clean default
	test "`echo -e "a\nb\nc" | ./rgrep 'a'`" = "a"
	test "`echo -e "a\n" | ./rgrep 'a'`" = "a"
	test "`echo -e "a" | ./rgrep '...'`" = ""
	test "`echo -e "abc" | ./rgrep '.b.'`" = "abc"
	test "`echo -e "h\naaaaah" | ./rgrep 'a+h'`" = "aaaaah"
	test "`echo -e "h\naaaaahhhhh" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo -e "h\naaaaahhhhh\n" | ./rgrep 'aa+hh+'`" = "aaaaahhhhh"
	test "`echo -e "woot\nwot\nwat\n" | ./rgrep 'wo?t'`" = "wot"
	test "`echo -e "CCCCCCC\nC+\nC++" | ./rgrep '.\+\+'`" = "C++"
	test "`echo -e "GG" | ./rgrep 'G+'`" = "GG"
	test "`echo -e "USF_CS221.jpg" | ./rgrep 'U.F_CL?S2+1\.jpg'`" = "USF_CS221.jpg"
	@echo "Passed sanity check."

