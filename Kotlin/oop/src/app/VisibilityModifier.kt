package app

import data.SuperTeacher
import data.Teacher

fun main() {
    val teacher = Teacher("Tobi")
    println(teacher.name)
    // teacher.teach() // ERROR

    val superTeacher = SuperTeacher("Eko")
    superTeacher.test()
}