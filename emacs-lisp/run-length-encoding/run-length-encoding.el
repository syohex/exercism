;;; run-length-encoding.el --- run-length-encoding Exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun run-length-encode (str)
  (with-temp-buffer
    (insert str)
    (goto-char (point-min))
    (let ((case-fold-search nil)
          ret)
      (while (re-search-forward "\\([a-zA-Z ]\\)\\1\\{0,\\}" nil t)
        (let* ((chars (match-string-no-properties 0))
               (len (length chars)))
          (if (= len 1)
              (push chars ret)
            (push (format "%d%s" len (match-string-no-properties 1)) ret))))
      (apply #'concat (reverse ret)))))

(defun run-length-decode (str)
  (with-temp-buffer
    (insert str)
    (goto-char (point-min))
    (let ((case-fold-search nil)
          ret)
      (while (re-search-forward "\\([0-9]+\\)?\\([a-zA-Z ]\\)" nil t)
        (let ((num (match-string-no-properties 1))
              (char (match-string-no-properties 2)))
          (if (not num)
              (push char ret)
            (push (make-string (string-to-number num) (string-to-char char)) ret))))
      (apply #'concat (reverse ret)))))

(provide 'run-length-encoding)
;;; run-length-encoding.el ends here
