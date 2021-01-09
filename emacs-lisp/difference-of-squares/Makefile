.PHONY : all test

all: test

test:
	emacs -Q -batch -L . -l difference-of-squares-test.el -f ert-run-tests-batch-and-exit
