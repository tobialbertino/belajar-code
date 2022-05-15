package app

import data.Game
import data.Login
import data.MinMax

fun minMax(value1: Int, value2: Int): MinMax {
    return when {
        value1 > value2 -> MinMax(value2, value1)
        else -> MinMax(value1, value2)
    }
}

fun login(login: Login, callback: (Login) -> Boolean): Boolean {
    return callback(login)
}

fun main() {
    val game = Game("GI", 1_000)
    val (name, price) = game
    println(name)
    println(price)

    val (min, max) = minMax(1000, 10)
    println(min)
    println(max)

    val login = Login("Tobi", "rahasia")
    // login(login) {login -> login.username == "Tobi" == login.password == "rahasia"}
    login(login) { (username, password) ->
        username == "Tobi" && password == "rahasia"
    }
}