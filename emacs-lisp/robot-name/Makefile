.PHONY : all test

all: test

test:
	emacs -Q -batch -L . -l robot-name-test.el -f ert-run-tests-batch-and-exit
