package app

import data.Rectangle

fun main() {
    val rectangle = Rectangle()
    println("corner rectangle ${rectangle.corner}, parrent corner ${rectangle.parentCorner}")

    rectangle.printName()
}