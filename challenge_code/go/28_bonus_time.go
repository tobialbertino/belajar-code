// https://www.codewars.com/kata/56f6ad906b88de513f000d96/train/go

package kata

import "fmt"

func BonusTime(salary int, bonus bool) string {
	var getSalary int = salary
	if bonus {
		getSalary *= 10
	}

	return fmt.Sprintf("%s%d", "\u00A3", getSalary)
}
