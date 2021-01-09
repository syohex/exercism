;;; acronym.el --- Acronym (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun acronym (str)
  (with-temp-buffer
    (insert str)
    (goto-char (point-min))
    (let (acc)
      (while (re-search-forward "\\([a-zA-Z]\\)[a-zA-Z]*" nil t)
        (push (upcase (match-string-no-properties 1)) acc))
      (apply #'concat (reverse acc)))))

(provide 'acronym)

;;; acronym.el ends here
