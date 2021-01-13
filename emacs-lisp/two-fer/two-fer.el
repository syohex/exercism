;;; two-fer.el --- Two-fer Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(cl-defun two-fer (&optional (name "you"))
  (format "One for %s, one for me." name))

(provide 'two-fer)
;;; two-fer.el ends here
