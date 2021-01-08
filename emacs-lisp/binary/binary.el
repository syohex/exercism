;;; binary.el --- Binary exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun to-decimal (str)
  (if (not (string-match-p "^[01]+$" str))
      0
    (let ((nums (cl-loop for n in (split-string str "" t)
                         collect (string-to-number n)))
          (sum 0))
      (cl-loop with sum = 0
               for num in nums
               do
               (setq sum (+ (* 2 sum) num))
               finally
               return sum))))

(provide 'binary)
;;; binary.el ends here
