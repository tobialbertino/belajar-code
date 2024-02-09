// https://www.codewars.com/kata/5bb904724c47249b10000131

package kata

import (
	"strconv"
	"strings"
)

func Points(games []string) (points int) {
	for _, str := range games {
		if str[0] > str[2] {
			points += 3
		}

		if str[0] == str[2] {
			points += 1
		}
	}
	return
}

func Points0(games []string) int {
	total := 0

	for _, v := range games {
		i1, i2 := ParseGames(v)

		if i1 > i2 {
			total += 3
		}

		if i1 == i2 {
			total += 1
		}
	}

	return total
}

func ParseGames(str string) (int, int) {
	s := strings.Split(str, ":")
	if len(s) == 2 {
		i1, _ := strconv.Atoi(s[0])
		i2, _ := strconv.Atoi(s[1])

		return i1, i2
	}

	return 0, 0
}
