package app

import data.Car

fun main() {
    val avanza = Car(paramBrand = "Toyota")
    avanza.year = 2018

    val almaz = Car(paramBrand = "Wuling", paramName = "almaz")

    println(avanza.brand)
    println(avanza.year)
    println(almaz.brand)
    println(almaz.year)
}