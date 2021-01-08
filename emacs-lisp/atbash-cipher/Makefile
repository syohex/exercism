.PHONY : all test

all: test

test:
	emacs -Q -batch -L . -l atbash-cipher-test.el -f ert-run-tests-batch-and-exit
