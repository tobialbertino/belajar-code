package app

import data.Person

fun main() {
    val mutableSet: MutableSet<Person> = mutableSetOf()
    mutableSet.add(Person("M"))
    mutableSet.add(Person("Khoiru"))
    mutableSet.add(Person("Khoiru"))
    mutableSet.add(Person("Tobi"))

    for (person in mutableSet) {
        println(person)
    }
}