package app

import data.Manager
import data.VicePresident

fun main() {
    val manager = Manager("Tobi")
    manager.sayHello("Budi")

    val vicePresident = VicePresident("Budi")
    vicePresident.sayHello("Tobi")

}