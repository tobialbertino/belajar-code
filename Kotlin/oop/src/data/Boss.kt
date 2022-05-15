package data

class Boss(val name: String) {

    inner class Employee(val name: String) {

        fun hi() = println("Hi, My name is ${this.name}, and my boss name is ${this@Boss.name}")
    }
}