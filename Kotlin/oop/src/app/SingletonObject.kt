package app

import data.Application
import data.Utilities

fun main() {
    Utilities.name = "Di ubah"
    println(Utilities.name)
    println(Utilities.toUpper("tobi"))
    a()
    b()

    println(Application.Companion.toUpper("test uppercase"))
    println(Application.toUpper("test uppercase"))

}

fun a(){
    println(Utilities.name)
}

fun b(){
    println(Utilities.name)
}