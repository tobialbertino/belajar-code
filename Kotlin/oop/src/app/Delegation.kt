package app

import data.MyBase
import data.MyBaseDelegation

fun main() {
    val base = MyBase()
    base.sayHello("Tobi")

    val baseDelegate = MyBaseDelegation(base)
    baseDelegate.sayHello("Joko")
    baseDelegate.sayGoodBye("Budi")


}