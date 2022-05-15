package app

import exception.ValidationException

fun validateAndSayHello(name: String) {
    if (name.isBlank()) {
        throw ValidationException("Name is blank")
    }
    println("Hello $name")
}

fun main() {
    try {
        validateAndSayHello("Tobi")
        validateAndSayHello("") // terjadi error, masuk catch
        println("Program")
    } catch (error: ValidationException) {
        println("Terjadi error: ${error.message}")
    } catch (error: Throwable) {
        println("Terjadi error: ${error.message}")
    } finally {
        println("Program selesai")
    }
}