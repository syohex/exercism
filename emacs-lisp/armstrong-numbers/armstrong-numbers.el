;;; armstrong-numbers.el --- armstrong-numbers Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun armstrong-p (n)
  (cl-loop with str = (number-to-string n)
           with len = (length str)
           for c across str
           sum (expt (- c ?0) len) into s
           finally
           return (= s n)))

(provide 'armstrong-numbers)
;;; armstrong-numbers.el ends here
