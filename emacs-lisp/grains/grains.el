;;; grains.el --- Grains exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun square (num)
  (expt 2 (1- num)))

(defun total ()
  (cl-loop for i from 1 to 64
           sum (square i)))

(provide 'grains)
;;; grains.el ends here
