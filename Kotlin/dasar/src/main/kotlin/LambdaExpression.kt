fun toUpper(value: String): String = value.uppercase()

fun main() {

    val contohLambda: (String, String) -> String = { firstName: String, lastName: String ->
        val result = "$firstName $lastName"
        result
    }

    val result = contohLambda("Eko", "Kurniawan")
    println(result)

    val sayHello: (String) -> String = {
        "Hello $it"
    }

    println(sayHello("Eko"))

    val toUpperCaseTest: (String) -> String = ::toUpper
    println(toUpperCaseTest("Eko Kurniawan"))
}