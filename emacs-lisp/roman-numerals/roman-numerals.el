;;; roman-numerals.el --- roman-numerals Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defvar roman-table
  '((100 "M" "D" "C")
    (10 "C" "L" "X")
    (1 "X" "V" "I")))

(defun to-roman (num)
  (let (ret)
    (when (>= num 1000)
      (cl-loop with count = (/ num 1000)
               repeat count
               do
               (progn
                 (push "M" ret)
                 (cl-decf num 1000))))
    (cl-loop for v in roman-table
             for base = (nth 0 v)
             for upper = (nth 1 v)
             for middle = (nth 2 v)
             for lower = (nth 3 v)
             do
             (progn
               (when (>= num (* 9 base))
                 (push (concat lower upper) ret)
                 (cl-decf num (* 9 base)))
               (when (>= num (* 5 base))
                 (push middle ret)
                 (cl-decf num (* 5 base)))
               (when (>= num (* 4 base))
                 (push (concat lower middle) ret)
                 (cl-decf num (* 4 base)))
               (cl-loop with count = (/ num base)
                        repeat count
                        do
                        (progn
                          (push lower ret)
                          (cl-decf num base)))))
    (apply #'concat (reverse ret))))

(provide 'roman-numerals)
;;; roman-numerals.el ends here
