;;; luhn.el --- Luhn exercise (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun luhn--to-number (str)
  (if (not (string-match-p "[0-9]+" str))
      (error "%s is not string" str)
    (string-to-number str)))

(defun luhn-p (str)
  (with-temp-buffer
    (insert (reverse str))
    (goto-char (point-min))
    (save-excursion
      (while (re-search-forward "\\s-+" nil t)
        (replace-match "")))
    (when (string-match-p "[0-9]\\{2\\}" (buffer-string))
      (let ((sum 0)
            (even nil))
        (while (re-search-forward "\\(.\\)" nil t)
          (let ((num (luhn--to-number (match-string-no-properties 1))))
            (if (not even)
                (progn
                  (cl-incf sum num))
              (let ((double (* 2 num)))
                (cl-incf sum (if (> double 9) (- double 9) double))))
            (setq even (not even))))
        (zerop (mod sum 10))))))

(provide 'luhn)

;;; luhn.el ends here
