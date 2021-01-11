;;; bob.el --- Bob exercise (exercism)

;;; Commentary:

;;; Code:

(require 'subr-x)

(defun response-for--all-upcase-p (str)
  (when (string-match-p "[a-zA-Z]" str)
    (cl-loop for c across str
             when (or (<= ?a c ?z) (<= ?A c ?Z))
             always (<= ?A c ?Z))))

(defun response-for--say-nothing-p (str)
  (string-match-p "\\`[ \t\n\r]*\\'" str))

(defun response-for--question-p (str)
  (string-match-p "?\\s-*\\'" str))

(defun response-for (str)
  (cond ((and (response-for--question-p str)
              (response-for--all-upcase-p str)) "Calm down, I know what I'm doing!")
        ((response-for--say-nothing-p str) "Fine. Be that way!")
        ((response-for--all-upcase-p str) "Whoa, chill out!")
        ((response-for--question-p str) "Sure.")
        (t "Whatever.")))

(provide 'bob)
;;; bob.el ends here
