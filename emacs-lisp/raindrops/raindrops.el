;;; raindrops.el --- Raindrops (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)
(require 'subr-x)

(defun convert (n)
  "Convert integer N to its raindrops string."
  (let ((ret ""))
    (when (zerop (mod n 3))
      (setq ret (concat ret "Pling")))
    (when (zerop (mod n 5))
      (setq ret (concat ret "Plang")))
    (when (zerop (mod n 7))
      (setq ret (concat ret "Plong")))
    (if (string-empty-p ret)
        (number-to-string n)
      ret)))

(provide 'raindrops)
;;; raindrops.el ends here
