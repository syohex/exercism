;;; perfect-numbers.el --- perfect-numbers Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun classify (number)
  (unless (>= number 0)
    (error "Classification is only possible for natural numbers"))
  (cl-loop for i from 1 to (/ number 2)
           when (zerop (mod number i))
           sum i into s
           finally
           return (cond ((= s number) 'perfect)
                        ((> s number) 'abundant)
                        (t 'deficient))))

(provide 'perfect-numbers)
;;; perfect-numbers.el ends here
