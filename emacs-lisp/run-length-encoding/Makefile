.PHONY : all test

all: test

test:
	emacs -Q -batch -L . -l run-length-encoding-test.el -f ert-run-tests-batch-and-exit
