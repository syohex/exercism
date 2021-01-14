;;; phone-number.el --- phone-number Exercise (exercism)

;;; Commentary:

;;; Code:

(defun numbers--strip-non-number (str)
  (with-temp-buffer
    (insert str)
    (goto-char (point-min))
    (while (re-search-forward "[^0-9]+" nil t)
      (replace-match ""))
    (buffer-string)))

(defun numbers (str)
  (let ((num-str (numbers--strip-non-number str)))
    (if (string-match "\\`1?\\([0-9]\\{10\\}\\)\\'" num-str)
        (match-string 1 num-str)
      "0000000000")))

(defun area-code (str)
  (if (not (string-match "\\`1?\\([0-9]\\{3\\}\\)[0-9]\\{7\\}\\'" str))
      (error "invalid input %s" str)
    (match-string 1 str)))

(defun pprint (str)
  (if (not (string-match "\\`1?\\([0-9]\\{3\\}\\)\\([0-9]\\{3\\}\\)\\([0-9]\\{4\\}\\)\\'" str))
      (error "invalid input %s" str)
    (format "(%s) %s-%s"
            (match-string 1 str) (match-string 2 str) (match-string 3 str))))

(provide 'phone-number)
;;; phone-number.el ends here
