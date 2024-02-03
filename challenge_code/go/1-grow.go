// https://www.codewars.com/kata/57f780909f7e8e3183000078/train/go

package kata

func Grow(arr []int) int {
	var i int = 1

	for _, v := range arr {
		i *= v
	}

	return i
}
