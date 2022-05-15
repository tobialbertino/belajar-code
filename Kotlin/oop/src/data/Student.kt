package data

class Student(val name: String, val age: Int)

fun Student?.sayHello(name: String) {
    if (this != null) {
        println("Hello $name, My name is ${this.name}, and my age is ${this.age}")
    }
}

val Student.uppername: String
    get() = this.name.uppercase()
