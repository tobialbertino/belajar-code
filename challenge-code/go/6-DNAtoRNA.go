// https://www.codewars.com/kata/5556282156230d0e5e000089/rust

package kata

import "strings"

func DNAtoRNA(dna string) string {
	// your code here
	return strings.ReplaceAll(dna, "T", "U")
}
