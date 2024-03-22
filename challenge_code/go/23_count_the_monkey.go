// https://www.codewars.com/kata/56f69d9f9400f508fb000ba7/train/go

package kata

func monkeyCount(n int) (res []int) {
	for i := 1; i <= n; i++ {
		res = append(res, i)
	}
	return
}
