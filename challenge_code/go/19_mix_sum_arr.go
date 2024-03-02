// https://www.codewars.com/kata/57eaeb9578748ff92a000009/go

package kata

import "strconv"

func SumMix(arr []any) (sum int) {
	for _, v := range arr {
		switch v.(type) {
		case int:
			sum += v.(int)
		case string:
			conv, err := strconv.Atoi(v.(string))
			if err != nil {
				return 0
			}
			sum += conv
		}
	}
	return sum
}
