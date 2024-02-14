// https://www.codewars.com/kata/55cbd4ba903825f7970000f5/train/go

package kata

func GetGrade(a, b, c int) rune {
	switch score := (a + b + c) / 3; {
	case score < 60:
		return 'F'
	case score < 70:
		return 'D'
	case score < 80:
		return 'C'
	case score < 90:
		return 'B'
	default:
		return 'A'
	}
}
