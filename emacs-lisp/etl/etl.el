;;; etl.el --- etl Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun etl (h)
  (let ((ret (make-hash-table :test #'equal)))
    (cl-loop for score being the hash-keys in h using (hash-value lst)
             if (and (integerp score) (>= score 0))
             do
             (cl-loop for e in lst
                      if (stringp e)
                      do
                      (puthash (downcase e) score ret)
                      else
                      do
                      (error "invalid character: %s" e))
             else
             do
             (error "invalid score: %s" score))
    ret))

(provide 'etl)
;;; etl.el ends here
