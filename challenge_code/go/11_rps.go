// https://www.codewars.com/kata/5672a98bdbdd995fad00000f

package kata

import "strings"

func Rps(p1, p2 string) string {
	rock := "rock"
	paper := "paper"
	scissor := "scissors"
	Player1Won := "Player 1 won!"
	Player2Won := "Player 2 won!"

	if strings.EqualFold(p1, p2) {
		return "Draw!"
	}

	m := map[string]string{
		rock:    scissor,
		paper:   rock,
		scissor: paper,
	}

	if m[p1] == p2 {
		return Player1Won
	} else {
		return Player2Won
	}

}
