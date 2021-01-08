;;; atbash-cipher.el --- Atbash-Cipher (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun encode (plaintext)
  "Encode PLAINTEXT to atbash-cipher encoding."
  (cl-loop for c across (downcase plaintext)

           when (<= ?a c ?z)
           collect (+ (- ?z c) ?a) into chars

           when (<= ?0 c ?9)
           collect c into chars

           finally
           return
           (with-temp-buffer
             (insert (apply #'string chars))
             (goto-char (point-min))
             (while (re-search-forward "[a-z0-9]\\{5\\}" nil t)
               (unless (eobp)
                 (replace-match (concat (match-string 0) " "))))
             (buffer-string))))

(provide 'atbash-cipher)
;;; atbash-cipher.el ends here
