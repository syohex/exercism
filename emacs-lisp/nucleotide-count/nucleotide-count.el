;;; nucleotide-count.el --- nucleotide-count Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun nucleotide-count (str)
  (let ((hash (make-hash-table)))
    (cl-loop for c in '(?A ?C ?G ?T)
             do
             (puthash c 0 hash))
    (cl-loop for c across str
             do
             (puthash c (1+ (gethash c hash)) hash))
    (cl-loop for key being the hash-keys in hash using (hash-value count)
             collect (cons key count))))

(provide 'nucleotide-count)
;;; nucleotide-count.el ends here
