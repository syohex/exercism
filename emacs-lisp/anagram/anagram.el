;;; anagram.el --- Anagram (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)
(require 'seq)

(defun anagrams-for (str words)
  (cl-loop with sorted = (cl-sort (downcase (seq-copy str)) #'<)
           for word in words
           when (and (not (string= str word))
                     (string= sorted (cl-sort (downcase (seq-copy word)) #'<)))
           collect word))

(provide 'anagram)
;;; anagram.el ends here
