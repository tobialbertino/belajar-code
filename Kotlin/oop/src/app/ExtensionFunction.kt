package app

import data.Student
import data.sayHello
import data.uppername

fun main() {
    val student: Student? = Student("Tobi", 15)
    student.sayHello("Budi")
    println(student?.uppername)
}
