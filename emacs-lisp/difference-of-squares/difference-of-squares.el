;;; difference-of-squares.el --- Difference of Squares (exercism)

;;; Commentary:

;;; Code:

(defun square-of-sum (n)
  (cl-loop for i from 1 to n
           sum i into a
           finally
           return (* a a)))

(defun sum-of-squares (n)
  (cl-loop for i from 1 to n
           sum (* i i)))

(defun difference (n)
  (- (square-of-sum n) (sum-of-squares n)))

(provide 'difference-of-squares)
;;; difference-of-squares.el ends here
