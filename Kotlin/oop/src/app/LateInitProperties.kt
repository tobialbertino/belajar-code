package app

import data.Television

fun main() {
    val tv = Television()

    // println(tv.brand) // ERROR
    tv.initTelevision("Samsung")
    println(tv.brand)
}