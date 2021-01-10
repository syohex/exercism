;;; hamming.el --- Hamming (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun hamming-distance (a b)
  (unless (= (length a) (length b))
    (error "Length of both arguments must be equal"))
  (cl-loop for c1 across a
           for c2 across b
           count (/= c1 c2)))

(provide 'hamming)
;;; hamming.el ends here
