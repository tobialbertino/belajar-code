package app

import data.Boss

fun main() {
    val boss1 = Boss("Tobi")

    val employee1 = boss1.Employee("Budi")
    val employee2 = boss1.Employee("Joko")

    val boss2 = Boss("Eko")

    val employee3 = boss1.Employee("Budi")
    val employee4 = boss1.Employee("Joko")

    employee1.hi()
    employee2.hi()
    employee3.hi()
    employee4.hi()

}