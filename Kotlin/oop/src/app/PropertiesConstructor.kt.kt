package app

import data.User

fun main() {
    val user1 = User("Tobi", "secret")
    val user2 = User("Albert", "secret")

    user1.username = "Budi"
    user1.password = "SuperSecret"

    println(user1.username)
    println(user1.password)

    println(user2.username)
    println(user2.password)
}