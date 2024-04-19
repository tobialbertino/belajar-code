// https://www.codewars.com/kata/568dcc3c7f12767a62000038/go

package kata

func SetAlarm(employed, vacation bool) bool {
	if employed && !vacation {
		return true
	}
	return false
}
