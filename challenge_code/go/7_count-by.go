// https://www.codewars.com/kata/5513795bd3fafb56c200049e/train/go

package kata

func CountBy(x, n int) (res []int) {

	for i := 1; i <= n; i++ {
		res = append(res, i*x)
	}

	return res
}
