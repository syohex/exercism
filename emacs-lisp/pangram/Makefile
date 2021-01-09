.PHONY : all test

all: test

test:
	emacs -Q -batch -L . -l pangram-test.el -f ert-run-tests-batch-and-exit
