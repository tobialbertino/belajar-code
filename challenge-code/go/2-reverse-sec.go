// https://www.codewars.com/kata/5a00e05cc374cb34d100000d

package kata

func ReverseSeq(n int) []int {
	var res []int

	for i := n; i > 0; i-- {
		res = append(res, i)
	}
	return res
}
