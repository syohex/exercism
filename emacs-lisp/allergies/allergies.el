;;; allergies.el --- Allergies Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defvar allergen-alist
  '(("eggs" . 1)
    ("peanuts" . 2)
    ("shellfish" . 4)
    ("strawberries" . 8)
    ("tomatoes" . 16)
    ("chocolate" . 32)
    ("pollen" . 64)
    ("cats" . 128)))

(defun allergen-list (n)
  (cl-loop for (allergen . val) in allergen-alist
           unless (zerop (logand n val))
           collect allergen))

(defun allergic-to-p (n allergen)
  (member allergen (allergen-list n)))

(provide 'allergies)
;;; allergies.el ends here
