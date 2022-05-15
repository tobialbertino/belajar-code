package app

import data.Person

fun main() {
    val tobi = Person()
    tobi.firstName = "M"
    tobi.middleName = "Khoiru"
    tobi.lastName = "Tobi"

    tobi.sayHello("Budi")
    tobi.run()
    val fullName = tobi.getFullName()
    println(fullName)
}