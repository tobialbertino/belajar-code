package app

import data.Company

fun main() {
    val company1 = Company("Tobi")
    val company2 = Company("Tobi")

    println(company1 == company2) // FALSE
    println(company1 == company1)
    println(company2 == company2)
}