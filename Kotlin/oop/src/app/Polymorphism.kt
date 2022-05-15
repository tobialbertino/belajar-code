package app

import data.Employee
import data.Manager
import data.VicePresident

fun main() {
    var employee: Employee = Employee("Tobi")
    employee.sayHello("Budi")

    employee = Manager("Tobi")
    employee.sayHello("Budi")

    employee = VicePresident("Tobi")
    employee.sayHello("Budi")
}