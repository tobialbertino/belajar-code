package data

class Person {
    var firstName: String = ""
    var middleName: String? = null
    var lastName: String = ""

    fun sayHello(name: String) {
        println("Hello $name, My name is ${this.firstName}")
    }

    fun sayHello(firstName: String, lastName: String) {
        println("Hello $firstName $lastName, My name is ${this.firstName}")
    }

    fun run() {
        println("I'm run")
    }

    fun getFullName(): String {
        return "$firstName $middleName $lastName"
    }
}