// This is a "stub" file.  It's a little start on your solution.
// It's not a complete solution though; you have to write some code.

// Package acronym should have a package comment that summarizes what it's about.
// https://golang.org/doc/effective_go.html#commentary
package acronym

import (
	"regexp"
	"unicode"
)

var re = regexp.MustCompile(`[a-zA-Z][a-zA-Z']*`)

// Abbreviate should have a comment documenting it.
func Abbreviate(s string) string {
	matches := re.FindAllString(s, -1)

	ret := ""
	for _, match := range matches {
		r := unicode.ToUpper(rune(match[0]))
		ret += string(r)
	}

	return ret
}
