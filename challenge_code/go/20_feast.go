// https://www.codewars.com/kata/5aa736a455f906981800360d/train/go

package kata

func Feast(beast string, dish string) bool {
	var lenBeast = len(beast)
	var lenDish = len(dish)

	if (beast[0] == dish[0]) &&
		beast[lenBeast-1] == dish[lenDish-1] {
		return true
	}

	return false
}
