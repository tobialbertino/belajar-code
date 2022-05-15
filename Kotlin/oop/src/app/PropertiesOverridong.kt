package app

import data.Rectangle
import data.Shape
import data.Triangle

fun main() {
    val shape = Shape()
    println(shape.corner)

    val shape1 = Rectangle()
    println(shape1.corner)

    val shape2 = Triangle()
    println(shape2.corner)

}