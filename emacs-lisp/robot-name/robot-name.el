;;; robot-name.el --- Robot Name (exercism)

;;; Commentary:
;;
;; Build a robot with a name like AA000, that can be reset
;; to a new name. Instructions are in README.md
;;

;;; Code:

(defvar robot-hash (make-hash-table))

(defun robot-random-name ()
  (let ((chars "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
        (nums "0123456789"))
    (string
     (aref chars (mod (random) (length chars)))
     (aref chars (mod (random) (length chars)))
     (aref nums (mod (random) (length nums)))
     (aref nums (mod (random) (length nums)))
     (aref nums (mod (random) (length nums))))))

(defun build-robot ()
  (let ((id nil)
        found)
    (while (not found)
      (let ((r (random)))
        (unless (gethash r robot-hash)
          (setq id r found t))))
    (puthash id (robot-random-name) robot-hash)))

(defun robot-name (robot)
  (or (gethash robot robot-hash)
      (let ((name (robot-random-name)))
        (puthash robot name robot-hash)
        name)))

(defun reset-robot (robot)
  (remhash robot robot-hash))

(provide 'robot-name)
;;; robot-name.el ends here
