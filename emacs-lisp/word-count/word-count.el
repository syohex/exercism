;;; word-count.el --- word-count Exercise (exercism)

;;; Commentary:

;;; Code:

(defun word-count (sentence)
  (with-temp-buffer
    (insert sentence)
    (goto-char (point-min))
    (let ((hash (make-hash-table :test #'equal)))
      (while (re-search-forward "[a-zA-Z0-9]+" nil t)
        (let* ((word (downcase (match-string-no-properties 0)))
               (val (gethash word hash)))
          (if val
              (puthash word (1+ val) hash)
            (puthash word 1 hash))))
      (cl-loop for word being the hash-keys in hash using (hash-value count)
               collect (cons word count)))))

(provide 'word-count)
;;; word-count.el ends here
