package app

import data.Person

fun main() {
    val set: Set<Person> = setOf(
        Person("M"),
        Person("Khoiru"),
        Person("Tobi"),
        Person("Tobi")
    )

    println(set.size)
    println(set.contains(Person("Tobi")))

    for (person in set) {
        println(person)
    }
}