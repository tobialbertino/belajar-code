package app

import data.Smartphone

fun main() {
    val smartphone = Smartphone("S20", "Android")

    println(smartphone.toString())
    println(smartphone.hashCode())
}