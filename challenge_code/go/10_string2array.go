// https://www.codewars.com/kata/57e76bc428d6fbc2d500036d/train/go

package kata

import "strings"

func StringToArray(str string) (res []string) {
	// res = strings.Split(str, " ")
	res = strings.Fields(str)
	return
}
