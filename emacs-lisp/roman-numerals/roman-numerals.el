;;; roman-numerals.el --- roman-numerals Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun to-roman (num)
  (let (ret)
    (when (>= num 1000)
      (cl-loop with count = (/ num 1000)
               repeat count
               do
               (progn
                 (push "M" ret)
                 (cl-decf num 1000))))
    (when (>= num 900)
      (push "CM" ret)
      (cl-decf num 900))
    (when (>= num 500)
      (push "D" ret)
      (cl-decf num 500)
      (cl-loop with count = (/ num 100)
               repeat count
               do
               (progn
                 (push "C" ret)
                 (cl-decf num 100))))
    (when (>= num 400)
      (push "CD" ret)
      (cl-decf num 400))
    (when (>= num 100)
      (cl-loop with count = (/ num 100)
               repeat count
               do
               (progn
                 (push "C" ret)
                 (cl-decf num 100))))
    (when (>= num 90)
      (push "XC" ret)
      (cl-decf num 90))
    (when (>= num 50)
      (push "L" ret)
      (cl-decf num 50))
    (when (>= num 40)
      (push "XL" ret)
      (cl-decf num 40))
    (when (>= num 10)
      (cl-loop with count = (/ num 10)
               repeat count
               do
               (progn
                 (push "X" ret)
                 (cl-decf num 10))))
    (when (>= num 9)
      (push "IX" ret)
      (cl-decf num 9))
    (when (>= num 5)
      (push "V" ret)
      (cl-decf num 5))
    (when (>= num 4)
      (push "IV" ret)
      (cl-decf num 4))
    (cl-loop with count = num
             repeat count
             do
             (progn
               (push "I" ret)
               (cl-decf num)))
    (apply #'concat (reverse ret))))

(provide 'roman-numerals)
;;; roman-numerals.el ends here
