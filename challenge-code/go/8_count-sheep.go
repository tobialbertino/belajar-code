// https://www.codewars.com/kata/5b077ebdaf15be5c7f000077

package kata

import (
	"fmt"
	"strings"
)

func countSheep(num int) string {
	var res strings.Builder

	for i := 1; i <= num; i++ {
		fmt.Fprintf(&res, "%d sheep...", i)
	}

	return res.String()
}
