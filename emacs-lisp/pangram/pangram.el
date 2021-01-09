;;; pangram.el --- Pangram (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun is-pangram (str)
  (let ((hash (make-hash-table)))
    (cl-loop for c across (downcase str)
             do
             (puthash c t hash))
    (cl-loop for i from ?a to ?z
             always (gethash i hash))))

(provide 'pangram)

;;; pangram.el ends here
