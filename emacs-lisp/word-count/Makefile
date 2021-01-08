.PHONY : all test

all: test

test:
	emacs -Q -batch -L . -l word-count-test.el -f ert-run-tests-batch-and-exit
