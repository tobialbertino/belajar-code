const val APPLICATION = "Belajar Kotlin"
const val VERSION = "1.0.0"

fun main() {
    val firstName = "Tobi"
    val age = 30

    println(firstName)
    println(age)

    var name: String? = null
    name = "Tobi"
    println(name)
    println(name?.length)

    println("$APPLICATION : $VERSION")

}