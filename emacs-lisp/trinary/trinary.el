;;; trinary.el --- Trinary (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun trinary-to-decimal (str)
  (if (not (string-match-p "\\`[0-9]+\\'" str))
      0
    (cl-loop for c across (reverse str)
             for i = 0 then (1+ i)
             sum (+ (* (- c ?0) (expt 3 i))))))

(provide 'trinary)

;;; trinary.el ends here
